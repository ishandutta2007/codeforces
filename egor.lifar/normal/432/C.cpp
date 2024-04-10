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
#include <assert.h>


using namespace std;


int n;
int a[100000];
vector<int> v;


bool prosto(int x) {
    for (int i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++) {
        if (prosto(i)) {
            v.push_back(i);
        }
    }
    vector< pair<int, int> > ans;
    for (int g = 0; g < 100; g++) {
        for (int i = 0; i < n; i++) {
            int k = i;
            int j = a[i] - 1;
            while (k < j) {
                int s = distance(v.begin(), upper_bound(v.begin(), v.end(), j - k + 1));
                k += v[s - 1] - 1;
                swap(a[k - v[s - 1] + 1], a[k]);
                ans.push_back(make_pair(k - v[s - 1] + 2, k + 1));
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << ' ' << ans[i].second << endl;
    }
    return 0;
}