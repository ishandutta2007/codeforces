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
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
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


int n;
ll T, sum;
string str;
int cnt[26];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> T >> str;
	T += (1LL<<(str[n-2]-'a'));
	T -= (1LL<<(str[n-1]-'a'));
	rep(i, n-2) cnt[str[i]-'a']++;
	rep(i, 26) sum += 1LL * cnt[i] * (1<<i);
	T = abs(T);
	
	if(sum%2 != T%2 || sum < T){
		cout << "No" << endl;
	}
	else{
		ll p = (sum - T) / 2;
		ll lb = p, ub = p;
		
		rep(i, 26){
			ll nlb = max(0LL, lb - cnt[i]);
			ll nub = ub;
			
			lb = (nlb + 1)/2;
			ub = nub / 2;
			if(lb > ub){
			    cout << "No" << endl; return 0;
			}
		}
		if(lb <= 0 && 0 <= ub){
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
}