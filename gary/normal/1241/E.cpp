//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[500000+10][2];//
vector<mp> son[500000+10]; 
vector<int> dp_line;
int father[500000+10];
void calc(int now,int prev){
	for(auto it : son[now]){
		if(it.FIR!=prev) {
			father[it.FIR]=now;
			calc(it.FIR,now);
		}
	}
	dp_line.PB(now);
}
void mian(){
	dp_line.clear();
	int n,k;
	scanf("%d %d",&n,&k);
	rb(i,1,n) son[i].clear(),dp[i][0]=dp[i][1]=0;
	rep(i,n-1){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		son[a].PB(II(b,c)),son[b].PB(II(a,c));
	}
	father[1]=-1;
	calc(1,-1);
//	reverse(ALL(dp_line));
	for(auto i:dp_line){
		vector<LL> minus;
		for(auto j:son[i]){
			if(j.FIR!=father[i]){
//				cout<<i<<" "<<j.FIR<<endl;
				dp[i][0]+=dp[j.FIR][1];
				dp[i][1]+=dp[j.FIR][1];
				minus.PB(-((LL)(j.SEC)+dp[j.FIR][0]-dp[j.FIR][1]));
			}
		}
		sort(ALL(minus));
		int tot=0;
		for(auto j:minus){
			++tot;
			if(j>=0) break;
			if(tot<=k-1){
				dp[i][0]-=j;
			}
			if(tot<=k){
				dp[i][1]-=j;
			}
			else break;
		}
	}
//	cout<<dp[3][1]<<endl;
	printf("%I64d\n",max(dp[1][1],dp[1][0])); 
}
int main(){
	int q;
	cin>>q;
	while(q--){
		mian();
	}
	return 0;
}