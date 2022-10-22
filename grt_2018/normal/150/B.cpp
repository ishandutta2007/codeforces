#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define ST first
#define ND second
#define PB push_back
#define DET(a,b,c) (LL(b.x-a.x)*LL((c.y-a.y))-LL((c.x-a.x))*LL((b.y-a.y)))

const int MOD = 1000*1000*1000+7;
LL ans=1;
int n,m,k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    if(k>n||k==1) {
        for(int i=1; i<=n;i++) ans=(ans*m)%MOD;
        cout<<ans;
        return 0;
    }
    if(k%2==0&&k<n) {
        cout<<m;
        return 0;
    }
    if(k<n) {
        cout<<m*m;
        return 0;
    }
    for(int i=1; i<=(n+1)/2;i++) {
        ans=(ans*m) %MOD;
    }
    cout<<ans;
}