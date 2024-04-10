#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int nax = 7010;
int n;
ll ans;
pair<ll,int>e[nax];
vector<ll>masks;

int main() {_
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>e[i].ST;
    }
    for(int i=0; i<n;i++) {
        cin>>e[i].ND;
    }
    sort(e,e+n);
    e[n].ST = -1;
    for(int i=1; i<n; i++) {
        if(e[i].ST!=e[i+1].ST&&e[i].ST==e[i-1].ST) masks.PB(e[i].ST);
    }
    for(int i=0; i<n;i++) {
        bool ok=0;
        for(ll it:masks) {
            if((e[i].ST|it)==it) ok=1;
        }
        if(ok) ans+=e[i].ND;
    }
    cout<<ans;
}