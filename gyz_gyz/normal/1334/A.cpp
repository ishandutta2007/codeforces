#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18;
const int mo=998244353;
void sol(){int n,p,c;
	scanf("%d",&n);
	int lp=0,lc=0;bool fl=1;
	rep(i,1,n){
		scanf("%d%d",&p,&c);
		if(c-lc<0||p-lp<c-lc)fl=0;
		lp=p;lc=c;
	}
	printf("%s\n",fl?"YES":"NO");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}