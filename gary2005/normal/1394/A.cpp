/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,d,m;
vector<int> a1,a2;
int sum[100000+20],sum2[100000+20];
signed main(){
	fastio;
	R2(n,d);
	R(m);
	rb(i,1,n){
		int ai;
		R(ai);
		if(ai<=m){
			a1.PB(ai);
		}
		else{
			a2.PB(ai);
		}
	}
	sort(ALL(a1));
	reverse(ALL(a1));
	sort(ALL(a2));
	reverse(ALL(a2));
	rep(i,a1.size()){
		sum[i+1]=sum[i]+a1[i];
	}
	rep(i,a2.size()){
		sum2[i+1]=sum2[i]+a2[i];
	}
	if(a2.empty()){
		cout<<sum[n]<<endl;
		return 0;
	}
	int res=0;rep(i,a2.size()+1){
		if(!i) continue;
		int cover=0;
		cover=(i-1)*d+i;
		if(cover>n){
			continue;
		}
//		cout<<i<<" "<<cover<<" "<<sum[min(n-cover,(int)a1.size())]<<" "<<sum2[i+1]<<endl;
		res=max(res,sum[min(n-cover,(int)a1.size())]+sum2[i]);
	}
	cout<<res<<endl;
	return 0;
}