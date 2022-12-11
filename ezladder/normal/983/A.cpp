#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
            
using namespace std;
            
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

ll gcd(ll a, ll b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){	
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
    	ll a, b, c;
    	cin >> a >> b >> c;
    	if (a == 0){
    		cout << "Finite\n";
    		continue;
    	}
    	ll cc = gcd(a, b);
    	b /= cc;
    	while(1){
    		ll ff = gcd(b, c);
    		if (ff == 1) break;
    		while(b % ff == 0) b /= ff;
    	}
    	if (b == 1) cout << "Finite\n";
    	else cout << "Infinite\n";
    }
}