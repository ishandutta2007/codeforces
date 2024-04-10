#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int inf=1e9;
void sol(){int n,m,ans=0;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;
		scanf("%d",&x);ans+=x;
	}
	printf("%d\n",min(ans,m));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}