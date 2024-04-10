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
int n,low[303],high[303],val[404];
vector<int> each[	303];
void err(){
	cout<<"-1\n";
	exit(0);
}
void dfs1(int now,int prev=-1){
	if(val[now]){
		low[now]=high[now]=val[now];
		return ;
	}
	low[now]=INF;
	high[now]=-1;
	for(auto it:each[now]){
		if(it!=prev){
			dfs1(it,now);
			low[now]=min(low[now],low[it]);
		high[now]=max(high[now],high[it]);
		}
		
	}
}
vector<int> ans;
void dfs2(int now,int prev=-1){
	ans.PB(now);
	vector<pair<pair<int,int>,int> > under;
	for(auto it:each[now])
	{
		if(it!=prev){
			under.PB(II(II(low[it],high[it]),it));
		}
	}
	sort(ALL(under));
	int SZ=under.size();
	rep(i,SZ){
//		cout<<now<<" "<<under[i].FIR.FIR<<" "<<under[i].FIR.SEC<<" "<<under[i].SEC<<endl;
		if(i!=SZ-1){
//			cout<<under[i+1].FIR.FIR<<"_"<<unde.r[i+1].SEC<<endl;
			if(under[i].FIR.SEC>=under[i+1].FIR.FIR) err();
		}
	}
	for(auto it:under){ 
		dfs2(it.SEC,now);ans.PB(now);
	}
}
int main(){
	fastio;
	cin>>n;
	rb(i,1,n-1){
		int u,v;
		cin>>u>>v;
		each[u].PB(v);
		each[v].PB(u);
	}
	int cnt=0; 
	rb(i,1,n){
		if(each[i].size()==1&&i!=1){
			cnt++;
		} 
	} 
	rb(i,1,cnt){
		int x;
		cin>>x;
		val[x]=i;
	}
	dfs1(1);
//	rb(i,1,n)
//		cout<<low[i]<<"_"<<high[i]<<'\n';
	dfs2(1);
	for(auto it:ans){
		cout<<it<<" ";
	}cout<<endl;
	return 0;	
}