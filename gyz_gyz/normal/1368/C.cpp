#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,ll>pil;
const int N=1e6+10;
const int inf=1e9;
const int mo=998244353;
int main(){int n;
	scanf("%d",&n);
	printf("%d\n",n*3+4);
	printf("0 0\n");
	rep(i,1,n+1)printf("%d %d\n%d %d\n%d %d\n",i,i-1,i-1,i,i,i);
}