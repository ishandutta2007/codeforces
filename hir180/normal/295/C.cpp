#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 2000000000
#define mod 1000000007
long long dp[55][55][205]={};
long long c[55][55]={};
int n,lim,A=0,B=0;
int main(){
	scanf("%d %d",&n,&lim);
	for(int i=0;i<n;i++){
		int fk; scanf("%d",&fk);
		if(fk==50) A++;
		else B++;
	}
	dp[A][B][0]=1;
	c[0][0]=1;
	for(int i=1;i<=50;i++){
		for(int j=0;j<=i;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		}
	}
	for(int k=1;k<=204;k++){
		for(int i=A;i>=0;i--){
			for(int j=B;j>=0;j--){
				if(k%2){
					for(int ii=i;ii<=A;ii++){
						for(int jj=j;jj<=B;jj++){
							if((i!=ii || j!=jj) && (ii-i)*50+(jj-j)*100<=lim){
								dp[i][j][k]+=(dp[ii][jj][k-1]*c[ii][ii-i]*c[jj][jj-j])%mod;
								dp[i][j][k]%=mod;
							}
						}
					}
				}else{
					for(int ii=0;ii<=i;ii++){
						for(int jj=0;jj<=j;jj++){
							if((i!=ii || j!=jj) && (i-ii)*50+(j-jj)*100<=lim){
								dp[i][j][k]+=(dp[ii][jj][k-1]*c[A-ii][i-ii]*c[B-jj][j-jj])%mod;
								dp[i][j][k]%=mod;
							}
						}
					}
				}
			}
		}
	}
	for(int k=1;k<=204;k++){
		if(dp[0][0][k]){
			printf("%d\n",k);
			printf("%lld\n",dp[0][0][k]);
			return 0;
		}
	}
	puts("-1\n0");
}