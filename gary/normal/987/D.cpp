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
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> dp[100000+10];
int a[100000+10];
vector<int> each[100000+10];
int main(){
	memset(dp,0x3f,sizeof(dp));
	int n,m,k,s;
	scanf("%d %d %d %d",&n,&m,&k,&s);
	queue<mp> q;
	rb(i,1,n){
		rb(j,1,k+1) dp[i].PB(INF);
		scanf("%d",&a[i]); 
		dp[i][a[i]]=0;
		q.push(II(i,a[i]));
	}
	rb(i,1,m){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		each[vi].PB(ui);
		each[ui].PB(vi);
	}
	while(!q.empty()){
		mp now=q.front();
		q.pop();
		int SZ=each[now.FIR].size();
		rep(i,SZ){
			if(dp[each[now.FIR][i]][now.SEC]>	dp[now.FIR][now.SEC]+1){
				dp[each[now.FIR][i]][now.SEC]=dp[now.FIR][now.SEC]+1;
				q.push(II(each[now.FIR][i],now.SEC)); 
				} 
		}
	}
	rb(i,1,n){
		LL cost=0;
		sort(dp[i].begin()+1,dp[i].begin()+1+k);
		rb(j,1,s){
			cost+=dp[i][j];
		}
		printf("%I64d ",cost);
	}
	return 0;
}