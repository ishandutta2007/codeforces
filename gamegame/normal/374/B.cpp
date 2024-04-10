#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll n,m,k;
ll x,y,z;
ll a[1000001],b[1000001];
string s,t;
bool can[1001];
int w[222];
bool check(string& v,int u,int x){
	int g=0;
	for(auto c:v){
		if(w[c]>=u) return false;
		g=g*u+w[c];
	}
	return g<x;
}
int ff(string t){
	if(t[0]==t.back() && t.size()>=2) return (t.size()+1)/2;
	else return 1;
}
void solve(){
	string s;
	cin >> s;
	string t;
	ll ans=1;
	for(auto c:s){
		if(!t.empty() && t.back()+c-48-48!=9){
			ans=ans*ff(t);
			t="";
		}
		t+=c;
	}
	ans=ans*ff(t);
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	for(int i=0; i<10 ;i++) w[i+'0']=i;
	for(int i=10; i<36 ;i++) w[i+'A'-10]=i;
	solve();
}