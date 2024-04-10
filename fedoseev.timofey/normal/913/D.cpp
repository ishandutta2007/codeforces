#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

bool cmp(const pair<pair <int, int>, int> &f, const pair< pair <int, int>, int> &s) {
    if (f.first.second != s.first.second) {
        return f.first.second < s.first.second;
    }
    else if (f.first.first != s.first.first){
        return f.first.first >= s.first.first;
    }
    else {
        return f.second < s.second;
    }
}

vector <pair <pair <int, int>, int>> problems;

int n, T;

bool check(int x) {
    int time = T;
    int t = x;
    for (int i = 0; i < n; ++i) {
        if (problems[i].first.first >= x && problems[i].first.second <= time && t > 0) {
            time -= problems[i].first.second;
            --t;
        }
    }
    return t == 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> T;
    problems.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> problems[i].first.first >> problems[i].first.second;
        problems[i].second = i;
    }
    sort(problems.begin(), problems.end(), cmp);
    int l = 0;
    int r = n + 1;
    while (l + 1 != r) {
        int m = (l + r) >> 1;
        if (check(m)) l = m;
        else r = m;
    }
    vector <int> ans;
    int t = l;
    int time = T;
    for (int i = 0; i < n; ++i) {
        if (problems[i].first.first >= l && problems[i].first.second <= time && t > 0) {
            time -= problems[i].first.second;
            --t;
            ans.push_back(problems[i].second + 1);
        }
    }
    cout << l << endl << l << endl;
    for (auto i : ans) {
        cout << i << " ";
    }
    return 0;
}