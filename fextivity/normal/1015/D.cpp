#include<bits/stdc++.h>
using namespace std;
#define ll   long long
#define ld   long double
#define ull  unsigned long long
#define fi   first
#define se   second
#define pb   push_back
#define pob  pop_back
#define mp   make_pair
#define pque priority_queue
#define endl '\n'
typedef vector <int> 	vi;
typedef vector <ll>		vll;
typedef pair <int, int> ii;
typedef pair <int, int> llll;
typedef vector <vi > 	vvi;
typedef vector <vll > 	vvll;
typedef vector <ii > 	vii;
typedef vector <llll > 	vllll;

const ll N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18;

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	ll n, k, s, idx = 0;
	cin >> n >> k >> s;
	if (s > (n - 1) * k || s < k){
	    cout << "NO\n";
	    return 0;
	}
	cout << "YES\n";
	if (k == 1){
	    cout << 1 + s;
	    return 0;
	}
	if (k == 2){
	    if (s <= n){
	        cout << s << ' ' << s - 1;
	    }
	    else{
	        cout << n << ' ' << n - 1 - (s - n);
	    }
	    return 0;
	}
	vll ans(k);
	ll num = s / k, ck = 1, t;
	for (int i = 0; i < k; i++){
	    if (ck == 1){
	        ans[idx] = 1 + num;
	        ck = 0;
	    }
	    else{
	        ans[idx] = 1;
	        ck = 1;
	    }
	    idx++;
	}
	s -= num * k;
	if (s != 0){
	    for (int i = 0; i < k - 1; i += 2){
	        t = (s >> 1);
	        if (n - ans[i] >= t){
	            ans[i] += t;
	            s -= t * 2;
	        }
	        else{
	            s -= (n - ans[i]) * 2;
	            ans[i] = n;
	        }
	    }
	    if ((s & 1)){
	        if (ans[k - 1] == 1){
	            ans[k - 2]++;
	        }
	        ans[k - 1]++;
	        s--;
	    }
	}
	//cout << s << endl;
	for (int i = 0; i < k; i++){
	    cout << ans[i] << ' ';
	}
}