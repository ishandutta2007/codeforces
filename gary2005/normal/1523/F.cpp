/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXM=101;
const int MAXN=14;
LL dp[1<<MAXN][MAXM];
int f[1<<MAXN][MAXM];
int dis[1<<MAXN][MAXM],dis2[MAXM][MAXM],dis3[1<<MAXN][MAXN],xa[MAXN],ya[MAXN],xb[MAXM],yb[MAXM],t[MAXM],n,m;
bool cmp(pair<mp,int> A,pair<mp,int> B){
	return A.SEC<B.SEC;
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,n) scanf("%d%d",&xa[i],&ya[i]);
	rb(i,1,m) scanf("%d%d%d",&xb[i],&yb[i],&t[i]);
	fill((LL*)dp,(LL*)dp+(1<<MAXN)*MAXM,1e18);
	fill((int*)f,(int*)f+(1<<MAXN)*MAXM,-1e9);
	vector<pair<mp,int> > inf(m+1);
	rb(i,1,m) inf[i]=II(II(xb[i],yb[i]),t[i]);
	sort(inf.begin()+1,inf.begin()+1+m,cmp);
	rb(i,1,m) xb[i]=inf[i].FIR.FIR,yb[i]=inf[i].FIR.SEC,t[i]=inf[i].SEC;
//	rb(i,1,m){
//		cout<<xb[i]<<' '<<yb[i]<<" "<<t[i]<<endl;
//	}
	rep(mask,1<<n){
		rb(k,1,m){
			dis[mask][k]=INF;
			rep(j,n){
				if((mask>>j)&1){
					check_min(dis[mask][k],abs(xb[k]-xa[j])+abs(yb[k]-ya[j]));
				}
			}
		}
	}
	rep(mask,1<<n) rep(j,n){
		dis3[mask][j]=INF;
		rep(k,n)
			if((mask>>k)&1)
				check_min(dis3[mask][j],abs(xa[j]-xa[k])+abs(ya[j]-ya[k]));
	}
	rb(i,1,m)
		rb(j,1,m)
			dis2[i][j]=abs(xb[i]-xb[j])+abs(yb[i]-yb[j]);
	rep(i,n) dp[1<<i][0]=0;
	rb(i,1,m) f[0][i]=1;
	rep(mask,1<<n){
		rb(j,0,m){
			if(f[mask][j]>=0){
				rb(nex,j+1,m){
					if(t[j]+min(dis2[j][nex],dis[mask][nex])<=t[nex]){
						check_max(f[mask][nex],f[mask][j]+1);
					}
				}
				rep(nex,n){
					if((mask>>nex)&1);
					else
						check_min(dp[mask|(1<<nex)][f[mask][j]],1ll*t[j]+min(abs(xa[nex]-xb[j])+abs(ya[nex]-yb[j]),dis3[mask][nex]));
				}
			}
			if(dp[mask][j]!=1e18){
				rep(k,n){
					check_min(dp[mask|(1<<k)][j],dp[mask][j]+dis3[mask][k]);
				}
				rb(nex,j+1,m){
					if(dp[mask][j]+dis[mask][nex]<=t[nex]){
						check_max(f[mask][nex],j+1);
					}
				}
			}
		}
	}
	int ans=0;
	rb(i,1,m) rep(mask,1<<n) check_max(ans,f[mask][i]);
	printf("%d\n",ans);
	return 0;
}