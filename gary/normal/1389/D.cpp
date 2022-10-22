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
int n,k,l1,r1,l2,r2;
int check(int L1,int R1,int L2,int R2){
	if(R1<L2){
		return 0;
	}
	return min(R1,R2)-max(L1,L2);
}
void solve(){
	R2(n,k);
	R2(l1,r1);
	R2(l2,r2);
	if(l1>l2){
		swap(l1,l2);
		swap(r1,r2);
	}
	int reach=0;
	if(r1<l2){
		reach=l2-r1;
	}
	LL sa;
	LL init=sa=check(l1,r1,l2,r2);
	init*=n;
	k-=init;
	if(k<=0){
		cout<<0<<endl;
		return ;
	}
	int maxi=max(r1,r2)-min(l1,l2)-sa;
	LL res=0;
	LL tmp=1000000000000000;
	rb(i,1,n){
		res+=reach;
		if(maxi>=k){
			res+=k;
			k=0;
			break;
		}
	else{
		res+=maxi;
		k-=maxi;
		tmp=min(tmp,res+2*k);
	}
	}
	if(k>0){
		cout<<tmp<<endl;
	}
	else
	cout<<min(res,tmp)<<endl; 
}
signed main(){
	fastio;
	int t;
	cin>>t;
	while(t--) {solve();	}
	return 0;
}