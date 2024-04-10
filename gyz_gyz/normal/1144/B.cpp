#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) if((x+=(y))>=mo)x-=mo
#define pb push_back
#define fr first
#define sc second
#define gc getchar()
#define clz __builtin_clz
#define ctz __builtin_ctz
#define N 1000010
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
using namespace std;
typedef long long ll;
int n;vector<int>a,b;
int main(){int n;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x&1)a.pb(x);else b.pb(x);
	}int ans=0;
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int t1=a.size(),t2=b.size();
	if(t1==t2)return printf("0\n"),0;
	if(t1<t2)rep(i,0,t2-t1-2)ans+=b[i];
	else rep(i,0,t1-t2-2)ans+=a[i];
	printf("%d\n",ans);
}