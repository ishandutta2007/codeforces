/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
int t[2300],a[2400];
LL pre[2002][2002];// 
int rest[2002][2002];
bool can[2002][2002];
LL dp[2002];
int ll[2002],rr[2002];
bool used_las[2002][2002];
signed main(){
	fastio;
	int k;
	cin>>n>>k;
	rb(i,1,n){
		int l,r;
		cin>>l>>r>>a[i];
		t[i]=r-l+1;
		ll[i]=l;
		rr[i]=r;
	}
	rb(i,1,n){
		int needt=0;
		int last=0;
		rb(j,i,n){
 			int res=(j==i? k:rest[i][j-1]);
//			cout<<i<<" "<<j<<" "<<res<<endl;
			check_max(last,(ll[j]));
//			if(i==1){
//				cout<<j<<' '<<last<<endl;
//			}
			if(last>rr[j]) break;
			int needt=0;
			if(a[j]<res){
				used_las[i][j]=((last)==rr[j]);
				can[i][j]=1;
				rest[i][j]=res-a[j];
				pre[i][j]=pre[i][j-1]+a[j];
				continue;
			}
			if(a[j]==res){
				last++;
				if(last>rr[j]+1) break;
				used_las[i][j]=((last-1)==rr[j]);
				can[i][j]=1;
				rest[i][j]=k;
				pre[i][j]=pre[i][j-1]+a[j];
				continue;
			}
			last++;
			int aj=a[j]-res;
			needt+=(aj+k-1)/k;
			if(needt+last>rr[j]+1){
				break;
			}
			used_las[i][j]=((needt+last)==(rr[j]+1));
			last+=needt;
			can[i][j]=1;
			pre[i][j]=pre[i][j-1]+a[j];
			rest[i][j]=(aj+k-1)/k*k-aj;
			if(rest[i][j]==0) rest[i][j]=k;
			else last--;
		}
	}
	memset(dp,127,sizeof(dp));
	dp[0]=0;                                                                            
	rb(i,1,n){                                     
		rb(j,1,i){
			if(dp[j-1]!=dp[n+1])
				if(can[j][i]){
					if(i==n||!used_las[j][i]||ll[i+1]!=rr[i]){
						check_min(dp[i],dp[j-1]+rest[j][i]-(i==n? rest[j][i]:0)+pre[j][i]);
					}
				}
		}
	}
	if(dp[n]==dp[n+1]) dp[n]=-1;
	cout<<dp[n]<<endl;                
	return 0;
}
/*
10 85
3 5 57
6 8 86
9 10 46
11 11 19
11 12 37
12 12 62
14 14 60
15 15 78
16 16 69
19 20 50
*/