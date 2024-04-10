#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; 
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=1e5+5;
int n,c,d;
char op[10];
struct node{
	int b,p;
}a[N],b[N];
int f[N];
inline void add(int x,int y){
	for(;x<=N-3;x+=x&-x) f[x]=max(f[x],y);
}
inline int query(int x){
	int res=0;
	for(;x;x-=x&-x) res=max(res,f[x]);
	return res;
}
int main(){
	n=read(),c=read(),d=read();
	int cnt1=0,cnt2=0,res1=0,res2=0;
	int ans=0;
	for(int i=1;i<=n;i++) {
		int x=read(),y=read();
		scanf("%s",op);
		if(op[0]=='C') {
			if(y<=c) {
				a[++cnt1]={x,y};
				res1=max(res1,x);
			}
		}else {
			if(y<=d) {
				b[++cnt2]={x,y};
				res2=max(res2,x);
			}
		}
	}
	if(res1&&res2) ans=res1+res2;
	for(int i=1;i<=cnt1;i++){
		int t=query(c-a[i].p);
		if(t) ans=max(ans,t+a[i].b);
		add(a[i].p,a[i].b);
	}
	memset(f,0,sizeof(f));
	for(int i=1;i<=cnt2;i++){
		int t=query(d-b[i].p);
		if(t) ans=max(ans,t+b[i].b);
		add(b[i].p,b[i].b);
	}
	cout<<ans;
    return 0;
}