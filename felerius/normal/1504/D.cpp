#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
//#define endl        '\n'

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<pair<int,int>> p1, p2; // p1 gets 1, p2 gets 2
    rep(i,n) rep(j,n) ((i+j) % 2 ? p1 : p2).emplace_back(i+1, j+1);

    auto pick = [&](bool first, int col) {
        auto& vec = first ? p1 : p2;
        cout << col << ' ' << vec.back().first << ' ' << vec.back().second << endl;
        vec.pop_back();
    };

    rep(t,n*n) {
        int a; cin>>a;
        if(a==-1) exit(0);

        if(size(p1)&&size(p2)) {
            if(a==1) pick(false, 2);
            else pick(true, 1);
        } else {
            int col = size(p1) ? 1 : 2;
            if(col==a) col = 3;
            pick(size(p1), col);
        }
    }


    return 0;
}