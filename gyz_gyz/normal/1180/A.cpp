#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int mo=998244353;
int main(){int n;
	scanf("%d",&n);int ans=1;
	rep(i,2,n)ans+=(i-1)*4;
	printf("%d\n",ans);
}