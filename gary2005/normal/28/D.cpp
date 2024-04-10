/*
AuThOr Gwj
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
#define rep(a,b) for(int a=0;a<b;++a)
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define auto ABCDEFgHIjk
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e5+20;
map<mp,int> M;/*li+ci -- ri*/
int dp[MAXN],n,back[MAXN];
#define v SEC.FIR.FIR
#define c SEC.FIR.SEC
#define l SEC.SEC.FIR
#define r SEC.SEC.SEC
#define id FIR
pair<int,pair<mp,mp> > monkey[MAXN];
bool cmp(pair<int,pair<mp,mp> > A,pair<int,pair<mp,mp> > B){
	return A.l<B.l;
}
int main(){
	fastio;
	R(n);
	rb(i,1,n){
		R2(monkey[i].v,monkey[i].c);
		R2(monkey[i].l,monkey[i].r);
		monkey[i].id=i;
	}
	rb(i,1,n){
		if(monkey[i].l==0){
			dp[i]=monkey[i].v;
			if(dp[i]>dp[M[II(monkey[i].l+monkey[i].c,monkey[i].r)]]){
				        M[II(monkey[i].l+monkey[i].c,monkey[i].r)]=i;
			}
		}
		else{
			if(M[II(monkey[i].l,monkey[i].r+monkey[i].c)]){
      dp[i]=dp[M[II(monkey[i].l,monkey[i].r+monkey[i].c)]]+monkey[i].v;
	   back[i]=M[II(monkey[i].l,monkey[i].r+monkey[i].c)];
			if(dp[i]>dp[M[II(monkey[i].l+monkey[i].c,monkey[i].r)]]){
				M[II(monkey[i].l+monkey[i].c,monkey[i].r)]=i;
			}
			}
		}
	}
	int pos=0;
	rb(i,1,n){
		if(monkey[i].r==0){
			if(dp[i]>dp[pos]) pos=i;
		}
	}
	vector<int> res;
	while(pos){
		res.PB(pos);
		pos=back[pos];
	}
	reverse(ALL(res));
	cout<<res.size()<<endl;
	rep(i,res.size()){
		cout<<monkey[res[i]].id<<" ";
	}
	cout<<endl;
	return 0;
}
/*
5 
1 1 0 3
1 1 1 2
1 1 2 1
1 1 3 0
2 1 3 0

5
1 1 0 3
10 1 2 1
2 2 1 1
10 1 1 2
3 1 3 0
*/