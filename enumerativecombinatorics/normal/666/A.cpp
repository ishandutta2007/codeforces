#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
char in[11000];
int dp[11000][3];
set<string>S;
char tmp[4];
int n;
int solve(int a,int b){
	if(~dp[a][b])return dp[a][b];
	if(a==n)return dp[a][b]=1;
	int t=0;
	if(a<=n-2){
		if(b!=0||in[a]!=in[a-2]||in[a+1]!=in[a-1]){
			int res=solve(a+2,0);
			if(res){
				t=res;
				tmp[2]=0;tmp[0]=in[a];tmp[1]=in[a+1];string tt=tmp;S.insert(tt);
			}
		}	
	}
	if(a<=n-3){
		if(b!=1||in[a]!=in[a-3]||in[a+1]!=in[a-2]||in[a+2]!=in[a-1]){
			int res=solve(a+3,1);
			if(res){
				t=res;
				tmp[3]=0;tmp[0]=in[a];tmp[1]=in[a+1];tmp[2]=in[a+2];string tt=tmp;S.insert(tt);
			}
		}	
	}
	return dp[a][b]=t;
}
int main(){
	scanf("%s",in);
	n=strlen(in);
	for(int i=0;i<11000;i++)for(int j=0;j<3;j++)
		dp[i][j]=-1;
	for(int i=5;i<=n;i++){
		solve(i,2);
	}
	printf("%d\n",(int)(S.size()));
	for(set<string>::iterator it=S.begin();it!=S.end();it++)printf("%s\n",(*it).c_str());
}