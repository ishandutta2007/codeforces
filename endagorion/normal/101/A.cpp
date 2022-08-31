#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

bool cmp(pair< int, int > &a, pair< int, int > &b) {
    return a.second < b.second;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector< pair< int, int > > lets(26);
    for (int i = 0; i < 26; ++i) {
        lets[i].second = i;
        lets[i].first = 0;
    }
    for (size_t i = 0; i < s.length(); ++i) {
        ++lets[s[i] - 'a'].first;
    }
    sort(lets.begin(), lets.end());
    int diff = 26;
    for (int i = 0; i < 26; ++i) {
        if (lets[i].first <= k) {
            --diff;
            k -= lets[i].first;
            lets[i].first = 0;
        } else {
            lets[i].first -= k;
            k = 0;
        }
    }
    sort(lets.begin(), lets.end(), cmp);
    cout << diff << '\n';
    for (size_t i = 0; i < s.length(); ++i) {
        if (lets[s[i] - 'a'].first > 0) {
            cout << s[i];
            --lets[s[i] - 'a'].first;
        }
    }
    cout << '\n';

    return 0;
}