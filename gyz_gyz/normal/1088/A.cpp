#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define N 200000
#define mo 1000000007
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
int main(){int n;
	scanf("%d",&n);
	if(n==1){
		printf("-1\n");return 0;
	}
	printf("%d %d\n",n,n);
}