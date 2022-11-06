#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define ll long long
#define N 300000
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
int T;ll a,b,k;
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%I64d%I64d%I64d",&a,&b,&k);
		printf("%I64d\n",(k+1)/2*a-k/2*b);
	}
}