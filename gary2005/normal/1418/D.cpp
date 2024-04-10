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
int cnt=0;
multiset<int> li;
set<int> s;
set<int> :: IT ite1;
int q(){
	if(cnt<=2){
		return 0;
	} 
	int l,r;
	l=*s.begin();
	ite1=s.end();
	ite1--;
	r=*ite1;
	return r-l+(*li.begin());
}
int las(int x){
	if(s.lower_bound(x)==s.begin()){
		return -1;
	} 
	ite1=s.lower_bound(x);
	ite1--;
	return *ite1;
}
int nex(int x){
	if(s.upper_bound(x)==s.end()) return -1;
	return *(s.upper_bound(x));
}
int main(){
	fastio;
	int n,Q;
	R2(n,Q);
	rb(i,1,n){
		int x;
		R(x);
		s.insert(x);
	}
	int last=-1;
	for(set<int>:: IT ite=s.begin();ite!=s.end();ite++){
		if(last!=-1) li.insert(last-*ite);
		last=*ite;
	}
	cnt=n;
	cout<<q()<<endl;
	while(Q--){
		bool ty;
		R(ty);
		int x;
		R(x);
		if(ty==1){
			cnt++;
			int ll,nn;
			ll=las(x);
			nn=nex(x);
			if(ll>0&&nn>0){
				li.erase(li.lower_bound(ll-nn));
			}
			if(ll>0){
				li.insert(ll-x);
			}
			if(nn>0){
				li.insert(x-nn);
			}
			s.insert(x);
		} 
		else{
			cnt--;
			int ll,nn;
			ll=las(x);
			nn=nex(x);
			if(ll>0&&nn>0){
				li.insert(ll-nn);
			}
			if(ll>0){
				li.erase(li.lower_bound(ll-x));
			}
			if(nn>0){
				li.erase(li.lower_bound(x-nn));
			}
			s.erase(x);
			
		}
		cout<<q()<<endl;
	}
	return 0;
}