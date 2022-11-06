#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=998244353;
void sol(){int k,n,a,b;
	scanf("%d%d%d%d",&k,&n,&a,&b);--k;
	printf("%d\n",k/b<n?-1:min((k-b*n)/(a-b),n));
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}