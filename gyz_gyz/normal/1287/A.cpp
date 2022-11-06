#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=998244353;
const int inf=1e9;
char s[N];
void sol(){int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int ct=-inf,ans=0;
	rep(i,1,n){++ct;
		if(s[i]=='A')ct=0;
		ans=max(ans,ct);
	}
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}