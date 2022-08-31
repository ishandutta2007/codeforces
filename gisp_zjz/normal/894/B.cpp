#include<bits/stdc++.h>
#define M 1000000007

using namespace std;
typedef long long ll;
ll n,m,ans,t;

int main()
{
    cin>>n>>m>>t; n--,m--;
    if ((n+m)&1) {
        if (t==-1){
            cout << 0 << endl;
            return 0;
        }
    }
    ans=1; t=2;
    while (n){
        if (n&1) ans=ans*t%M;
        t=t*t%M;
        n>>=1;
    }
    t=ans; ans=1;
    while (m){
        if (m&1) ans=ans*t%M;
        t=t*t%M;
        m>>=1;
    }
    cout<<ans<<endl;
}