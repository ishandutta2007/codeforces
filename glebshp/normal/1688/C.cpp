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

int par[26];

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        int n;
        cin >> n;
        for (int i = 0; i < 26; i++) {
            par[i] = 0;
        }
        for (int i = 0; i <= 2 * n; i++) {
            string str;
            cin >> str;
            for (char c : str) {
                par[int(c - 'a')] ^= 1;
            }
        }
        for (int i = 0; i < 26; i++) {
            if (par[i] == 1) {
                cout << char('a' + i) << endl;
                break;
            }
        }
    }

    return 0;
}