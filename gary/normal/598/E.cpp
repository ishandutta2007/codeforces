//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int dp[31][31][31][31][51];
int n,m,K;
void solve(){
//	memset(dp,0x3f,sizeof(dp));
	n=30;
	m=30;
	K=50;
	rb(gao,1,K){
		rl(i,n,1){
			rl(j,m,1){
				rl(k,m,i){
					rl(l,m,j){
						if((k-i+1)*(l-j+1)<gao){
//							if(gao==1)cout<<(k-i+1)*(l-j+1)<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<gao<<endl;
							break;
//							continue;
						}
						
						dp[i][j][k][l][gao]=((k-i+1)*(l-j+1)==gao)?0:INF;
						//cut out
						int cost=l-j+1;
						int cutline=cost;
						cost*=cost;
						rb(h,i,k-1){
							if((h-i+1)*cutline>gao) {
								dp[i][j][k][l][gao]=min(min(dp[i][j][k][l][gao],INF),dp[h+1][j][k][l][gao]+cost);
//								if(i==1&&j==3&&k==2&&l==3)cout<<dp[i][j][k][l][gao]<<" "<<h<<endl;
								continue;	
							}
							
							dp[i][j][k][l][gao]=min(min(dp[i][j][k][l][gao],dp[h+1][j][k][l][gao-(h-i+1)*cutline]+cost),dp[h+1][j][k][l][gao]+cost);
						}
						cost=k-i+1;
						cutline=cost;
						cost*=cost;
						rb(h,j,l-1){
							if((h-j+1)*cutline>gao) {
								dp[i][j][k][l][gao]=min(min(dp[i][j][k][l][gao],INF),dp[i][h+1][k][l][gao]+cost);
//								if(i==1&&j==3&&k==2&&l==3)cout<<dp[i][j][k][l][gao]<<" <-2-> "<<h<<endl;
								continue;
							}
							
							dp[i][j][k][l][gao]=min(min(dp[i][j][k][l][gao],dp[i][h+1][k][l][gao-(h-j+1)*cutline]+cost),dp[i][h+1][k][l][gao]+cost);
						}
					}
					
				}
			}
		}
	}
}
int main(){
//	int st=time(0);
//	freopen("random.out","r",stdin);
//	freopen("cho.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	rb(i,1,30)
		rb(j,1,30)
			rb(k,i,30)
				rb(l,j,30){
					dp[i][j][k][l][0]=0;
				}
	
	solve();
//	cout<<"*"<<dp[1][3][2][3][1]<<endl;
//	cout<<dp[1][1][2][1][1]<<endl;
	int t;
	scanf("%d",&t);
	while(t--){
		int tmpn,tmpm,tmpk;
		scanf("%d %d %d",&tmpn,&tmpm,&tmpk);
		printf("%d\n",dp[1][1][tmpn][tmpm][tmpk]);
	}
//	cout<<"spend:"<<time(0)-st<<endl;
	return 0;
}