#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 1000000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n;char s[N],t[N];ll k;
int main(){
	scanf("%d%lld",&n,&k);ll x=1,ans=n;
	scanf("%s",s+1);scanf("%s",t+1);
	rep(i,1,n){ll y=x;
		x=x*2-(t[i]=='a')-(s[i]=='b');
		if(x<k){
			ans+=(x-y)*(n-i+1);
		}else{
			ans+=(k-y)*(n-i+1);break;
		}
	}
	printf("%lld\n",ans);
}