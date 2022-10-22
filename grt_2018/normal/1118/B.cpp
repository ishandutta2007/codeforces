#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*100000+2;

int n;
int a[MAXN];
long long p[MAXN][2],s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n;i++) {
        cin>>a[i];
        p[i][0] = p[i-1][1];
        p[i][1] = p[i-1][0] + a[i];
        s+=a[i];
    }
    int ans=0;
    for(int i=1; i<=n;i++) {
        long long w = p[i][0];
        if((i)%2==n%2) w+=p[n][1] - p[i][1];
        else w+=p[n][0] - p[i][1];
        //cout<<w<<" "<<p[i][0]<<" "<<p[i][1]<<"\n";
        if(2*w==s-a[i]) ans++;
    }
    cout<<ans;
    return 0;
}