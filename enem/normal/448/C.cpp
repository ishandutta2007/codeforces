#include<bits/stdc++.h>
using namespace std;

int xd(int a[], int n, int hgt)
{
    if(n == 0) return 0;

    int mn = a[0];
    for(int i=1; i<n; i++)
        mn = min(mn, a[i]);
    
    int ans = mn-hgt, str=0;
    for(int i=0; i<n; i++)
    {
        if(a[i] == mn)
        {
            ans += xd(a + str, i-str, mn);
            str = i+1;
        }
    }
    ans += xd(a + str, n-str, mn);

    return min(n, ans);
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];

    cout<<xd(a, n, 0);

    return 0;
}