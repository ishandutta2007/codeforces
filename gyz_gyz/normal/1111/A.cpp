#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 110
#define mo 998244353
#define eps 1e-14
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
bool a[300];
int main(){string s,t;
	cin>>s>>t;int n=s.length()-1;
	if(t.length()!=n+1)return printf("No\n"),0;
	a['a']=a['e']=a['i']=a['o']=a['u']=1;
	rep(i,0,n)if(a[s[i]]!=a[t[i]])return printf("No\n"),0;
	printf("Yes\n");
}