/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,m;
int dis[51][51],far[51],near[51];LL dp[51][51][51];
bool ok[51][51][51];
int main(){
	fastio;
	R2(n,m);
	memset(dis,63,sizeof(dis));
	rb(i,1,n)
		dis[i][i]=0;
	rb(i,1,m){
		int u,v,c;
		R2(u,v);
		R(c);
		dis[u][v]=dis[v][u]=c;
	}
	rb(k,1,n)
		rb(i,1,n)
			rb(j,1,n)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
	rb(i,1,n){
		far[i]=-INF;
		near[i]=INF;
		rb(j,1,n)
		{
			if(i!=j){
				far[i]=max(far[i],dis[i][j]);
				near[i]=min(near[i],dis[i][j]);
			}
		}
//		cout<<far[i]<<"-"<<near[i]<<endl;
	}
	rb(i,1,n)
		rb(j,1,n)
			if(i!=j)
			rb(k,1,n){
				if(j!=k){
					mp gold,bronze;
					gold=II(near[i],i);
					bronze=II(far[j],j);
					rb(l,1,n){
						if(II(dis[k][l],k)>gold&&II(dis[k][l],k)<bronze){
							ok[i][j][k]=1;
						}
					}
				}
			}
	int g1,g2,s1,s2;
	R2(g1,g2);
	R2(s1,s2);
	LL res=0;
	rb(i,1,n){
		rb(j,1,n){
			if(i!=j){
				mp gold,bronze;
				gold=II(near[i],i);
				bronze=II(far[j],j);
				if(gold>bronze) continue;
				memset(dp,0,sizeof(dp));
				dp[0][0][0]=1;
				rb(k,1,n){
					rl(g,n,0){
						rl(b,n,0){
							if(k==i){
								if(g){
									dp[k][g][b]=dp[k-1][g-1][b];
								}
							}	
							else
							if(k==j){
								if(b){
									dp[k][g][b]=dp[k-1][g][b-1];
								}			
							}
							else{
								if(g&&II(near[k],k)<gold){
									dp[k][g][b]+=dp[k-1][g-1][b];
								}
								if(b&&II(far[k],k)>bronze){
									dp[k][g][b]+=dp[k-1][g][b-1];
								}
								if(ok[i][j][k]){
									dp[k][g][b]+=dp[k-1][g][b];
								}
							}
						}
					}
				} 
				rb(g,0,n)
					if(g<=g2&&g>=g1)
					rb(b,0,n){
						int sil=n-g-b;
						if(sil<=s2&&sil>=s1){
//							cout<<i<<" "<<j<<" "<<dp[n][g][b]<<endl;
							res+=dp[n][g][b];
						}
					}
			}
		}
	}
	cout<<res<<endl;
	return 0;
}