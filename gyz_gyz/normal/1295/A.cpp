#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
using namespace std;
typedef long long ll;
const int N=1e5+10;
void sol(){int n;
	scanf("%d",&n);
	printf("%d",n&1?7:1);
	rep(i,1,n/2-1)printf("1");
	printf("\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}