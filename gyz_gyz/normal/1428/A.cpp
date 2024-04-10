#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e6+10;
const int mo=998244353;
const ll inf=1e18;
void sol(){int x1,y1,x2,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	printf("%d\n",abs(x1-x2)+abs(y1-y2)+(x1!=x2&&y1!=y2)*2);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}