#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>pi;
typedef vector<int>vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 300*1000+1;
const int INF = 1000*1000*1000;
int c[MAXN];
int ans,n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) cin>>c[i];
    for(int x=0; x<2; x++) {
        for(int j=n-1; j>=0; j--) {
            if(c[0]!=c[j]) {
                ans=max(ans,j-0);
                break;
            }
        }
        reverse(c,c+n);
    }
    cout<<ans;
}