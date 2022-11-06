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
void sol(){int n;
	scanf("%d",&n);
	if(n==1){
		printf("-1\n");return;
	}
	rep(i,1,n-2)printf("8");
	printf("%d9\n",(((n-2)*2)%3)?9:8);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}