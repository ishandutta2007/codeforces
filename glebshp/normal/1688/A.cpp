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

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int tnum;
    cin >> tnum;
    for (int tc = 0; tc < tnum; tc++) {
        unsigned int mask;
        cin >> mask;
        for (int i = 0; i <= 30; i++) {
            if ((mask & (1u << i)) > 0) {
                unsigned int ans = 1u << i;
                if ((mask ^ ans) == 0) {
                    if (i == 0) {
                        ans |= 2u;
                    } else {
                        ans |= 1u;
                    }
                }

                cout << ans << endl;
                break;
            }
        }

    }

    return 0;
}