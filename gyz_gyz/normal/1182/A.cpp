#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int mo=1e9+7;
const ll Inf=1e18;
int main(){int n;
	scanf("%d",&n);
	printf("%d\n",n&1?0:1<<(n>>1));
}