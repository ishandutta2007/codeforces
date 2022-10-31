#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-11;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
char in[21][110000];
int p[110000];
int dp[21][1<<20];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++)scanf("%s",in[i]);
	for(int i=0;i<b;i++){
		for(int j=0;j<a;j++){
			p[i]+=(in[j][i]-'0')*(1<<j);
		}
	}
	for(int i=0;i<b;i++){
		dp[0][p[i]]++;
	}
	for(int i=1;i<=a;i++){
		for(int j=0;j<(1<<a);j++){
			int ad=0;
			for(int k=0;k<a;k++){			
				int tmp=dp[i-1][j^(1<<k)];
				ad+=tmp;
			}
			dp[i][j]=(ad+(i-2-a)*(i>1?dp[i-2][j]:0))/i;
		}
	}
	for(int i=0;i<(1<<a);i++){
	//	for(int j=0;j<=a;j++)printf("%d ",dp[j][i]);printf("\n");
	}
	int ret=mod;
	for(int i=0;i<(1<<a);i++){
		int tmp=0;
		for(int j=0;j<=a;j++){
			tmp+=min(j,a-j)*(dp[j][i]);
		}
		ret=min(ret,tmp);
	}
	printf("%d\n",ret);
}