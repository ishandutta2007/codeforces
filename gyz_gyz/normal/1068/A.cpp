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
ll n,m,k,l,x;
int main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&k,&l);x=(k+l-1)/m+1;
	if(x*m>n)printf("-1\n");else printf("%I64d\n",x);
}