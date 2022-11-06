#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
int f[N],a[N],b[N];
vector<int>p[N];
void dfs(int x){
	for(auto&i:p[x])if(i!=f[x]){
		f[i]=x;dfs(i);
		if(a[i]>0)a[x]+=a[i];
	}
}
void dp(int x){
	for(auto&i:p[x])if(i!=f[x]){
		b[i]=a[x]+b[x];
		if(a[i]>0)b[i]-=a[i];
		b[i]=max(b[i],0);dp(i);
	}
}
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(!a[i])a[i]=-1;
	}
	rep(i,2,n){int x,y;
		scanf("%d%d",&x,&y);
		p[x].push_back(y);
		p[y].push_back(x);
	}
	dfs(1);dp(1);
	rep(i,1,n)printf("%d%c",a[i]+b[i],i==n?'\n':' ');
}