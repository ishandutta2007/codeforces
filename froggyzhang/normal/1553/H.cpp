#include<bits/stdc++.h>
using namespace std;
#define N 533333
const int inf=0x3f3f3f3f;
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
int n,m,vis[N],a[N];
vector<int> mx[N<<2],mn[N<<2],ans[N<<2];
#define ls u<<1
#define rs u<<1|1
void Solve(int u,int L,int R){
	if(L==R){
		ans[u]=vector<int>(1,inf);
		if(vis[L])mx[u]=mn[u]=vector<int>(1,0);
		else mx[u]=vector<int>(1,-inf),mn[u]=vector<int>(1,inf);
		return;
	}
	int mid=(L+R)>>1;
	Solve(ls,L,mid),Solve(rs,mid+1,R);
	int len=R-L+1;
	mx[u].resize(len);
	mn[u].resize(len);
	ans[u].resize(len);
	for(int i=0;i<len>>1;++i){
		mx[u][i]=max(mx[ls][i],mx[rs][i]+(len>>1));
		mn[u][i]=min(mn[ls][i],mn[rs][i]+(len>>1));
		ans[u][i]=min(min(ans[ls][i],ans[rs][i]),mn[rs][i]+(len>>1)-mx[ls][i]);
	}
	for(int i=0;i<len>>1;++i){
		mx[u][i+(len>>1)]=max(mx[ls][i]+(len>>1),mx[rs][i]);
		mn[u][i+(len>>1)]=min(mn[ls][i]+(len>>1),mn[rs][i]);
		ans[u][i+(len>>1)]=min(min(ans[ls][i],ans[rs][i]),mn[ls][i]+(len>>1)-mx[rs][i]);
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		vis[a[i]]=1;
	}
	Solve(1,0,(1<<m)-1);
	for(int i=0;i<(1<<m);++i){
		printf("%d ",ans[1][i]);
	}
	return 0;
}