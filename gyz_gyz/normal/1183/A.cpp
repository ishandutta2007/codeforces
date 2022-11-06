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
bool ok(int x){int r=0;
	while(x)r+=x%10,x/=10;return r%4;
}
int main(){int n;
	scanf("%d",&n);
	while(ok(n))++n;
	printf("%d\n",n);
}