#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1e5+11;
int a[N],b[N],n,vis[N];
int st[N],en[N],siz[N],wt;
int sta[N],sop;
void find(int x){
	st[++wt]=sop+1;
	int tot=0;
	while(!vis[x]){
		tot++;
		sta[++sop]=x;
		vis[x]=1;
		x=a[x];
	}
	en[wt]=sop,siz[wt]=tot;
}
int main(){
	n=rd();
	rep(i,1,n)a[i]=b[i]=rd();
	sort(b+1,b+n+1);
	rep(i,1,n)a[i]=lower_bound(b+1,b+n+1,a[i])-b;
	rep(i,1,n)if(!vis[i])find(i);
	printf("%d\n",wt);
	rep(i,1,wt){
		printf("%d ",siz[i]);
		sort(sta+st[i],sta+en[i]+1);
		rep(j,st[i],en[i])
			printf("%d%c",sta[j]," \n"[j==en[i]]);
	}
}