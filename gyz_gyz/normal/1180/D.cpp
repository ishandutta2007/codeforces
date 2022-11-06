#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define see(x) (cerr<<(#x)<<'='<<(x)<<endl)
#define pb push_back
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=2e5+10;
const int mo=998244353;
int main(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n/2)rep(j,1,m)printf("%d %d\n%d %d\n",i,j,n-i+1,m-j+1);
	if(n&1)rep(i,1,m)printf("%d %d\n",n/2+1,i&1?i/2+1:m-i/2+1);
}