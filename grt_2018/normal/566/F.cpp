#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 1000*1000+10;
int n,m;
bool t[nax];
int clique[nax];
int ans;

int main() {_
    cin>>n;
    for(int a,i=1; i<=n; i++) {
        cin>>a;
        m=max(m,a);
        t[a]=1;
    }
    for(int i=m; i>=1; i--) {
        if(t[i]) {
            for(int j=2*i; j<=m; j+=i) {
                if(t[j]) clique[i]=max(clique[i],clique[j]);
            }
            clique[i]++;
            ans=max(ans,clique[i]);
        }
    }
    cout<<ans;

}