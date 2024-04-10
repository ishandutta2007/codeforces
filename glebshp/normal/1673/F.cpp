#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const int lsize = 10;
int n, k;

int getEncoding(int x, int par) {
    for (int i = 0; i < lsize; i++) {
        if (!((x >> i) & 1)) {
            return (1 << (i * 2 + par));
        }
    }

    return 0;
}

int decode(int x, int par) {
    vector <int> secs;
    for (int i = 0; i < lsize * 2; i++) {
        if (i % 2 == par) {
            secs.pb((x >> i) & 1);
        }
    }

    int res = 0;
    int sum = 0;
    for (int i = (int) secs.size() - 2; i >= 0; i--) {
        sum += secs[i];
        if (sum % 2 == 1) {
            res += (1 << i);
        }
    }

    return res;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << getEncoding(j, 0) << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            cout << getEncoding(i, 1) << ' ';
        }
        cout << endl;
    }
    cout.flush();
    
    int curpos = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        curpos ^= x;
        cout << decode(curpos, 1) + 1 << ' ' << decode(curpos, 0) + 1 << endl;
        cout.flush();
    }
    
    return 0;
}