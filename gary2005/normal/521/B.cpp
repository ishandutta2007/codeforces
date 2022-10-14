/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
map<mp,int> M;
int m;
const int MAXN=1e5+20;
int x[MAXN],y[MAXN];
vector<int> v[MAXN],up[MAXN];
int oc[MAXN];
set<int> can;
const int MOD=1e9+9;
int stand[MAXN];
void erase(int x){
	can.erase(x);
	for(auto it:up[x]){
		v[it].erase(lower_bound(ALL(v[it]),x));
	}
	if(v[x].size()==1){
		oc[v[x][0]]--;
		if(oc[v[x][0]]==0){
//			cout<<"In"<<v[x][0]<<endl;
			can.insert(v[x][0]);
		}
	}
	for(auto it:v[x]){
		up[it].erase(lower_bound(ALL(up[it]),x));
	}
	for(auto it:up[x]){
		if(v[it].size()==1){
			oc[v[it][0]]++;
			if(can.find(v[it][0])!=can.end())
				can.erase(v[it][0]);
		}
	}
}
int main(){
	scanf("%d",&m);
	rb(i,1,m) scanf("%d%d",&x[i],&y[i]),M[II(x[i],y[i])]=i;
	rb(i,1,m){
		rb(j,-1,1)
			if(M.find(II(x[i]+j,y[i]-1))!=M.end()) v[i].PB(M[II(x[i]+j,y[i]-1)]),up[M[II(x[i]+j,y[i]-1)]].PB(i);
	}
	rb(i,1,m) sort(ALL(v[i])),sort(ALL(up[i]));
	rb(i,1,m) stand[i]=v[i].size();
	rep(i,m) can.insert(i+1);
	rb(i,1,m) if(stand[i]==1){
		oc[v[i][0]]++;
		if(can.find(v[i][0])!=can.end()){
//			cout<<"Er"<<i<<' '<<v[i][0]<<endl;
			can.erase(v[i][0]);
		}
	}
	LL rest=0;
	rb(i,1,m){
		rest=rest*m%MOD;
		int ban;
//		cout<<can.size()<<endl;
		if(i&1){
			auto ite=can.end();
			ban=*(--ite);
		}
		else{
			ban=*can.begin();
		}
//		cout<<i<<' '<<ban<<endl;
		erase(ban);
		rest+=ban-1;
	}
	cout<<rest%MOD<<endl;
	return 0;
}