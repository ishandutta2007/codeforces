#include<bits/stdc++.h>
using namespace std;
#define N 1505
const int mod=1e9+9;
const int base=1145141;
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
int n,m,a[N][N],b[N][N],vis[N];
bitset<N> g[N],now;
vector<int> ans;
int ha[N],hb[N];
inline int Hash(int *a){
	int x=0;
	for(int i=1;i<=m;++i){
		x=(1LL*x*base+a[i])%mod;
	}
	return x;
}
bool check(){
	static int p[N],vis[N];
	for(int i=1;i<=n;++i){
		ha[i]=Hash(a[i]);
		hb[i]=Hash(b[i]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(vis[j])continue;
			if(hb[i]==ha[j]){
				p[i]=j;break;
			}
		}
		if(!p[i])return false;
		vis[p[i]]=1;
	}
	for(int i=1;i<n;++i){
		if(!now[i]&&p[i]>p[i+1])return false;
	}
	return true;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			b[i][j]=read();
		}
	}
	for(int j=1;j<=m;++j){
		for(int i=1;i<=n;++i){
			if(i==n||b[i][j]>b[i+1][j])g[j][i]=1;
		}
	}
	now[n]=1;
	while(true){
		int p=0;
		for(int j=1;j<=m;++j){
			if(vis[j])continue;
			if((now|g[j])==now){
				p=j;break;
			}
		}
		if(!p)break;
		ans.push_back(p);
		vis[p]=1;
		for(int i=1;i<n;++i){
			if(b[i][p]<b[i+1][p])now[i]=1;
		}
	}
	if(!check()){
		return !printf("-1\n");
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d ",x);
	}
	return 0;
}