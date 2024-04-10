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
int n,m,t; 
vector<mp > each[5001];
priority_queue<mp > Q;
int dp[5001][5001];
int las[5001][5001];
int main(){
	memset(dp,-1,sizeof(dp));
	cin>>n>>m>>t;
	rep(i,m){
		int xi,yi,vi;
		cin>>xi>>yi>>vi;
		each[xi].PB(II(yi,vi));
	}
	Q.push(II(0,1*10000+0));
	dp[1][0]=0;
	while(!Q.empty()){
		int i=Q.top().SEC/10000;
		int j=Q.top().SEC%10000;
		int c=-Q.top().FIR;
		Q.pop();
		if(c<dp[i][j]) continue;
		int SZ=each[i].size();
		rep(k,SZ)
		{
			int T=c+each[i][k].SEC;
			if(T<=t){
				if(dp[each[i][k].FIR][j+1]==-1||dp[each[i][k].FIR][j+1]>T)
				{
					las[each[i][k].FIR][j+1]=i;
					dp[each[i][k].FIR][j+1]=T;
					Q.push(II(-T,each[i][k].FIR*10000+j+1));
					
				}
			}
		}
	}
	vector<int> WAY;
	rl(i,n-1,0){
//		cout<<dp[n][i]<<endl;
		if(dp[n][i]!=-1){
			int now=n;
			int it=i;
			rb(k,1,i+1){
				WAY.PB(now);
				now=las[now][it];
				it--;
			}
			break;
		}
	}
	reverse(WAY.begin(),WAY.end());
	cout<<WAY.size()<<endl;
	rep(i,WAY.size()){
		cout<<WAY[i]<<" ";
	}
	return 0;
}