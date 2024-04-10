#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
int f[10005];
LL dp[305][305][305];
void KMP(string s){
	int j=-1;
	f[0]=-1;
	for(int i=1;i<s.size();i++){
		while(s[j+1]!=s[i]&&j!=-1)
		j=f[j];
		if(s[j+1]==s[i])
		j++;
		f[i]=j;
	//	printf("%d ",f[i]);
	}
//	printf("\n");
}
int main(){
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	KMP(s);
	int next[10005];
	next[0]=0;
	for(int i=0;i<s.size();i++){
		int x=f[i];
		while(x!=-1&&s[x+1]==s[i+1]){
			x=f[x];
		}
		if(s[x+1]!=s[i+1]){
			next[i+1]=x+2;
		}
		else{
			next[i+1]=0;
		}
	//	printf("%d %d\n",next[i+1],x);
	}
//	printf("\n");
	dp[0][0][0]=1;
	LL mod =1e9+7;
	for(int i=0;i<2*n;i++){
		for(int j=0;j<=2*n;j++){
			for(int k=0;k<s.size();k++){
				//printf("%d %d %d\n",i,j,k);
			//	printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
				dp[i][j][k]%=mod;
				if(s[k]=='('){
					dp[i+1][j+1][k+1]+=dp[i][j][k];
					if(j!=0)
					dp[i+1][j-1][next[k]]+=dp[i][j][k];
				}
				else{
					if(j!=0)
					dp[i+1][j-1][k+1]+=dp[i][j][k];
					dp[i+1][j+1][next[k]]+=dp[i][j][k];
				}
			}
			dp[i][j][s.size()]%=mod;
		//	printf("%d %d %d %d\n",i,j,s.size(),dp[i][j][s.size()]);
			dp[i+1][j+1][s.size()]+=dp[i][j][s.size()];
			if(j!=0)
			dp[i+1][j-1][s.size()]+=dp[i][j][s.size()];
		}
	}
	printf("%lld\n",dp[2*n][0][s.size()]%mod);
}