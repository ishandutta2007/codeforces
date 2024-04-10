#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


#define M 1000000007


int p, k;
bool used[1000001];


int pow(int a, int x) {
    if (x == 1) {
        return a;
    } else {
        if (x % 2 == 0) {
            int g = pow(a, x / 2);
            return (1LL * g * g) % p;
        } else {
            return (1LL * a * pow(a, x - 1)) % p;
        }
    } 
}


int main() {
    cin >> p >> k;
    if (k == 0) {
        int ans = 1;
        for (int i = 0; i < p - 1; i++) {
            ans = (1LL * ans * p) % M;
        }
        cout << ans << endl;
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < p; i++) {
        if (!used[i]) {
            int j = i;
           // cout << i << endl;
            int cnt = 0;
            while (!used[j]) {
                cnt++;
                used[j] = true;
                j = (1LL * j * k) % p;
                //cout << j << endl;
            }
            int h = pow(k, cnt);
            //cout << cnt << endl;
            if ((h - 1 + p) % p == 0) {
                ans = (1LL * ans * p) % M;
            }
            //cout << i << endl;
        }
    }
    cout << ans << endl;
    return 0; 
}