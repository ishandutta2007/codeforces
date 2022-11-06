#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
const int inf=1e9;
void sol(){int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	int ans=min(n,max(x+y+1-n,1));
	printf("%d ",ans);
	ans=max(min(x+y-1,n),1);
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}