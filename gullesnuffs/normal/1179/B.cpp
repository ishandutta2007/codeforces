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

void addPos(int r, int c) {
    printf("%d %d\n", r+1, c+1);
}

int main(){
    int n, m;
    cin >> n >> m;
    //vector<pair<int, int>> pos;
    rep(c,0,(m+1)/2) {
        if (c == m-c-1) {
            rep(r,0,(n+1)/2) {
                addPos(r, c);
                if (r != n-r-1)
                    addPos(n-r-1, c);
            }
        }
        else {
            rep(r,0,n) {
                addPos(r, c);
                addPos(n-r-1, m-c-1);
            }
        }
    }
    /*set<pair<int, int>> vectors;
    rep(i,0,sz(pos-1)) {
        int dx = pos[i+1].first - pos[
    }*/
    /*for (auto it : pos) {
        cout << it.first+1 << " " << it.second+1 << endl;
    }*/
}