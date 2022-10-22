#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>pi;
typedef vector<int>vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 300*1000+1;
int n,um;
LL ans;
int a[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) cin>>a[i];
    for(int i=0; i<n;i++) {
        if(um*2<=a[i]) {
            a[i]-=2*um;
            ans+=um;
            um=0;
        }
        else {
            ans+=a[i]/2;
            um-=(a[i]/2);
            a[i]-=2 * (a[i]/2);
        }
        ans+=a[i]/3;
        um+=(a[i]%3);
    }
    cout<<ans;
}