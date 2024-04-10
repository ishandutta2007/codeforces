#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <bitset>


using namespace std;


int n;
long long v[4001], d[4001], p[4001];
bool ubej[4001];

               
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> d[i] >> p[i];
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (p[i] >= 0LL) {
            ans.push_back(i);
            long long s = v[i];
            long long sum = 0;
            for (int j = i + 1; j < n; j++) {
                if (p[j] >= 0LL) {
                    p[j] -= s;
                    s--;
                    s = max(s, 0LL);
                }
                p[j] -= sum;
                if (!ubej[j]) {
                    if (p[j] < 0) {
                        ubej[j] = true;
                        sum += d[j];
                    }
                }
            }
        }
    }
    cout << (int)ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << endl;
    return 0;   
}