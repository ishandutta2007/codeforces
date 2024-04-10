#include <bits/stdc++.h>

using namespace std;

int n, a, b, k, f, ans;
string from[330], to[330];

map<pair<string, string> , int> cost;

int main() {
    scanf("%d %d %d %d %d", &n, &a, &b, &k, &f);

    for(int i = 0; i < n; i++) {
        cin >> from[i] >> to[i];

        int c = a;
        if(i && from[i] == to[i-1]) c = b;
        cost[{min(from[i], to[i]), max(from[i], to[i])}] += c;
    }

    vector<int> v;
    for(auto pssi : cost) {
        v.push_back(pssi.second);
    } sort(v.begin(), v.end());

    while(!v.empty() && k && f < v.back()) {
        ans += f;
        k--;
        v.pop_back();
    }

    while(!v.empty()) {
        ans += v.back();
        v.pop_back();
    }

    printf("%d\n", ans);
    return 0;
}