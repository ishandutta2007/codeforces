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
const int MAXN=505;
int dp[MAXN][MAXN];
mp pre[MAXN][MAXN];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	memset(dp,63,sizeof(dp));
	queue<pair<int,mp> > pq;
	dp[0][n]=0;
	pq.push(II(0,II(0,n)));
	while(!pq.empty()){
		pair<int,mp> now=pq.front();
		pq.pop();
		rb(i,0,now.second.FIR){
			int j=k-i;
			if(j<=now.SEC.SEC){
				if(dp[now.SEC.FIR-i+j][now.SEC.SEC-j+i]>now.FIR+1){
					dp[now.SEC.FIR-i+j][now.SEC.SEC-j+i]=now.FIR+1;
					pre[now.SEC.FIR-i+j][now.SEC.SEC-j+i]=II(i,j);
					pq.push(II(now.FIR+1,II(now.SEC.FIR-i+j,now.SEC.SEC-j+i)));
				}
			}
		}
	}
	if(dp[n][0]==INF){
		puts("-1");
		return 0;
	}
	int ans=0;
	vector<mp> ope;
	vector<int> v[2];
	rb(i,1,n) v[0].PB(i);
	while(v[0].size()){
		int i,j;
		i=pre[v[0].size()][v[1].size()].first;
		j=pre[v[0].size()][v[1].size()].SEC;
		vector<int> S[2];
		rb(z,1,j) S[1].PB(v[0].back()),v[0].POB();
		rb(z,1,i) S[0].PB(v[1].back()),v[1].POB();
		for(auto it:S[0]) v[0].PB(it);
		for(auto it:S[1]) v[1].PB(it); 
		cout<<"? ";
		for(auto it:S[0]) printf("%d ",it);
		for(auto it:S[1]) printf("%d ",it);
		puts("");
		ff;
		int val;
		scanf("%d",&val);
		ans^=val;
	}
	printf("! %d\n",ans);
	return 0;
}