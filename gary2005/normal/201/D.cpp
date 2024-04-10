/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
mp rest;
map<string,int> M;
int n,m;
int a[500000+20],nex[500000+20][15];
int dp[15*(15-1)/2+20][1<<15];
int solve(){
	scanf("%d",&m);
	memset(dp,63,sizeof(dp));
	memset(nex,63,sizeof(nex));
	rb(i,1,m){
		string s;
		cin>>s;
		if(M.find(s)==M.end()) a[i]=-1;
		else a[i]=M[s];
	}
	rl(i,m,1){
		if(a[i]!=-1){
			nex[i][a[i]]=i;
		}
		rep(j,15)
			check_min(nex[i][j],nex[i+1][j]);
	}
	dp[0][0]=0;
	rep(mask,1<<n){
		int cnt=__builtin_popcount(mask);
		rb(j,0,cnt*(cnt-1)/2){
			if(dp[j][mask]<=m){  
				int pos=dp[j][mask];
				rep(k,n){
					int New=cnt-__builtin_popcount(mask&((1<<k)-1));
					if(!((mask>>k)&1)){
						if(nex[pos+1][k]<=m){
							check_min(dp[j+New][mask|(1<<k)],nex[pos+1][k]);
						}
					}
				}
			}
		}
	}
	int rest=INF;
	rb(i,0,n*(n-1)/2){
		if(dp[i][(1<<n)-1]<=m){
			rest=i;
			break;
		}
	}
	return rest;
}
int main(){
	scanf("%d",&n);	
	rep(i,n){
		string ss;
		cin>>ss;
		M[ss]=i;
	}
	rest=II(-INF,INF);
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		int pi=solve();
		if(pi<rest.SEC) rest=II(i,pi);
	}
	if(rest.SEC==INF){
		puts("Brand new problem!");
		return 0;
	}
	printf("%d\n",rest.FIR);
	cout<<"[:"; 
	rest.SEC=(n)*(n-1)/2+1-rest.SEC;
	rb(i,1,rest.SEC){
		printf("|");
	} 
	cout<<":]\n";
	return 0;
}