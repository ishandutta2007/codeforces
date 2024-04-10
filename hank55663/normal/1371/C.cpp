#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		LL a,b,n,m;
		scanf("%lld %lld %lld %lld",&a,&b,&n,&m);
		if(min(a,b)>=m&&a+b>=n+m){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}

	}
	return 0;
}