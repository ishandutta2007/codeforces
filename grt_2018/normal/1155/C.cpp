#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 300*1000+1;
int n,m;
LL x[nax],g;
LL p[nax];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n;i++) {
        cin>>x[i];
    }
    for(int i=0; i<m;i++) {
        cin>>p[i];
    }
    g = x[1]-x[0];
    for(int i=2; i<n;i++) {
        g=__gcd(g,x[i]-x[i-1]);
    }
    for(int i=0; i<m;i++) {
        if(g%p[i]==0) {
            cout<<"YES\n"<<x[0]<<" "<<i+1;
            return 0;
        }
    }
    cout<<"NO";
}