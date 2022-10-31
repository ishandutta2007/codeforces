#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int b[100000];
int prime[100001];
int table[100001];
int dp[100001];
vector<int>last[100001];
int main(){
	int a;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",b+i);
		table[b[i]]=1;
	}
	prime[0]=prime[1]=-1;
	for(int i=2;i<=100000;i++){
		if(prime[i]==0){
			prime[i]=1;
			for(int j=i+i;j<=100000;j+=i)prime[j]=-1;
		}
	}
	for(int i=0;i<=100000;i++){
		if(table[i])dp[i]=1;
	}
	for(int i=2;i<=100000;i++){
		if(prime[i]){
			int m=0;
			for(int j=i;j<=100000;j+=i){
				if(table[j]){
					last[j].push_back(m);
					m=j;
				}
			}
		}
	}
	for(int i=2;i<=100000;i++){
		for(int j=0;j<last[i].size();j++)dp[i]=max(dp[last[i][j]]+1,dp[i]);
	}
	int ret=0;
	for(int i=1;i<=100000;i++)ret=max(ret,dp[i]);
	printf("%d\n",ret);
}