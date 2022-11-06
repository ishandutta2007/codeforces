#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=1e9+7;
int main(){ll n;
	scanf("%lld",&n);ll t=1;
	rep(i,1,12){
		if(n<=i*t*9){
			ll s=(n-1)/i+t;
			int v=(n-1)%i;
			dep(j,i-2,v)s/=10;
			return printf("%lld\n",s%10),0;
		}
		n-=i*t*9;t*=10;
	}
}