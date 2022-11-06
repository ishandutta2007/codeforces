#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mo=998244353;
void sol(){int n,s,k;set<int>S;
	scanf("%d%d%d",&n,&s,&k);
	rep(i,1,k){int x;
		scanf("%d",&x);S.insert(x);
	}
	rep(i,0,k)
		if((s+i<=n&&!S.count(s+i))||(s-i>0&&!S.count(s-i)))
			return(void)printf("%d\n",i);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}