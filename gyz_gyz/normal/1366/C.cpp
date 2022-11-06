#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
int p[2][N];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,0,n+m)p[0][i]=p[1][i]=0;
	rep(i,1,n)rep(j,1,m){int x;
		scanf("%d",&x);
		int t1=i+j-2,t2=n+m-i-j;
		if(t1!=t2)++p[x][min(t1,t2)];
	}int ans=0;
	rep(i,0,n+m)ans+=min(p[0][i],p[1][i]);
	printf("%d\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}