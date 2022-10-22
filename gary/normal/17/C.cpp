/*
AuThO	r GaRyMr
*/
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
string s;
const int MOD=51123987;
LL C[200][200],dp[2][66][66][66][8];//iajbkcmask 
void MMOD(LL &tmp){
	tmp%=MOD;
}
bool check(int A,int B){
	return abs(A-B)<=1;
}
int main(){
	fastio;
	cin>>n>>s;
	s='$'+s;
	rep(i,200)
		C[i][0]=1;
	rb(i,1,199)
		rb(j,1,199)
			C[i][j]=C[i-1][j-1]+C[i-1][j],C[i][j]%=MOD;
//	cout<<c[1][2]<<endl;
	dp[0][0][0][0][0]=1; 
	int now=1,prev=0;
	rb(i,1,n)
	{
		int Key=s[i]-'a';
		rb(a,0,58)
			rb(b,0,58){
				rb(c,0,58){
					//ielse  
					rep(mask,8){
						if(dp[prev][a][b][c][mask]==0) continue;
						if(mask&(1<<Key)){
							dp[now][a][b][c][mask]+=dp[prev][a][b][c][mask];
							MMOD(dp[now][a][b][c][mask]);
						} 
						else{
							if(Key==0){
								dp[now][a+1][b][c][1<<Key]+=dp[prev][a][b][c][mask];
								MMOD(dp[now][a+1][b][c][1<<Key]);
								
							}
							
							else{
								if(Key==1) dp[now][a][b+1][c][1<<Key]+=dp[prev][a][b][c][mask],MMOD(dp[now][a][b+1][c][1<<Key]);
							else dp[now][a][b][c+1][1<<Key]+=dp[prev][a][b][c][mask],MMOD(dp[now][a][b][c+1][1<<Key]);
							}
							
							dp[now][a][b][c][mask+(1<<Key)]+=dp[prev][a][b][c][mask],MMOD(dp[now][a][b][c][mask+(1<<Key)]);
							
							}
					}
				}
			}
		rep(a,60)
			rep(b,60)
				rep(c,60)
					rep(mask,8)
					dp[prev][a][b][c][mask]=0;
		swap(now,prev);
	}
	vector<pair<mp,int> > pre;
	rb(i,0,60)
		rb(j,0,60)
			rb(k,0,60){
				if(i+j+k==n&&check(i,j)&&check(k,j)&&check(i,k)){
//					cout<<i<<" "<<j<<" "<<k<<endl; 
					pre.PB(II(II(i,j),k));
				}
			}
	LL res=0;
	for(auto it:pre){
		rep(a,60)
			rep(b,60)
				rep(c,60)
					rep(mask,8)
					{
						int fa,fb,fc;
						fa=it.FIR.FIR;
						fb=it.FIR.SEC;
						fc=it.SEC;
						if(fa>0&&a==0) continue;
						if(fb>0&&b==0) continue;
						if(fc>0&&c==0) continue;
						LL tmp=1;
//						cout<<V[1][2]<<endl;
						if(fa>0){
							tmp*=C[fa-1][a-1];
							MMOD(tmp);
						}
						if(fb>0){
							tmp*=C[fb-1][b-1];
							MMOD(tmp);
						}
						if(fc>0){
							tmp*=C[fc-1][c-1];
							MMOD(tmp);
						}
//						if(tmp )cout<<a<<" "<<b<<" "<<c<<" "<<tmp <<" "<<fa<<" "<<fb<<" "<<fc<<endl; 
						res+=tmp*dp[prev][a][b][c][mask]%MOD;
						MMOD(res);}
	}cout<<res<<endl;
	return 0;
}