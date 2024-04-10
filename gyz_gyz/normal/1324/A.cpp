#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
void sol(){bool v[2];int n;
	scanf("%d",&n);v[0]=v[1]=0;
	rep(i,1,n){int x;
		scanf("%d",&x);v[x&1]=1;
	}
	printf("%s\n",v[0]&&v[1]?"NO":"YES");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}