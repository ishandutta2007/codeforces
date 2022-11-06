#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int inf=1e9;
const int mo=1000000007;
int main(){int n,mx=0;
	scanf("%d",&n);
	rep(i,1,n){int x;
		scanf("%d",&x);
		printf("%d%c",x+mx,i==n?'\n':' ');
		mx=max(mx,x+mx);
	}
}