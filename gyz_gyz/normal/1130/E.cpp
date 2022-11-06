#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define N 300010
#define mo 998244353
using namespace std;
typedef long long ll;
int main(){int k;
	scanf("%d",&k);
	rep(n,1,2000)if(n*999999>k){
		printf("%d\n-1",n+1);
		rep(i,1,n)printf(" %d",i<n?1000000:(n+k)%1000000+1);
		printf("\n");return 0;
	}
}