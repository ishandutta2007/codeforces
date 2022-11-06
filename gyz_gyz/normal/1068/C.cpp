#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 3000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int n,m,x,y;vector<int>p[N];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		p[x].pb(i);p[y].pb(i);
	}
	rep(i,1,n){
		if(!p[i].size())p[i].pb(m+i);
		printf("%d\n",p[i].size());
		for(auto j:p[i])printf("%d %d\n",i,j);
	}
}