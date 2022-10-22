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

bool adj[256][256];
bool done[256];

int main(){
	ios::sync_with_stdio(0);
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    rep(i,0,n) {
        adj[a[i]][b[i]] = 1;
        adj[b[i]][a[i]] = 1;
    }
    rep(i,0,256)
        adj[i][i] = 1;
    rep(k,0,256)
        rep(i,0,256)
        rep(j,0,256) {
            if(adj[i][k] && adj[k][j])
                adj[i][j] = 1;
        }
    vector<pair<char, char> > ans;
    rep(i,0,256) {
        if(done[i])
            continue;
        rep(j,0,256)
            if(adj[i][j]) {
                if (i != j)
                    ans.emplace_back(i, j);
                done[j] = 1;
            }
    }
    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first << " " << it.second << endl;
    }
}