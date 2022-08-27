#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,ans;

int main()
{
    scanf("%lld",&n); n--; ans=n;
    for (int i=0;i<60;i++) ans+=(n>>(i+1))<<i;
    cout << ans << endl;
}