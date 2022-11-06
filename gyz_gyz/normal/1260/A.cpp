#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
typedef long long ll;
const int N=1e6+10;
int sol(){int x,y;
	scanf("%d%d",&x,&y);
	ll w=y/x;int t=y%x;
	printf("%lld\n",t*(w+1)*(w+1)+(x-t)*w*w);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}