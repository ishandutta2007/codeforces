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


#define M 1000000007


int n, k;
int last[26];
int cnt[26];


int main() {
    cin >> n >> k;
    string s;
    cin >> s;
    int m = (int)s.size();
    for (int i = 0; i < m; i++) {
        last[s[i] - 'a'] = i + 1;
    }
    vector<pair<int, int> > v;
    for (int i = 0; i < k; i++) {
        v.push_back(make_pair(last[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        s += char('a' + v[i % k].second);
    }
    n = (int)s.size();
    for (int i = 0; i < n; i++) {
        int sum = 1;
        for (int j = 0; j < k; j++) {
            sum = (sum + cnt[j]) % M;
        }
        cnt[s[i] - 'a'] = sum;
    }
    int sum = 1;
    for (int j = 0; j < k; j++) {
        sum = (sum + cnt[j]) % M;
    }
    cout << sum << endl;
    return 0;   
}