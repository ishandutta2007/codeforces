#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <cmath>

using namespace std;


int n, d, k;


int main() {
    cin >> n >> k >> d;
    if (k >= n) {
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < n; j++) {
                cout << j + 1 << ' ';
            }
            cout << endl;
        }
        return 0;
    }
    long long ans = 1;
    bool b = false;
    for (int j = 0; j < d; j++) {
    	ans *= 1LL * k;
    	if (ans >= n) {
    		b = true;
    		break;
    	}
    }
    if (!b) {
    	cout << -1 << endl;
    	return 0;
    }
    ans = 1;
    for (int i = 0; i < d; i++) {
        int s = 0;
        int t = 1;
        for (int j = 0; j < n; j++) {
        	s++;
        	if (s > ans) {
        		t++;
        		s = 1;
        	}
        	if (t > k) {
        		t = 1;
        	}
        	printf("%d\n", t);
        }
        ans *= k;
        if (ans > 10000LL) {
        	ans = 10000LL;
        }
    }
}