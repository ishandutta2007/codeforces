#include <bits/stdc++.h>
using namespace std;

#define rep(i,f,t) for (int i = (f); i < (t); i++)
#define all(x) (x).begin(), (x).end()
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

// 
// bool prufer(const vi& code, const vector<pii>& eds, int N) {
//     vector<set<int>> adj(N);
//     trav(it, eds) deg[it.first].insert;
//     trav(it, eds) deg[it.second]++;
// 
//     set<int> leafs;
//     rep(i,0,N) if (deg[it.first] == 1) leafs.insert(i);
//     rep(i,0,N-2) {
//     }
// }

int main() {
    cin.sync_with_stdio(false);
    int N, M, KA, KB;
    cin >> N >> M >> KA >> KB;

    if (KB >= N || KA > M) {
        cout << "No" << endl;
        return 0;
    }

    vi a(KA), b(KB);
    trav(it, a) cin >> it;
    trav(it, b) cin >> it;

    while (sz(a) < M - 1) a.push_back(a.back());
    while (sz(b) < N) b.push_back(N + M);

    vi appears(N+M+1);
    trav(it, a) appears[it]++;
    trav(it, b) appears[it]++;

    set<int> al, bl;
    rep(i,1,N+1) al.insert(i);
    rep(i,N+1,N+M+1) bl.insert(i);

    trav(it, a) al.erase(it);
    trav(it, b) bl.erase(it);

    int ai = 0;
    int bi = 0;
    vector<pii> eds;
    rep(_,0,N+M-1) {
        if (!al.empty() && bi != sz(b)) {
            eds.emplace_back(*al.begin(), b[bi]);
            al.erase(al.begin());
            if (--appears[b[bi]] == 0) bl.insert(b[bi]);
            bi++;
        } else if (!bl.empty() && ai != sz(a)) {
            eds.emplace_back(a[ai], *bl.begin());
            bl.erase(bl.begin());
            if (--appears[a[ai]] == 0) al.insert(a[ai]);
            ai++;
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    if (bi != sz(b) || ai != sz(a)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        trav(it, eds) cout << it.first << " " << it.second << endl;
        //assert(prufer(a, eds, N+M));
        //assert(prufer(b, eds, N+M));
    }
}