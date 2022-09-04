#pragma (-Ofast )
#pragma unroll
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
#define N 500005
bitset<705> dp[705][705];
int l[705][705];
int r[705][705];
int a[705];
int ok[705][705];
int main(){
	int n;
	scanf("%d",&n);
	MEM(dp);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(__gcd(a[i],a[j])!=1)
				ok[i][j]=1;
		}
		l[i][i]=1;
		r[i][i]=1;
	}
	for(int i=0;i<n;i++){
		for(int le=0;le<n;le++){
			if(le+i>=n)
			break;
			for(int head=le;head<=le+i;head++){
				if(l[head][le]&&r[head][le+i]){
					dp[le][le+i][head]=1;
					if(le!=0&&ok[head][le-1]){
						r[le-1][le+i]=1;
					}
					if(le+i<n-1&&ok[head][le+i+1]){
						l[le+i+1][le]=1;
					}
				}
			}
		}
	}
	int ok=0;
	for(int i=0;i<n;i++){
		if(dp[0][n-1][i])
		ok=1;
	}
	if(ok){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}
/*
1 2 3 3 2 1 =6
1 2 4       12
1 3 3       3
1 3 4       8
2 2 3       4
2 2 4       9
2 3 3       2
2 3 4       6

*/