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
#define N 131072
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,p[N],a[N],v[N];
void cy(int x){
	a[x]=x;if(!a[p[x]])cy(p[x]);
}
void dfs(int x){v[x]=1;
	if(!v[p[x]])dfs(p[x]);
	else if(v[p[x]]==1)cy(x);
	if(!a[x])a[x]=a[p[x]];v[x]=2;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&p[i]);
	rep(i,1,n)if(!v[i])dfs(i);
	rep(i,1,n)printf("%d ",a[i]);
}