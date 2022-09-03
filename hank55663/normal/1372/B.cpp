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
void solve(int n){
	for(int i = 2;i*i<=n;i++){
		if(n%i==0){
			printf("%d %d\n",n/i,n/i*(i-1));
			return ;
		}
	}
	printf("%d %d\n",n-1,1);
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}