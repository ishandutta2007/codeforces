#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){string s;
	cin>>s;int n=s.length();
	int x=n-1;bool ans=0;
	while(x>0){
		if(s[x]==s[x-1]){
			rep(i,x-1,n-3)s[i]=s[i+2];
			n-=2;ans^=1;--x;if(x>=n)--x;
		}else --x;
	}
	printf("%s",ans?"Yes":"No");
}