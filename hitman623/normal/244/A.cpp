#include <bits/stdc++.h>
#define pb push_back
#define long long long
using namespace std;

int main()
{
    long n,k,a[32],i,j;
    set < long > s;
    cin>>n>>k;
    for(i=1;i<=n*k;++i)
    s.insert(i);
    for(i=0;i<k;++i)
    {
        cin>>a[i];
        s.erase(s.find(a[i]));
    }
    for(i=0;i<k;++i)
    {
        cout<<a[i]<<" ";
        for(j=0;j<n-1;++j)
        {
            cout<<*s.begin()<<" ";
            s.erase(s.begin());
        }
        cout<<endl;
    }
    return 0;
}