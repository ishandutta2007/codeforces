#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=998244353;
ll f[101][26];char s[N];
int main(){int n;ll m;
	scanf("%d%lld",&n,&m);
	scanf("%s",s+1);
	rep(i,1,n){
		dep(j,i,1){
			f[j][s[i]-'a']=j==1;
			rep(k,0,25)f[j][s[i]-'a']+=f[j-1][k];
			f[j][s[i]-'a']=min(f[j][s[i]-'a'],m);
		}
	}ll ans=0;
	dep(i,n,1){
		rep(j,0,25){
			ll s=min(f[i][j],m);
			m-=s;ans+=s*(n-i);
		}
	}
	if(m)--m,ans+=n;
	printf("%lld\n",m?-1:ans);
}