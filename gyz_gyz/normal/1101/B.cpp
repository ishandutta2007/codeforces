#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 10010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){string s;
	cin>>s;int n=s.length()-1,l=0,r=n;
	while(l<=n&&s[l]!='[')++l;
	while(l<=n&&s[l]!=':')++l;
	while(r&&s[r]!=']')--r;
	while(r&&s[r]!=':')--r;
	if(l>=r)return printf("-1\n"),0;int ans=4;
	rep(i,l+1,r-1)if(s[i]=='|')++ans;
	printf("%d\n",ans);
}