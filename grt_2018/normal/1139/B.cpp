#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+1;
const int INF = 1000*1000*1000+1;
int n,a[MAXN];
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) cin>>a[i];
    int border = INF;
    for(int i=n-1; i>=0;i--) {
        if(a[i]<border) {
            ans+=a[i];
            if(border>0) border = a[i]-1;
        }
        else {
            ans+=border;
            if(border>0) border--;
        }
    }
    cout<<ans;
}