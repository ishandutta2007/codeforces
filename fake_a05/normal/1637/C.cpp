#include "bits/stdc++.h"

using namespace std;

#define fori(i, a, b) for(int i = (int) (a); i <= (int) (b); ++i)
#define ford(i, a, b) for(int i = (int) (a); i >= (int) (b); --i)
#define forIT(it, begin, end) for(__typeof(end) it = (begin) + ((begin) > (end)); it != (end) - ((begin) > (end)); it += 1 - 2 * ((begin) > (end)))

#define fi first
#define se second
#define b_e(x) begin(x), end(x)
#define ii pair<int, int>
#define vi vector<int> 
#define vvi vector<vi>

#define pb push_back
#define pf push_front
#define eb emplace_back
#define em emplace
#define ob pop_back
#define om pop
#define of pop_front

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rand rng
#define endl '\n'
#define sp ' '

void solve();

int32_t main() {
// freopen("test.inp","r",stdin);
// freopen("test.out","w",stdout);
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   int test_num = 1;
   cin >> test_num; 
   fori(test, 1, test_num) {
      solve();
   }
   return 0;
}

#define ld long double
#define int long long
const ld pi = 4 * atan(1.0), eps = 1e-9;
const int maxn = 2e5 + 5; 
int n; 
int arr[maxn]; 
void solve() {
	cin >> n; 
	int cntodd = 0, cnteven = 0, mxodd = 0, mxeven = 0; 
	fori(i,1, n) { 
		cin>> arr[i]; 
	}
	fori(i, 2, n - 1) {
		if(arr[i] & 1) cntodd++, mxodd = max(mxodd, arr[i]); 
		else cnteven++, mxeven = max(mxeven, arr[i]); 	
	}
	int sum = 0; fori(i, 2, n - 1) sum += (arr[i] + 1) / 2; 
	if(!cntodd) { 
		cout << sum << endl; 
	}
	else { 
		if(mxeven > 0) cout << sum << endl; 
		else { 
			if(cntodd == 1) { 
				if(mxodd > 3 and n >= 4) cout << 3 + (mxodd - 3) / 2 << endl; 
				else cout << -1 << endl; 
			}
			else { 
				if(mxodd > 1) cout << sum << endl; 
				else cout << -1 << endl; 
			}
		}
	}
}