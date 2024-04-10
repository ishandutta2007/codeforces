//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int a[100005];
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	int dp[100][100005];
	for(int i=1;i<100;i++)
		for(int j=n;j>=1;j--){
			if(a[j]+j+i>n)
			dp[i][j]=1;
			else
			dp[i][j]=dp[i][j+a[j]+i]+1;
		}
	int q;
	scanf("%d",&q);
	while(q--){
		int p,k;
		scanf("%d %d",&p,&k);
		if(k<100)
		printf("%d\n",dp[k][p]);
		else{
			int ans=0;
			while(p<=n){
				ans++;
				p=p+a[p]+k;
			}
			printf("%d\n",ans);
		}
	}
	
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
*/