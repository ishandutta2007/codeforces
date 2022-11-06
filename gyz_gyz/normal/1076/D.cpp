#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 3000000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,m,k,s,t,x,y,dl[N];ll z,d[N];bool v[N];
struct pr{int t;ll w;int id;};
vector<pr>p[N];
void dfs(int x){
	for(auto i:p[x])if(!v[i.t]&&d[x]+i.w==d[i.t]){
		printf("%d ",i.id);k--;v[i.t]=1;
		if(!k)exit(0);dfs(i.t);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);k=min(k,n-1);
	rep(i,1,m){
		scanf("%d%d%I64d",&x,&y,&z);
		p[x].pb({y,z,i});p[y].pb({x,z,i});
	}
	rep(i,2,n)d[i]=Inf;
	dl[1]=s=t=1;v[1]=1;
	for(;s<=t;v[dl[s++]]=0)
		for(auto i:p[dl[s]])
			if(d[dl[s]]+i.w<d[i.t]){
				d[i.t]=d[dl[s]]+i.w;
				if(!v[i.t]){
					dl[++t]=i.t;v[i.t]=1;
				}
			}
	printf("%d\n",k);
	rep(i,1,n)v[i]=0;
	v[1]=1;if(k)dfs(1);
}