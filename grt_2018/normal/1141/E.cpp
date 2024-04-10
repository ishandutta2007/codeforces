#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*1000*100+1;
long long H;
long long w,minp=1000*1000*1000;
int n;
long long ans;
int d[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>H>>n;
    for(int i=0; i<n;i++) {
        cin>>d[i];
        w+=d[i];
        if(H+w<=0) {
            cout<<i+1<<"\n";
            return 0;
        }
        minp=min(minp,w);
    }
    if(w>=0) {
        cout<<"-1";
        return 0;
    }
    w=-w;
    ans = (H+minp-1)/w + 1;
    H = H - ans*w;
    ans*=n;
    //cout<<H<<" "<<w<<" "<<ans<<" "<<minp<<"\n";
    for(int i=0; i<n;i++) {
        ans++;
        H+=d[i];
        if(H<=0) {
            cout<<ans;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}