#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=1e6+10;
double h[N];int sz[N];
int main(){int n,t=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		h[++t]=x;sz[t]=1;
		while(t>1&&h[t]<=h[t-1]){
			h[t-1]=(h[t]*sz[t]+h[t-1]*sz[t-1])/(sz[t]+sz[t-1]);
			sz[t-1]+=sz[t];--t;
		}
	}
	rep(i,1,t){
		rep(j,1,sz[i])printf("%.11lf\n",h[i]);
	}
}