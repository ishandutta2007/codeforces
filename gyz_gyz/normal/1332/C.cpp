#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
char s[N];int v[26];
void sol(){int n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",s);int ans=n;
	rep(i,0,k/2-1){
		rep(j,0,n/k-1){
			++v[s[j*k+i]-'a'];
			++v[s[j*k+k-1-i]-'a'];
		}int res=0;
		rep(j,0,25){
			res=max(res,v[j]);
			v[j]=0;
		}
		ans-=res;
	}
	if(k&1){
		rep(j,0,n/k-1)++v[s[j*k+k/2]-'a'];
		int res=0;
		rep(j,0,25){
			res=max(res,v[j]);
			v[j]=0;
		}
		ans-=res;
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}