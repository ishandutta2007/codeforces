#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 1000
#define ll long long
#define mo 2147483647
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
ll l,r;
int main(){
	scanf("%I64d%I64d",&l,&r);
	printf("YES\n");
	rep(i,0,(r-l)/2)printf("%I64d %I64d\n",l+i*2,l+i*2+1);
}