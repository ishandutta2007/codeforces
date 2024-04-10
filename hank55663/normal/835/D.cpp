#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 800005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef long long LL;
int dp[5005][5005];
bool pal[5005][5005];
char c[5005];
int DP(int l,int r){
	if(l==r)
	return 1;
	if(l==r-1&&c[l]==c[r])
	return 2;
	if(pal[l][r]==0)
	return 0;
	if(dp[l][r]!=-1)
	return dp[l][r];
	if((l+r)%2==0){
		dp[l][r]=DP(l,(l+r)/2-1)+1;
	}
	else{
		int mid=(l+r)/2;
		dp[l][r]=DP(l,mid)+1;
	}
	return dp[l][r];
} 
int main()
{
	scanf("%s",c);
	MEM(pal);
	for(int i=0;c[i]!=0;i++){
		for(int j=0;i-j>=0&&c[i+j]!=0;j++){
			if(c[i-j]!=c[i+j])
			break;
			pal[i-j][i+j]=true;
		//	printf("%d %d\n",i-j,i+j);
		}
		for(int j=0;i-j>=0&&c[i+j+1]!=0;j++){
			if(c[i-j]!=c[i+j+1])
			break;
			pal[i-j][i+j+1]=true;
		//	printf("%d %d\n",i-j,i+j);
		}
	}
	int ans[5005];
	MEM(ans);
	MEMS(dp);
	for(int i=0;c[i]!=0;i++)//printf("\n"))
		for(int j=i;c[j]!=0;j++){
			//printf("%d ",DP(i,j));
			ans[DP(i,j)]++;
		}
	int len=strlen(c);
	for(int i=strlen(c)-1;i>=0;i--)
	ans[i]+=ans[i+1];
	//int len=strlen(c);
	for(int i=1;i<=len;i++)
	printf("%d ",ans[i]);
}