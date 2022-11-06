#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
bool v[N];
void sol(){int n,ans=0;
	scanf("%d",&n);
	rep(i,1,n)v[i]=0;
	rep(i,1,n){int k;bool ok=0;
		scanf("%d",&k);
		rep(j,1,k){int x;
			scanf("%d",&x);
			if(!ok&&!v[x])v[x]=ok=1;
		}
		if(!ok&&!ans)ans=i;
	}
	if(!ans)printf("OPTIMAL\n");else{
		printf("IMPROVE\n");
		rep(i,1,n)if(!v[i]){
			printf("%d %d\n",ans,i);return;
		}
	}
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}