#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll dp[1001][2001][2][2];
int n,j;
int main(){
	ios::sync_with_stdio(false);
	dp[1][2][0][1]=dp[1][2][1][0]=dp[1][1][0][0]=dp[1][1][1][1]=1;
	cin >> n >> j;
	for(int i=1; i<n ;i++){
		for(int k=1; k<=2*i ;k++){
			for(int x=0; x<2 ;x++){
				for(int y=0; y<2 ;y++){
					for(int z=0; z<2 ;z++){
						for(int w=0; w<2 ;w++){
							int newi;
							if(x!=z && y!=w && z!=w) newi=2;
							else if(x!=z && y!=w) newi=1;
							else if(z==w) newi=0;
							else if(x==z && y==w) newi=0;
							else newi=1;
							dp[i+1][k+newi][z][w]+=dp[i][k][x][y];
							if(dp[i+1][k+newi][z][w]>=mod) dp[i+1][k+newi][z][w]-=mod;
						}
					}
				}
			}
		}
	}
	int k=j;
	cout << (dp[n][k][0][0]+dp[n][k][0][1]+dp[n][k][1][0]+dp[n][k][1][1])%mod <<endl;
}