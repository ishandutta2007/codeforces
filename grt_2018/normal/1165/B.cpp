#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+1;
int n,ans;
int a[nax];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int ind = 0;
    for(int i=1; i<=n;i++) {
        while(ind<n&&a[ind]<i) {
            ind++;
        }
        if(ind>=n) break;
        ans=i;
        ind++;
    }
    cout<<ans;
}