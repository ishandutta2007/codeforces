#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=1e9;
const int mo=998244353;
void sol(){int c0=0,c1=0,n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;
		scanf("%d",&x);
		if(x&1)++c1;else ++c0;
	}
	if(!c1)printf("No\n");
	else if(!c0)printf("%s\n",m&1?"Yes":"No");
	else if(n==m)printf("%s\n",c1&1?"Yes":"No");
	else printf("Yes\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}