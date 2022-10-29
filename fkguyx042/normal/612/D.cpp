#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

typedef long long llint;
typedef pair<int, bool> p;

#define pb push_back
#define X first
#define Y second
#define TRACE(x) cout<<#x<<" = "<<x<<endl;
#define endl "\n"

vector <p> gran; // pozicija, vrsta , 0 otvor, 1 zatvor
int n, k;
vector < pair< int, int> > ans;

int main () {
    std::ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        gran.pb(p(x, 0));
        gran.pb(p(y, 1));
    }
    sort(gran.begin(), gran.end());

    int opened = 0;
    int l;
    for (int i = 0; i < gran.size(); i++) {
        p t = gran[i];

        if (t.Y == 0) {
            opened++;
            if (opened == k)
                l = t.X;
        }
        else {
            opened--;
            if (opened == k - 1) {
                ans.pb( make_pair(l, t.X));
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].X << " " << ans[i].Y << endl;
    }
    return 0;
}