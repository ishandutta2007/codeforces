#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e5+10;
int p[N];
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;
		scanf("%d",&x);p[x]=i;
	}
	int nw=0;ll ans=0;
	rep(j,1,m){int x;
		scanf("%d",&x);
		if(p[x]>nw){
			ans+=(p[x]-j)*2+1;
			nw=p[x];
		}else ++ans;
	}
	printf("%lld\n",ans);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}