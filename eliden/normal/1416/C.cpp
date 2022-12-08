#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<": "<<x<<endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) x.begin(), x.end()
using ll = long long;
using vi = vector<int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vi a(n);
    rep(i,0,n) cin>>a[i];
    int ans=0;
    ll invtotal=0;
    vector<vi> seqs{a};
    for(int p=30;p>=0;--p) {
        int pow = 1<<p;
        ll inv0=0, inv1=0;
        vector<vi> next;
        for(const auto &seq:seqs) {
            vi seq0, seq1;
            int c0=0, c1=0;
            for(int x:seq) {
                if(x&pow) {
                    ++c1;
                    inv1+=c0;
                    seq1.push_back(x);
                }
                else {
                    ++c0;
                    inv0+=c1;
                    seq0.push_back(x);
                }
            }
            if(!seq0.empty()) next.push_back(seq0);
            if(!seq1.empty()) next.push_back(seq1);
        }
        seqs = move(next);
        next = vector<vi>();
        if(inv1<inv0) ans^=pow;
        invtotal += min(inv0,inv1);
    }
    cout<<invtotal<<" "<<ans<<"\n";
}