//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
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

#define si(x) int(x.size())
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}

template<class t> using vc=vector<t>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
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
string str[10]={
"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
bool dp[2005][2005];
int contain[10][2005];
void solve(){
	int n, k; cin >> n >> k;
	vc<string>vec(n);
	rep(ii, n){
		cin>>vec[ii];
		rep(i, 10){
			{
				rep(k, 7){
					if(str[i][k] == '0' && vec[ii][k] == '1'){
						contain[i][ii] = -1; goto nxt;
					}
					else if(str[i][k] == '1' && vec[ii][k] == '0') contain[i][ii] ++;
				}
				nxt:;
			}
		}
	}
	dp[n][0] = 1;
	for(int i=n-1;i>=0;i--){
		rep(j, k+1){
			if(dp[i+1][j] == false) continue;
			rep(a, 10){
				if(contain[a][i] >= 0 && j + contain[a][i] <= k){
					dp[i][j + contain[a][i]] = 1;
				}
			}
		}
	}
	if(dp[0][k] == 0){
		cout << -1 << endl;
		return;
	}
	rep(i, n){
		for(int j=9;j>=0;j--){
			if(contain[j][i] == -1) continue;
			if(k < contain[j][i]) continue;
			if(dp[i+1][k-contain[j][i]] == false) continue;
			
			k -= contain[j][i];
			cout << j;
			break;
		}
	}
	assert(k == 0);
	cout << endl;
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1;//cin >> t;
	while(t--) solve();
}