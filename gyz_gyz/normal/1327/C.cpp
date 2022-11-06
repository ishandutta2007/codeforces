#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+10;
const int inf=1e9;
const int mo=998244353;
int main(){int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",n+m+n*m-3);
	rep(i,2,n)printf("U");
	rep(i,2,m)printf("L");
	rep(i,1,n)rep(j,1,m)if(i!=n||j!=m)
		printf("%c",j==m?'D':i&1?'R':'L');
}