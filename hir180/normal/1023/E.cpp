#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

const ll mod = 1000000007;

int n;
bool ask(int a,int b,int c,int d){
	cout << "? " << a << " " << b << " " << c << " " << d << endl;
	string s; cin >> s;
	return s == "YES";
}
P go(int x,int y,string &s){
	if(x+y == n+1) return P(x,y);
	
	if(x+y < n+1){
		if(y < n){
			bool flag = ask(x,y+1,n,n);
			if(flag){
				s.pb('R');
				return go(x,y+1,s);
			}
		}
		{
			s.pb('D');
			return go(x+1,y,s);
		}
	}
	else{
		if(x > 1){
			bool flag = ask(1,1,x-1,y);
			if(flag){
				s.pb('D');
				return go(x-1,y,s);
			}
		}
		{
			s.pb('R');
			return go(x,y-1,s);
		}
	}
}
int main(){
	cin >> n;
	string L = "", R = "";
	P p = go(1,1,L);
	P q = go(n,n,R);
	assert(p == q);
	reverse(R.begin(),R.end());
	L += R;
	cout << "! " << L << endl;
}