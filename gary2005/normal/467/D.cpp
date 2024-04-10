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
int Cnt;
map<string,int> M;
int m,n;
mp cost[300000+20];
pair<LL,LL> res;
int a[100000+20],vis[300000+20];
vector<int> each[300000+20];
int get(string s){
	rep(i,s.length()){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i]-='A';
			s[i]+='a';
		}
	}
	if(M.find(s)==M.end()){
		return M[s]=++Cnt;
	}
	else{
		return M[s];
	}
}
mp calc(string s){
	mp Res=II(0,s.length());
	rep(i,s.length()){
		Res.FIR+=bool(s[i]=='r');
	}
	return Res;
}
vector<pair<mp,int> >  q;
void dfs(int now,mp val){
	vis[now]=1;
	cost[now]=val;
	for(auto it:each[now]){
		if(!vis[it]){
			dfs(it,val);
		}
	}
}
int main(){
	fastio;
	cin>>m;
	rb(i,1,m)
	{
		string s;
		cin>>s;
		a[i]=get(s);
	}
	int n;
	cin>>n;
	rb(i,1,n){
		string u,v;
		cin>>u>>v;
		each[get(v)].PB(get(u));
	}
	for(map<string,int> :: IT ite=M.begin();ite!=M.end();ite++){
		cost[ite->SEC]=calc(ite->FIR);
		q.PB(II(cost[ite->SEC],ite->SEC));
	}
	sort(ALL(q));
	for(auto it:q){
		if(!vis[it.SEC]){
			dfs(it.SEC,it.FIR);
		}
	}
	rb(i,1,m){
		res.FIR+=cost[a[i]].FIR;
		res.SEC+=cost[a[i]].SEC;
	}
//	cout<<cost[3].FIR<<" "<<cost[3].SEC<<endl;
	cout<<res.FIR<<" "<<res.SEC<<endl;
	return 0;
}