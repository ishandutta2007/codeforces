#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 998244353
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,m,x,y,ans,dis[N],fa[N];bool pos[N];
vector<int>p[N];
void f(int x){int dd=0;
	for(auto i:p[x])if(i!=fa[x]){
		fa[i]=x;dis[i]=dis[x]+1;f(i);
		dd=max(dd,dis[i]);
		if(pos[i]&&dis[x]>2)dis[x]=2;
	}
	if(dd>2)pos[x]=dis[x]=1,ans++;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		scanf("%d%d",&x,&y);
		p[x].pb(y);p[y].pb(x);
	}f(1);
	printf("%d\n",ans);
}