#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <queue>
#include <list>
#include <cstring>
#include <unordered_map>


using namespace std;


int n, q;
int k;
int t[150201];


int main() {
    cin >> n >> k >> q;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t[i]);
    }
    vector<pair<int, int> > curf;
    for (int i = 0; i < q; i++) {
        int tt;
        scanf("%d", &tt);
        if (tt == 1) {
            int a;
            scanf("%d", &a);
            a--;
            curf.push_back(make_pair(-t[a], a));
            sort(curf.begin(), curf.end());
            if ((int)curf.size() > k) {
                curf.resize(k);
            }
        } else {
            int a;
            scanf("%d", &a);
            a--;
            bool b = 1;
            for (int j = 0; j < (int)curf.size(); j++) {
                if (curf[j].second == a) {
                    b = 0;
                    break;
                }
            }
            if (b) {
                printf("NO\n");
            } else {
                printf("YES\n");
            }
        }
    }
    return 0;
}