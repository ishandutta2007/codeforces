#include <bits/stdc++.h>
typedef long long ll;
#define int long long
using namespace std;
main()
{
    int n,m;
    cin>>n>>m;
    int o=ll(sqrt(2*m));
    while(o*(o-1)/2<m) o++;
    cout<<max(0ll,n-m*2)<<" "<<n-o;
}