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
const long long mod=924844033;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int p[5100];
long long dp[5100][5100];
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	
	for(int i=0;i<=c;i++)for(int j=0;j<=a;j++)dp[i][j]=-inf;
	dp[0][0]=0;
	for(int i=0;i<c;i++){
		deque<pair<long long,int> > Q;
		for(int j=0;j<a;j++){
			while(Q.size()&&Q.front().second<=j-b){
				Q.pop_front();
			}
			while(Q.size()&&Q.back().first<=dp[i][j]){
				Q.pop_back();
			}
			Q.push_back(make_pair(dp[i][j],j));
			long long tmp=Q.front().first;
			dp[i+1][j+1]=tmp+p[j];
		}
	}
	long long ret=-1;
	for(int i=a-b+1;i<=a;i++)ret=max(ret,dp[c][i]);
	printf("%I64d\n",ret);
}