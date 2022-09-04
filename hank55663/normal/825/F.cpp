#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b)
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
#define seg pair<pii,pii>
//#define M 1000005
//#define pi 3.14159265359
#define count Count
using namespace std;
typedef long long LL;
int ans[8005];
pair<short,short> dp[8005][8005];
short comp[8005][8005];
int count[8005];
int main()
{	
	for(int i=0;i<8005;i++){
		count[i]=1;
		if(i>=10)
		count[i]=2;
		if(i>=100)
		count[i]=3;
		if(i>=1000)
		count[i]=4;
	}
	char s[8005];
	scanf("%s",s);
	MEM(comp);
	int len=strlen(s);
	for(int i=1;i<=len;i++)//,printf("\n"))
		for(int j=1;j<=len;j++){ 
			if(s[i-1]==s[j-1])
			comp[i][j]=comp[i-1][j-1]+1;
			else
			comp[i][j]=0;
		//	printf("%d ",comp[i][j]);
		} 
	for(int i=1;i<=len;i++){
		ans[i]=1e9;
		for(int j=i-1;j>=0;j--){
			dp[i][j].x=1;
			dp[i][j].y=ans[j];
			for(int k=j,a=1;k>=0;k-=i-j,a++){
				if(comp[i][k]>=i-j){
					if(count[dp[k][k-i+j].x+a]+dp[k][k-i+j].y<count[dp[i][j].x]+dp[i][j].y)
						dp[i][j].x=dp[k][k-i+j].x+a,dp[i][j].y=dp[k][k-i+j].y;
					else
						break;
				}
				else
				break;
			}
			ans[i]=min(ans[i],dp[i][j].y+i-j+count[dp[i][j].x]);
		//	printf("%d %d %d %d\n",i,j,dp[i][j].x,dp[i][j].y);
		}
	//	printf("%d\n",ans[i]);
	}
	printf("%d\n",ans[len]);
}