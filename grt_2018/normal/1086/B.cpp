#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 100*1000+10;
int n,s;
int l;
int deg[nax];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int a,b,i=1;i<n;i++) {
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }
    for(int i=1; i<=n;i++) {
        if(deg[i]==1) {
            l++;
        }
    }
    long double ans = (long double)2*s/l;
    cout<<setprecision(7)<<ans;
}