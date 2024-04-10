#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

	
int hass[256], hast[256];

int main(){
	ios::sync_with_stdio(0);
	string s, t;
	cin >> s >> t;
	rep(i,0,sz(s)){
		hass[s[i]]++;
	}
	rep(i,0,sz(t)){
		hast[t[i]]++;
	}
	ll lo = 0, hi = 10000000;
	while(hi-lo > 1){
		ll mid = (lo+hi)/2;
		ll needed = 0;
		rep(i,0,256){
			needed += max(0LL, hast[i]*mid-hass[i]);
		}
		if(needed > hass['?'])
			hi = mid;
		else
			lo = mid;
	}
	vector<int> put;
	rep(i,0,256){
		rep(j,0,(int)(hast[i]*lo-hass[i]))
			put.push_back(i);
	}
	rep(i,0,sz(s)){
		if(s[i] != '?')
			continue;
		if(put.empty()){
			s[i] = 'x';
			continue;
		}
		s[i] = put.back();
		put.pop_back();
	}
	cout << s << endl;
}