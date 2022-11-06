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
#define N 200000
#define K 15000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int T,n,s,tot,a[N],b[N],c[N];
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);tot=s=0;
		rep(i,1,n){
			scanf("%d",&c[i]);b[c[i]]^=1;
			if(!b[c[i]])a[++tot]=c[i];
		}
		rep(i,1,n)b[c[i]]=0;sort(a+1,a+tot+1);
		rep(i,1,tot-1)if((!s)||(a[i+1]*a[s]<a[s+1]*a[i]))s=i;
		printf("%d %d %d %d\n",a[s],a[s],a[s+1],a[s+1]);
	}
}