#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define a first
#define b second
const int N = 3e5 + 7;
ii d[N];
vector <int> v[2];
bool comp1(int i, int j) {
    return d[i].a > d[j].a;
}   
bool comp2(int i, int j) {
    return d[i].b < d[j].b;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i].a >> d[i].b;
        if (d[i].a < d[i].b) v[0].push_back(i);
        else v[1].push_back(i);
    }   
    sort(v[0].begin(), v[0].end(), comp1);
    sort(v[1].begin(), v[1].end(), comp2);
    if (v[0].size() > v[1].size()) {
        cout << v[0].size() << '\n';
        for (int e : v[0]) cout << e + 1 << ' ';
        cout << '\n';
    }   
    else {
        cout << v[1].size() << '\n';
        for (int e : v[1]) cout << e + 1 << ' ';
        cout << '\n';
    }   
}