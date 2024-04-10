#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int mo=1e9+7;
const int inf=1e9;
const int N=1e5+10;
void sol(){int n,d,ans;
	scanf("%d%d",&n,&d);ans=d;
	rep(i,1,100000)ans=min(ans,(d-1)/(i+1)+i+1);
	printf("%s\n",ans<=n?"YES":"NO");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}