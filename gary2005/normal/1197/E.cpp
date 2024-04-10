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
int n;//number of segments
mp seg[200000+2];
const int MOD=1e9+7;
pair<LL,LL>/*value , times */ dp[200000+2];
int main(){
	fastio;
	cin>>n;rb(i,1,n) cin>>seg[i].SEC>>seg[i].FIR;
	sort(seg+1,seg+1+n);
	LL add=0;
	map<LL,LL> m;//value+add=real value,times
	set<mp> q;//just like a priority_queue
	rb(i,1,n){
		if(i!=1){
			add+=seg[i].FIR-seg[i-1].FIR;
		}
		while(!q.empty()){
			mp now=*q.begin();
			if(now.FIR<=seg[i].FIR){
				q.erase(q.begin());
				m[dp[now.SEC].FIR-add+seg[i].FIR-now.FIR]+=dp[now.SEC].SEC;
				m[dp[now.SEC].FIR-add+seg[i].FIR-now.FIR]%=MOD;
			}
			else{
				break;
			}
		}
		if(m.begin()==m.end()) {
		dp[i].FIR=seg[i].FIR;
		dp[i].SEC=1ll;
		}
		else{
		
		dp[i].FIR=((*m.begin()).FIR)+add;
		dp[i].SEC=(*m.begin()).SEC;
		}
		q.insert(II(seg[i].SEC,i));
	}
	pair<LL,LL> res=II(INF,0);
	rb(i,1,n)
	{
		if(seg[i].SEC<=seg[n].FIR){
			continue;
		}
		else{
			if(res.FIR>dp[i].FIR){
				res=dp[i];
			}
			else{
				if(res.FIR==dp[i].FIR){
					res.SEC+=dp[i].SEC;
					res.SEC%=MOD;
				}
			}
		}
	}
	cout<<res.SEC<<endl;
	return 0;
}