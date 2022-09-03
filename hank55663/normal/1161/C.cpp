#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
/*
int dp[50][50][50][50];
int DP(vector<int> a){
	sort(a.begin(),a.end());
	//int flag=0;
	//if(a[0]==1&&a[1]==1&&a[2]==1&&a[3]==1){
	//	flag=1;
	//}
	if(a[0]==0&&a[1]==0&&a[2]==0)return 0;
	//if(flag){
		//printf("? %d\n",dp[a[0]][a[1]][a[2]][a[3]]);
	//}
	if(dp[a[0]][a[1]][a[2]][a[3]]!=-1)return dp[a[0]][a[1]][a[2]][a[3]];
	//if(a[0]==1&&a[1]==1&&a[2]==1&&a[3]==1){
	//	flag=1;
	//}
	for(int k=0;k<3;k++){
		for(int i = 1;i<=a[k];i++){
			for(int j = k+1;j<4;j++){
				for(int kk=1;kk<=a[j];kk++){
					a[k]-=i;
					a[j]-=kk;
					//if(flag)
					//printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],DP(a));
					if(DP(a)==0){
						a[k]+=i;
						a[j]+=kk;
						return dp[a[0]][a[1]][a[2]][a[3]]=1;
					}
					a[k]+=i;
					a[j]+=kk;
				//	if(flag)
				//	printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
				}
			}
		}
	}
	//if(flag)
	//	printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
	dp[a[0]][a[1]][a[2]][a[3]]=0;
	//if(flag)
		//printf("%d %d %d %d %d\n",a[0],a[1],a[2],a[3],dp[a[0]][a[1]][a[2]][a[3]]);
	return dp[a[0]][a[1]][a[2]][a[3]];
}*/
int main(){
	/*memset(dp,-1,sizeof(dp));
	for(int i = 1;i<5;i++){
		for(int j = 1;j<5;j++){
			for(int k = 1;k<5;k++){
				for(int l = 1;l<5;l++){
					if(!DP(vector<int>{i,j,k,l})){
						printf("%d %d %d %d\n",i,j,k,l);
					}
				}
			}
		}
	}*/
	//printf("%d %d\n",DP(vector<int>{1,1,1,1}),dp[1][1][1][1]);
	int n;
	scanf("%d",&n);
	int Min=0;
	int a[55];
	for(int i = 0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	if(a[n/2]==a[0]){
		printf("Bob\n");
	}
	else{
		printf("Alice\n");
	}
}
/*

2*5!     240
2*4!*5   240
2*3!*10 120
2*2!*10 40
2*1!*5  10
2    2

*/