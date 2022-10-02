#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>

using namespace std;

int n, k, l, r, sa, sk, a[1000];

int main() {
    cin >> n >> k >> l >> r >> sa >> sk;
    for (int i = 0; i < n; i++) {
        a[i] = l;
    }
    int sn = sa - sk;
    sn -= l * (n - k);
    if(sn != 0){
        for (int i = 0; i < sn / (n - k); i++) {
            for (int j = k; j < n; j++) {
                a[j]++;
            }
        }
    }
    for (int i = k; i < k + sn % (n - k); i++) {
        a[i]++;
    }
    sk -= k * l;
    if(k != 0){
        for (int i = 0; i < sk / k; i++) { 
            for (int j = 0; j < k; j++) {
                a[j]++;
            }
        }
    }
    for (int i = 0; i < sk % k; i++) {
        a[i]++;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' '; 
    }
    cout << endl;
	return 0;
}