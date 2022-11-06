#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define pb push_back
#define fr first
#define sc second
#define ll long long
#define N 400000
#define mo 998244353
#define inf 1000000000
#define Inf 5000000000000000000ll
using namespace std;
ll n,x,y; 
int main(){
	scanf("%lld%lld%lld",&n,&x,&y);
	if(max(x-1,y-1)<=max(n-x,n-y))printf("White");else printf("Black");
}