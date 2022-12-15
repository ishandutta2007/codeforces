#include <bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int ms = 2e6+5;

vector<int> v;
int total;

void solve(vector<int> v, int total, int st) {
    vi ans = {st};
    if(v[st] == 0) return;
    v[st]--;
    total--;
    while(total > 0) {
        bool found = 0;
        for(int i = 0; i < 4 && !found; i++) {
            if(v[i] > 0 && (st == i-1 || st == i+1)) {
                v[i]--;
                st = i;
                total--;
                ans.push_back(i);
                found = 1;
            }
        }
        if(!found) return;
    }
    cout << "YES\n";
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i+1 == ans.size()];
    }
    exit(0);
}

main() {
    cin.tie(0); ios::sync_with_stdio(0);
    for(int i = 0; i < 4; i++) {
        int x;
        cin >> x;
        total += x;
        v.push_back(x);
    }
    for(int i = 0; i < 4; i++) {
        solve(v, total, i);
    }
    cout << "NO\n";
}