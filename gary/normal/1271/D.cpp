/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
11.
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int dp[5000+10][5000+10],a[5000+10],to[5000+10],era[5001][5001],b[5000+10],c[5000+10];
vector<int> each[5000+10],from[5000+10];
bool cmp(int A,int B){
	return c[A]>c[B];
}
bool cmp2(int A,int B){
	return A>B;
}
int main(){
	rep(i,5000+10)
		rep(j,5000+10)
			dp[i][j]=-INF;
	int n,m,k_;
	cin>>n>>m>>k_;
	rb(i,1,n) cin>>a[i]>>b[i]>>c[i];
	rb(i,1,m){
		int u,v;
		scanf("%d %d",&u,&v);
		to[v]++;
		each[u].PB(v);
		from[v].PB(u);
	}
	rb(i,1,n){
		if(to[i]==0){
			each[i].PB(i);
			from[i].PB(i);
		}
		sort(ALL(from[i]),cmp2);
		int SZ=from[i].size();
		rep(j,SZ){
			if(j){
				era[from[i][j]][i]=1;
			}
		}
//		cout<<from[i][0]<<" "<<i<<endl; 
	}
	rb(i,1,n) sort(ALL(each[i]),cmp);
	dp[0][k_]=0;
	rb(i,1,n){
		rb(k,0,5000-b[i]+1){
			if(k>=a[i]){
				dp[i][k+b[i]]=dp[i-1][k];
			}
			int SZ=each[i].size();
			int sum=0;
			int tot=0;
			rep(j,SZ){
				if(era[i][each[i][j]]){
					continue;
				} 
				tot++;
				sum+=c[each[i][j]];
				if(k>=a[i]){
					if(k+b[i]-tot>=0)
					dp[i][k+b[i]-tot]=max(dp[i][k+b[i]-tot],dp[i-1][k]+sum);
				}
			}
		}
	} 
	int res=-1;
	rb(i,0,5000){
		res=max(res,dp[n][i]);
	}
	cout<<res<<endl;
	return 0;
}