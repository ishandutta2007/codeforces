#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <fstream>
#include <queue>
#include <cmath>
#include <algorithm>
 
using namespace std;
#define int long long

const int INF = 1e10 + 7;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x, d;
    cin >> x >> d;

    int curr = 1;
    vector <int> ans;
    while (x) {
        for (int len = 31; len >= 1; --len) {
            int can = ((1LL << len) - 1); 
            if (can <= x) {
                for (int i = 0; i < len; ++i) {
                    ans.push_back(curr);
                }
                x -= can;
                curr += INF;
                break;
            }
        }
    }

    cout << ans.size() << '\n';
    for (int elem : ans) cout << elem << ' ';
    cout << '\n';

    return 0;
}