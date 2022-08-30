//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
template<class T> using vc = vector<T>;
template<class T>
void dmp(T a){
	rep(i,a.size()) cout << a[i] << " ";
	cout << endl;
}
template<class T>
bool chmax(T&a, T b){
	if(a < b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
bool chmin(T&a, T b){
	if(a > b){
		a = b;
		return 1;
	}
	return 0;
}
template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 1000000007;//998244353
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
int n, a[100005], c[100005];
string b;

string solve(vector<int>v){
	int n = v.size();
	string str = "";
	rep(i, n-1) str.pb('+');
	vector<P>pos;
	ll M = 1;
	rep(i, v.size()){
		if(v[i] > 1) {
			pos.eb(v[i], i);
			M = M * v[i];
			chmin(M, (ll)(1000007));
		}
	}
	if(M >= 1000000){
		if(pos.size() >= 2){
			int beg = pos[0].b;
			int en = pos.back().b;
			for(int i=beg;i<en;i++) str[i] = '*';
		}
	}
	else{
		int dp[22] = {}, pre[22] = {};
		
		rep(i, pos.size()){
			dp[i+1] = 1;
			for(int j=0;j<=i;j++){
				dp[i+1] *= pos[j].a;
			}
			pre[i+1] = 0;
		}
		for(int i=1;i<=pos.size();i++){
			int add = pos[i].b - pos[i-1].b - 1;
			int zan = 1;
			for(int j=i;j<pos.size();j++){
				zan = zan * pos[j].a;
				if(dp[j+1] < dp[i] + add + zan){
					dp[j+1] = dp[i] + add + zan;
					pre[j+1] = i;
				}
			}
		}
		int cur = pos.size();
		while(cur != 0){
			int zen = pre[cur];
			int beg = pos[zen].b;
			int en = pos[cur-1].b;
			for(int i=beg;i<en;i++) str[i] = '*';
			cur = zen;
		}
	}
	return str;
}
int main(){
	cin >> n;
	repn(i, n) cin >> a[i];
	cin >> b;
	if(b.size() == 1){
		repn(i, n){
			cout << a[i];
			if(i != n) cout << b[0] ;
		}
		cout << endl;
	}
	else if(b == "-+" || b == "+-"){
		repn(i, n){
			cout << a[i];
			if(i != n) cout << '+' ;
		}
		cout << endl;
	}
	else if(b == "-*" || b == "*-"){
		int en = n+1;
		repn(i, n) if(a[i] == 0){
			en = i; break;
		}
		repn(i, n){
			cout << a[i];
			if(i != n){
				if(i+1 == en) cout << '-';
				else cout << '*';
			}
			else cout << endl;
		}
	}
	else{
		string ans = "";
		rep(i, n-1) ans.pb('+');
		
		repn(i, n){
			if(a[i] == 0);
			else{
				int j = i;
				while(a[j] > 0 && j <= n) j++;
				//[i, j)
				vc<int>v;
				for(int k=i;k<j;k++) v.pb(a[k]);
				auto op = solve(v);
				assert(op.size() == j-i-1);
				for(int x=i-1;x<j-2;x++) ans[x] = op[x+1-i];
				i = j-1;
			}
		}
		
		repn(i, n){
			cout << a[i];
			if(i != n){
				cout << ans[i-1];
			}
			else cout << endl;
		}
	}
}