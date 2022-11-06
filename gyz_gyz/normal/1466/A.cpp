#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const ll inf=1e18;
int a[N];
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]);
	set<int>s;
	rep(i,1,n)rep(j,i+1,n)s.insert(a[j]-a[i]);
	printf("%d\n",int(s.size()));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}