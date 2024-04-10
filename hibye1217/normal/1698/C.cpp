#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 9
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define mkp make_pair
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );
template <typename T> using priority_stack = priority_queue< T, vector<T>, greater<T> >;

inline int sgn(int x){ return (x > 0) - (x < 0); }

vector<int> v[2];

void Main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n; int zer = 0;
		while (n--){
			int x; cin >> x;
			if (x == 0){ zer += 1; }
			else{ v[(sgn(x)+1)/2].push_back(x); }
		}
		zer = min(zer, 3);
		vector<int> res;
		for (int x : v[0]){ res.push_back(x); }
		for (int x : v[1]){ res.push_back(x); }
		while (zer--){ res.push_back(0); }
		int len = res.size();
		if (len > 10){ cout << "NO" << endl; }
		else{
			set<int> s;
			for (int x : res){ s.insert(x); }
			bool ans = 1;
			for (int i = 0; i < len; i++){
				for (int j = i+1; j < len; j++){
					for (int k = j+1; k < len; k++){
						ans &= s.count(res[i]+res[j]+res[k]);
					}
				}
			}
			cout << (ans ? "YES" : "NO") << endl;
		}
		v[0].clear(); v[1].clear();
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed); cout.precision(PRECISION);
	Main();
}