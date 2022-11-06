#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
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
#define N 262144
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,d,k,a[N],s[N],p[N];
bool cmp(int x,int y){return a[x]<a[y];}
int main(){
	scanf("%d%d%d",&n,&m,&d);k=1;
	rep(i,1,n)scanf("%d",&a[i]);
	rep(i,1,n)p[i]=i;
	sort(p+1,p+n+1,cmp);s[p[1]]=1;
	rep(i,2,n)if(a[p[i]]-a[p[i-k]]<=d)s[p[i]]=++k;
	else s[p[i]]=s[p[i-k]];
	printf("%d\n",k);
	rep(i,1,n)printf("%d ",s[i]);	
}