#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n;
int a[2001][2001];
typedef pair<int,int> pii;
void add(vector<pii>&x,vector<pii>&y){
	for(auto c:y) x.push_back(c);
}
vector<pii>solve(int l,int r){
	vector<pii>e;
	if(l==r) return e;
	int king=l;
	for(int i=l; i<r ;i++) if(a[l][i]) king=i;
	int queen=0;
	for(int i=l+1; i<=king ;i++){
		if(a[i][r]) queen=i;
	}
	if(queen!=0){
		e=solve(l,king);
		auto f=solve(king,r);
		for(auto &c:f){
			if(c.fi==king) c.fi=queen;
			if(c.se==king) c.se=queen;
		}
		add(e,f);
		return e;
	}
	vector<pii>boys;
	boys.push_back({l,king});
	int cur=king+1;
	while(cur<=r){
		int nk=cur;
		for(int i=cur; i<=r ;i++) if(a[cur][i]) nk=i;
		boys.push_back({cur,nk});
		cur=nk+1;
	}
	if(boys.size()==3){
		while(true);
	}/*
	cout << "Boys~!" << endl;
	for(auto c:boys){
		cout << c.fi << ' ' << c.se << ' ';
	}
	cout <<" gilrs" << endl;*/
	for(auto c:boys){
		auto f=solve(c.fi,c.se);
		add(e,f);
	}
	if(boys.size()==2){
		e.push_back({boys[0].fi,boys[1].se});
		return e;
	}
	for(int i=2; i<boys.size() ;i++){
		e.push_back({boys[0].fi,boys[i].fi});
	}
	e.push_back({boys[1].fi,boys.back().se});
	return e;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		for(int j=i; j<=n ;j++){
			char c;cin >> c;
			a[i][j]=c-48;
		}
	}
	auto ans=solve(1,n);
	for(auto c:ans){
		cout << c.fi << ' ' << c.se << '\n';
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}