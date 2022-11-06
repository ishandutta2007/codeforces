#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 3010
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define inf 1000000000
#define eps 1e-8
using namespace std;
int T,n,v,l,r;
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d%d%d%d",&n,&v,&l,&r);
		printf("%d\n",n/v-r/v+(l-1)/v);
	}
}