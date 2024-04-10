#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 200000
#define mo 998244353
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,ans,tot,x,y;char s[N];
int main(){
	scanf("%d%s",&n,s+1);
	rep(i,1,n)if(s[i]=='G')++x,++tot;else{
		ans=max(ans,x+y+1);y=x;x=0;
	}
	ans=max(ans,x+y+1);
	printf("%d\n",min(ans,tot));
}