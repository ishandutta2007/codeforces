#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> p(2*n);
    rep(i,0,2*n) cin >> p[i];
    vector<int> a(m), b(m);
    vector<int> other(2*n,-1);
    vector<int> pnum(2*n,-1);
    rep(i,0,m) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
        if(p[a[i]]<p[b[i]]) swap(a[i],b[i]);
        // a[i] better than b[i]
        other[a[i]] = b[i];
        other[b[i]] = a[i];
        pnum[a[i]] = i;
        pnum[b[i]] = i;
    }
    int t;
    cin >> t;
    int op_move = -1;
    int left = 2*n;
    if(t==2) {
        cin >> op_move;
        --op_move;
        --left;
    }
    vector<bool> used(m);
    vector<bool> avail(2*n,true);
    while(left) {
        int j = -1;
        if(op_move!=-1) {
            avail[op_move] = false;
            j = pnum[op_move];
        }
        int chosen = -1;
        if(j!=-1 && avail[other[op_move]]) {
            used[j] = true;
            chosen = other[op_move];
        }
        else {
            int x = -1;
            rep(i,0,m) if(!used[i]) {
                x = i;
            }
            if(x!=-1) {
                used[x] = true;
                chosen = a[x];
            }
            else {
                rep(i,0,2*n) if(avail[i] && (chosen==-1 || p[i]>p[chosen])) {
                    chosen = i;
                }
            }
        }
        
        avail[chosen] = false;
        --left;
        cout << chosen+1 << "\n";
        cout.flush();
        if(left) {
            cin >> op_move;
            --op_move;
            --left;
        }
    }
                     
}