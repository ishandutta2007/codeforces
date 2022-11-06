#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
char s[N];
void sol(){int n,m,x,y,ans=0;
	scanf("%d%d%d%d",&n,&m,&x,&y);y=min(y,x*2);
	rep(i,1,n){
		scanf("%s",s+1);bool fl=0;
		rep(j,1,m)if(s[j]=='.'){
			if(fl)fl=0,ans+=y;else fl=1;
		}else if(fl)fl=0,ans+=x;
		if(fl)ans+=x;
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}