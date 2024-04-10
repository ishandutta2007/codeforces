#include <bits/stdc++.h>
#define N 1005
#define INF 5000000
using namespace std;
typedef long long ll;
int n,a[N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    if(n%2)
        cout<<a[n/2+1];
    else
        cout<<a[n/2];
    return 0;
}