//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int f[N];
int KMP(char c[]){
	int j=-1;
	f[0]=-1;
	for(int i=1;c[i]!=0;i++)
	{
		while(j>=0&&c[j+1]!=c[i])
		j=f[j];
		if(c[j+1]==c[i])
		j++;
		f[i]=j;
	}
	j++;
	return j;
}

int main(){
	char c[N];
	scanf("%s",c);
	char t[N];
	scanf("%s",t);
	int len=strlen(t);
	KMP(t);
	int j=-1;
	int ans=0;
	int ok[N];
	MEM(ok);
	for(int i=0;c[i]!=0;i++){
		for(int j=0;t[j]!=0&&c[i+j]!=0;j++){
			if(c[j+i]!=t[j]&&c[j+i]!='?')
			break;
			else if(t[j+1]==0){
				ok[i+j]=1;
			}
		}
	}
	vector<int> v;
	for(int j=f[len-1];j!=-1;j=f[j])v.pb(j); 
	int dp[N];
	int unmatchdp[N];
	MEM(dp);
	MEM(unmatchdp);
	for(int i=0;c[i]!=0;i++){
		if(ok[i]){
			dp[i]=1+unmatchdp[i-len];
			for(vector<int>::iterator it=v.begin();it!=v.end();it++){
				dp[i]=max(dp[i],dp[i-(len-*it)+1]+1);
			//	printf("%d",*it);
			}
		//	printf("\n");
		}
		unmatchdp[i]=max(unmatchdp[i-1],dp[i]);
	//	printf("%d %c\n",unmatchdp[i],c[i]);
	}
	printf("%d\n",unmatchdp[strlen(c)-1]); 
	return 0;
} 
//xabcabcab
//???????ab
// 10010
//1 1 2 6 3 8 4 11 5 17 6 15 7 13 8 25 9 22 10 27
//1
//2 4 6 8 10
//3 6 9
//4 2 6 8 10
//5 5 10
//6 2 3 4 6 8 10