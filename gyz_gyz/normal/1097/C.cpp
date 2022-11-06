#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 3000000
#define mo 998244353
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int n,ml,tt,ans,a[N],b[N];
int main(){
	scanf("%d",&n);
	rep(i,1,n){string s;
		cin>>s;int l=s.length()-1,x=0,mi=0;
		ml=max(ml,l+1);
		rep(i,0,l){
			if(s[i]=='(')++x;else --x;
			mi=min(mi,x);
		}
		if(mi<0&&x!=mi)continue;
		if(!x)++tt;
		if(x>0)++a[x];
		if(x<0)++b[-x];
	}ans=tt/2;
	rep(i,1,ml)ans+=min(a[i],b[i]);
	printf("%d\n",ans);
}