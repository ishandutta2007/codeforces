#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	ll x;
    	cin >> x;
    	if (x < 1200) {
    	  cout << 1200;
    	} else {
    	  if (x < 1400) {
    	    cout << 1400;
    	  } else {
    	    if (x < 1600) {
    	      cout << 1600;
    	    } else {
    	      if (x < 1900) {
    	        cout << 1900;
    	      } else {
    	        if (x < 2100) {
    	          cout << 2100;
    	        } else {
    	          if (x < 2300) {
    	            cout << 2300;
    	          } else {
    	            if (x < 2400) {
    	              cout << 2400;
    	            } else {
    	              if (x < 2600) {
    	                cout << 2600;
    	              } else {
    	                cout << 3000;
    	              }
    	            }
    	          }
    	        }
    	      }
    	    }
    	  }
    	}
}