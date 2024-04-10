#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 200*1000+10,mod=998244353;
int n,k;
int p[nax];
ll sum;
int cnt=1;

int main() {_
    cin >> n >> k;
    for(int i=1; i<=n; ++i) {
        cin >> p[i];
    }
    for(int i=n; i>=n-k+1; i--) {
        sum += i;
    }
    int last = 0;
    for(int i=1; i<=n; i++) {
        if(p[i]>n-k) {
            if(last>0) {
                cnt = (ll)cnt*(i-last)%mod;
            }
            last = i;
        }
    }
    cout<<sum<<" "<<cnt;
}