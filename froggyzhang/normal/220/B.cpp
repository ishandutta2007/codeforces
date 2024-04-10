#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000100
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
int n,m,a[N],ans[N];
vector<int> p[N];
vector<pair<int,int> > q[N];
struct BIT{
	int b[N];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void Add(int x,int d){
		while(x<=n){
			b[x]+=d;
			x+=lowbit(x);
		}
	}
	inline int Ask(int x){
		int ans=0;
		while(x){
			ans+=b[x];
			x-=lowbit(x);
		}
		return ans;
	}
}B;
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		p[i].push_back(0);
	}
	for(int i=1;i<=m;++i){
		int l=read(),r=read();
		q[r].emplace_back(l,i);
	}
	for(int i=1;i<=n;++i){
		if(a[i]<=n){
			if(p[a[i]].size()>a[i]){
				B.Add(p[a[i]][p[a[i]].size()-a[i]-1]+1,-1);
				B.Add(p[a[i]][p[a[i]].size()-a[i]]+1,1);
			}
			p[a[i]].push_back(i);
			if(p[a[i]].size()>a[i]){
				B.Add(p[a[i]][p[a[i]].size()-a[i]-1]+1,1);
				B.Add(p[a[i]][p[a[i]].size()-a[i]]+1,-1);
			}
		}
		for(auto [l,id]:q[i]){
			ans[id]=B.Ask(l);
		}
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}