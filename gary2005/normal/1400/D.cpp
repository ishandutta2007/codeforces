/*
{By GWj
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=3003;
int bit[MAXN+10]={0};
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=i&(-i);
	}
	return s;
}
void add(int i,int x=1){
	while(i<=MAXN){
		bit[i]+=x;
		i+=i&(-i);	
	}
}
int a[MAXN];
bool cmp(mp A,mp B){
	return A.SEC>B.SEC;
}
void solve(){
	int n;
	memset(bit,0,sizeof(bit));
	R(n);
	vector<mp> pp;
	rb(i,1,n){
		R(a[i]);
	}
	rb(i,1,n){
		rb(j,i+1,n){
			if(a[i]==a[j]) pp.PB(II(i,j));
		}
	}
	sort(ALL(pp),cmp);
	LL rest=0;
	int las=-1;
	vector<int> ssss;
	for(auto it:pp){
		if(it.SEC!=las){
			las=it.SEC;
			for(auto it:ssss){
				add(it);
			}
			ssss.clear();
			ssss.PB(it.FIR);
		}
		else{
			ssss.PB(it.FIR);	
		}
		rest+=sum(it.SEC-1)-sum(it.FIR);
	} 
	cout<<rest<<endl;
}
int main(){
	fastio;
	int t;
	R(t);
	while(t--) solve();
	return 0;
}