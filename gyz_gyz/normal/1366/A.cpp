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
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	n=min(n,m*2);
	m=min(m,n*2);
	printf("%d\n",(n+m)/3);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}