#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e6+10;
const int mo=1e9+7;
int main(){int n;
	scanf("%d",&n);
	while(n--){ll x;
		scanf("%lld",&x);
		int ans=0;
		while(!(x%5))++ans,x=x/5*4;
		while(!(x%3))++ans,x=x/3*2;
		while(!(x&1))++ans,x>>=1;
		printf("%d\n",x>1?-1:ans);
	}
}