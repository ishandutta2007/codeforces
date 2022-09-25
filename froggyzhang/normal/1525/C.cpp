#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,m,an,bn,X[N],ans[N];
char s[N];
struct Robot{
	int id,x,t;
	Robot(int _id=0,int _x=0,int _t=0){id=_id,x=_x,t=_t;}
	friend bool operator < (const Robot &a,const Robot &b){
		return a.x<b.x;
	}	
}a[N],b[N];
void Solve(Robot *a,int n){
	static Robot st[N];
	static int top;
	sort(a+1,a+n+1);
	top=0;
	for(int i=1;i<=n;++i){
		if(a[i].t==1){
			st[++top]=a[i];
		}
		else{
			if(top){
				if(st[top].t==1){
					ans[st[top].id]=ans[a[i].id]=(a[i].x-st[top].x)/2;
				}
				else{
					ans[st[top].id]=ans[a[i].id]=(a[i].x+st[top].x)/2;
				}
				--top;
			}
			else{
				st[++top]=a[i];
			}
		}
	}
	while(top>1){
		if(st[top-1].t==1){
			ans[st[top].id]=ans[st[top-1].id]=(2*m-st[top].x-st[top-1].x)/2;	
		}
		else{
			ans[st[top].id]=ans[st[top-1].id]=(st[top-1].x+2*m-st[top].x)/2;
		}
		top-=2;
	}
}
void sxymd(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		X[i]=read();
		ans[i]=-1;
	}
	an=bn=0;
	for(int i=1;i<=n;++i){
		cin>>s[i];
	}
	for(int i=1;i<=n;++i){
		if(X[i]&1)a[++an]=Robot(i,X[i],s[i]=='L'?-1:1);
		else b[++bn]=Robot(i,X[i],s[i]=='L'?-1:1);
	}
	Solve(a,an),Solve(b,bn);
	for(int i=1;i<=n;++i){
		printf("%d ",ans[i]);
	}
	printf("\n");
}
int main(){
	T=read();
	while(T--){
		sxymd();	
	}
	return 0;
}