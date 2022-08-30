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

int n, m, aa[1005][1005], bb[1005][1005];
string str;
void solve(){
	cin>>n>>m;
	rep(i,n)rep(j,n){
		cin >> aa[i][j];
		aa[i][j]--;
	}
	cin >> str;
	int x=0,y=0,val=0,cur=0;
	int a = 0, b = 1, c = 2;
	rep(i, m){
		if(str[i] == 'R'){
			y++;
		}
		if(str[i] == 'L'){
			y--;
		}
		if(str[i] == 'D'){
			x++;
		}
		if(str[i] == 'U'){
			x--;
		}
		if(str[i] == 'I'){
			swap(y, val); cur ^= 1; swap(b, c);
		}
		if(str[i] == 'C'){
			swap(x, val); cur ^= 2; swap(a, c);
		}
	}
	x = (x%n+n)%n;
	y = (y%n+n)%n;
	val = (val%n+n)%n;
	rep(i, n){
		rep(j, n){
			vector<int>vi({i, j, aa[i][j]});
			int x = vi[a];
			int y = vi[b];
			int z = vi[c];
			bb[x][y] = z;
		}
	}
	rep(i, n){
		rep(j, n){
			cout << 1+(bb[(i+n-x)%n][(j+n-y)%n]+2*n+val)%n << ' ';
		}
		cout<<'\n';
	}
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while(t--) solve();
}
/*
2 3 1 
3 1 2 
1 2 3 

3 1 2 
1 2 3 
2 3 1 

1 2 3 
3 1 2 
2 3 1 

1 3 2 
2 1 3 
3 2 1 

2 3 1 
3 1 2 
1 2 3
*/