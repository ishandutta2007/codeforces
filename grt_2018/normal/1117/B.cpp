#include <bits/stdc++.h>

using namespace std;

int n,m,k,maks,maks2;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int a,i=0; i<n;i++) {
        cin>>a;
        if(a>maks) {
            maks2=maks;
            maks=a;
        }
        else if(a>maks2) maks2=a;
    }
    //cout<<maks2<<" "<<maks<<" "<<(m/(k+1))<<"\n";
    ans = (long long)maks2*(m/(k+1));
    ans+=(long long)maks*(m-(m/(k+1)));
    cout<<ans;
    return 0;
}