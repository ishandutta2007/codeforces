/*
AuThOr GaRyMr
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
int n,K;
int cost [88][88],need;
int fv[88],t1=0,fv2[10],t2=0;
LL dp[6],dp2[6];
LL res=0;
int cc[6][6];
const LL MAX=8e9;
int AA[81];
void calc(){
	t1=0;
	int To=2;
	rb(i,2,n){
		if(To<=t2&&fv2[To]==AA[i]) {
			To++;
			continue;
		}
		fv[++t1]=AA[i];
	}
	rb(i,1,t2){
		dp[i]=dp2[i]=8000000000ll+10ll; 
	}
	rb(i,1,t2)
		rb(j,1,t2){
			cc[i][j]=2e8+10;
			rb(k,1,t1){
				cc[i][j]=min(cc[i][j],cost[fv2[i]][fv[k]]+cost[fv[k]][fv2[j]]);
			}
		}
	dp[1]=0;
	rb(i,1,need+1){
		rb(j,1,t2){
			if(dp[j]<res)
			rb(k,1,t2){
				dp2[k]=min(dp2[k],dp[j]+cc[j][k]);
				if(i==need+1){
				res=min(res,dp2[1]);
				break;
				}
			}
		}
		rb(j,1,t2){
			dp[j]=dp2[j];
			dp2[j]=MAX;
		}
	}	
}
void calc2(){
	rb(i,fv2[t2]+1,n)
		fv[++t1]=AA[i];
	rb(i,1,t2){
		dp[i]=dp2[i]=MAX; 
	}
	rb(i,1,t2)
		rb(j,1,t2){
			cc[i][j]=2e8+10;
			rb(k,1,t1){
				cc[i][j]=min(cc[i][j],cost[fv2[i]][fv[k]]+cost[fv[k]][fv2[j]]);
			}
		}
	dp[1]=0;
	rb(i,1,need+1){
		rb(j,1,t2){
			if(dp[j]<res)
			rb(k,1,t2){
				dp2[k]=min(dp2[k],dp[j]+cc[j][k]);
				if(i==need+1){
				res=min(res,dp2[1]);
				break;
				}
			}
		}
		rb(j,1,t2){
			dp[j]=dp2[j];
			dp2[j]=MAX;
		}
	}	
}
//int RANN_KEY;
void dfs(int now,int col){
	if(col==need){
		int ss=t1;
		if(n<K)
		calc();
		else
		calc2();
		t1=ss;
		if(res==MAX){
			cout<<res<<endl;
			exit(0);
		}
	}
	else{
		if(n<K){
			dfs(now,col+1);
			rb(i,now+1,n){
				fv2[++t2]=AA[i];
				dfs(i,col+1);
				--t2;
			}	
		}
		else{
			int ss=t1;
			rb(i,now+1,n){
				if(i+need-col-1>n) break;
				fv2[++t2]=AA[i];
				dfs(i,col+1);
				fv[++t1]=i;
				--t2;
			}	
			t1=ss;
		}
	}
}
int main(){
	fastio;
	cin>>n>>K;
	
	SRAND;
//	if(n==80){
//		RANN_KEY=random(n)+2;
//		if(RANN_KEY==n) RANN_KEY--;
//	}
	int ok[100]={0};
	rb(i,1,n){
		int key=i;
//		if(i==1){
//			key=1;
//		}
//		else{
//			key=random(n)+1;
//			while(ok[key]){
//				
//			key=random(n)+1;
//			}
//		}
//		ok[key]=1;
		AA[i]=key;
	}
	rb(i,1,n)
		rb(j,1,n)
		cin>>cost[i][j];
	need=K/2-1;
	fv2[++t2]=1;
	res=MAX;
	dfs(1,0);
	cout<<res<<endl;
	return 0;
}