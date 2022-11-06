#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=998244353;
const int inf=1e9;
char s[N];ll a[N];
int main(){int n,k;
	scanf("%d%d",&n,&k);
	map<ll,int>v;ll ans=0;
	rep(i,1,n){ll r=0;
		scanf("%s",s+1);
		rep(i,1,k){r*=3;
			if(s[i]=='E')++r;
			if(s[i]=='T')r+=2;
		}
		a[i]=r;++v[r];
	}
	rep(i,1,n)rep(j,i+1,n){
		ll r=0,x=a[i],y=a[j],t=1;
		rep(l,1,k){
			r+=t*(x%3==y%3?x%3:3-x%3-y%3);
			t*=3;x/=3;y/=3;
		}
		ans+=v[r];
	}
	printf("%lld\n",ans/3);
}