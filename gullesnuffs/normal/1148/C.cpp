#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int n;
vector<int> p;
vector<pair<int, int>> ans;

void doSwap(int i, int j) {
    ans.emplace_back(i, j);
    swap(p[i], p[j]);
}

void sw(int i, int j) {
    if (i > j)
        swap(i, j);
    if (2*(j-i) >= n) {
        doSwap(i, j);
        return;
    }
    if (j < n/2 || i >= n/2) {
        int k;
        if (j < n/2)
            k = n-1;
        else
            k = 0;
        doSwap(i, k);
        doSwap(j, k);
        doSwap(i, k);
    }
    else {
        doSwap(i, n-1);
        doSwap(0, n-1);
        doSwap(0, j);
        doSwap(0, n-1);
        doSwap(i, n-1);
    }
}

int main(){
	ios::sync_with_stdio(0);
    cin >> n;
    p = vector<int>(n);
    rep(i,0,n) {
        cin >> p[i];
        --p[i];
    }
    /*while (true) {
        p.clear();
        ans.clear();
        int n = 1+(rand()%5);
        rep(i,0,n)
            p.push_back(i);
        random_shuffle(all(p));*/

    rep(i,0,n) {
        while (p[i] != i) {
            sw(i, p[i]);
        }
    }
    rep(i,0,n) {
        if (p[i] != i) {
            //rep(j,0,n)
              //  cout << q[j] << " ";
            cout << endl;
            assert(0);
        }
    }
    cout << sz(ans) << endl;
    for (auto it : ans)
        cout << it.first+1 << " " << it.second+1 << endl;
    //}
}