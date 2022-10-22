/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n;
vector<int> each[300000+10];
int dp[300000+10];
mp tmp[300000+10];
int Dfs(int now,int las){
	tmp[now]=II(0,0);
	dp[now]=1;
	for(auto it:each[now]){
		if(it!=las){
			int save=Dfs(it,now);
			if(save>dp[tmp[now].SEC]){
				tmp[now].SEC=it;
			}
			if(dp[tmp[now].SEC]>dp[tmp[now].FIR]) swap(tmp[now].FIR,tmp[now].SEC);
		}
	}
	if(las==-1){
		dp[now]+=each[now].size()-1+dp[tmp[now].FIR];
		if(tmp[now].SEC){
			dp[now]--;
			dp[now]+=dp[tmp[now].SEC];
		}
	}
	else{
		if(tmp[now].FIR)
		dp[now]+=each[now].size()-2+dp[tmp[now].FIR];
	}
	return dp[now];
} 
int res;
void change_root(int now,int las){
	res=max(res,dp[now]);
//	cout<<now<<" "<<dp[now]<<"------------"<<endl;
	mp save1,save2;
	int save3,save4;
	save1=tmp[now];
	save3=dp[now];
	for(auto it:each[now]){
		if(it!=las){
			save2=tmp[it];
			save4=dp[it];
//			cout<<now<<" "<<it<<" "<<tmp[now].FIR<<endl;
			if(tmp[now].FIR==it){
//				cout<<it<<"don"<<endl; 
				dp[now]=1;
				tmp[now].FIR=tmp[now].SEC;
				if(tmp[now].FIR)
				{
					dp[now]+=each[now].size()-2+dp[tmp[now].FIR];
				}
				if(dp[now]>dp[tmp[it].SEC]){
					tmp[it].SEC=now;
				}
				if(dp[tmp[it].FIR]<dp[tmp[it].SEC]) swap(tmp[it].FIR,tmp[it].SEC);
				dp[it]=1;
				dp[it]+=each[it].size()-1+dp[tmp[it].FIR];
				if(tmp[it].SEC){
					dp[it]--;
					dp[it]+=dp[tmp[it].SEC];
				}
			}
			else{
				dp[now]=1;
				//dp[it]++; 
				dp[now]+=each[now].size()-2+dp[tmp[now].FIR];
				if(dp[now]>dp[tmp[it].SEC]){
					tmp[it].SEC=now;
				}
				if(dp[tmp[it].FIR]<dp[tmp[it].SEC]) swap(tmp[it].FIR,tmp[it].SEC);
				dp[it]=1;
				dp[it]+=each[it].size()-1+dp[tmp[it].FIR];
				if(tmp[it].SEC){
					dp[it]--;
					dp[it]+=dp[tmp[it].SEC];
				}
			}
			change_root(it,now);
			dp[it]=save4;
			tmp[it]=save2;
			tmp[now]=save1;
			dp[now]=save3;
		}
	}
}
void solve(){
	res=-INF;
	scanf("%d",&n);
	rb(i,1,n) each[i].clear(),dp[i]=0;
	rep(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		each[x].PB(y),each[y].PB(x);
	}
	Dfs(1,-1);
//	rb(i,1,n) cout<<tmp[i].FIR<<" - - "<<tmp[i].SEC<<endl;
	change_root(1,-1);
	printf("%d\n",res);
}
int main(){
	int q;
	cin>>q;
	while(q--) solve(); 
	return 0;
}