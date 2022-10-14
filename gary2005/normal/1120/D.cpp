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
const int MAXN=200000+1;
LL dp[MAXN][2];
int n,c[200000+1];
bool vis[200000+1][2],leaf[200000+1];
vector<int> each[MAXN];
void calc(int now=1,int pre=-1){
	int son=0;
	for(auto it:each[now]){
		if(it!=pre){
			calc(it,now);
			son++;
		}
	}
	if(son==0){
		leaf[now]=1;
		dp[now][0]=c[now];
		dp[now][1]=0;// 
		return ;
	}
	LL sum=0;
	for(auto it:each[now]){
		if(it!=pre){
			sum+=dp[it][0];
		}
	} 
	dp[now][0]=sum;
	for(auto it:each[now]){
		if(it!=pre)
		dp[now][0]=min(dp[now][0],sum-dp[it][0]+dp[it][1]+c[now]);
	}
	LL mini=(LL)(2e16);
	for(auto it:each[now]){
		if(it!=pre){
			mini=min(mini,dp[it][1]-dp[it][0]);
		}
	}
	dp[now][1]=sum+mini;
}
vector<int> can;
void recover(int now=1,int pre=-1,int typ=0){
	if(vis[now][typ]) return ;
	vis[now][typ]=true;
	if(leaf[now]){
		if(typ==0){
			can.PB(now);
		}
		return ;
	}
	if(typ==0){
		
	LL sum=0;
	for(auto it:each[now])
	{
		if(it!=pre){
			sum+=dp[it][0]; 
		}
	}
	if(dp[now][0]==sum){
		for(auto it:each[now]){
			if(it!=pre){
				recover(it,now,0);
			}
		}	
	}
	vector<int> VoV;
	for(auto it:each[now]){
		if(it!=pre){
			if(dp[now][0]==sum-dp[it][0]+dp[it][1]+c[now]){
			VoV.PB(it);
		}
		}
	}
	if(VoV.size()==0) return;
	can.PB(now);
	if(VoV.size()==1){
		recover(VoV[0],now,1);
		for(auto it:each[now]){
			if(it!=pre&&it!=VoV[0]){
				recover(it,now,0);
			}
		}
	}
	else{
		for(auto it:each[now]){
			if(it!=pre){
				recover(it,now,0);
			}
		}
		for(auto it:VoV){
			recover(it,now,1);
		}
	} }
	else{
		LL sum=0;
		for(auto it:each[now])
		{
			if(it!=pre){
				sum+=dp[it][0]; 
			}
		}
		vector<int>	nomination;
		LL mini=(LL)(2e16);
		for(auto it:each[now]){
			if(it!=pre){
				mini=min(mini,dp[it][1]-dp[it][0]);
			}
		}	
		for(auto it:each[now]){
			if(it!=pre){
				if(dp[it][1]-dp[it][0]==mini)
				{
					nomination.PB(it);
				}
			}
		}
		if(nomination.size()==1){
			recover(nomination[0],now,1);
			for(auto it:each[now])
				if(it!=pre&&it!=nomination[0]){
					recover(it,now,0);
				}
		}
		else{
			for(auto it:each[now])
				if(it!=pre)
					recover(it,now,0);
			for(auto it:nomination)
				recover(it,now,1);
		}
	}
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n)
	cin>>c[i],dp[i][0]=dp[i][1]=(LL)(2e16);
	rb(i,2,n){
		int a,b;
		cin>>a>>b;
		each[a].PB(b);
		each[b].PB(a);
	}
	calc();
	cout<<dp[1][0]<<" ";
	recover();
	sort(ALL(can));
//	cout<<can.size()<<endl;
	vector<int> data_tmp;
	int las=-1;
	for(auto it:can)
		if(it==las) continue;
		else{
			las=it;
			data_tmp.PB(it);
		}
	can=data_tmp;
	cout<<can.size()<<endl;
	for(auto it:can){
		cout<<it<<" ";
	}
	return 0;
}