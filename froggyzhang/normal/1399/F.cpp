#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
#define N 6030
inline int read(){
	int x=0,f=1;
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
int n,T,dp[N][N],len,b[N];
vector<int> lef[N];
set<pair<int,int> > s;
struct Seg{
	int l,r;
	bool operator <(const Seg b)const{
		return r==b.r?l>b.l:r<b.r;
	}
}a[N];
int dfs(int l,int r){
	if(l>r)return 0;
	if(~dp[l][r])return dp[l][r];
	int ok=s.count(make_pair(l,r));
	int ans=dfs(l,r-1)+ok;
	for(auto pos:lef[r]){
		if(pos<=l)break;
		ans=max(ans,dfs(l,pos-1)+dfs(pos,r)+ok);
	}
	return dp[l][r]=ans;
}
void Solve(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i].l=read(),a[i].r=read();
		b[++len]=a[i].l,b[++len]=a[i].r;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+len+1);
	len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=len;++i)lef[i].clear();
	s.clear();
	for(int i=1;i<=n;++i){
		a[i].l=lower_bound(b+1,b+len+1,a[i].l)-b;
		a[i].r=lower_bound(b+1,b+len+1,a[i].r)-b;
		lef[a[i].r].push_back(a[i].l);
		s.insert(make_pair(a[i].l,a[i].r));
	}
	for(int i=1;i<=len;++i)for(int j=1;j<=len;++j)dp[i][j]=-1;
	printf("%d\n",dfs(1,len));
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}