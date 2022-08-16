#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    multiset<int> b;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        b.insert(t);
    }

    for(int i=0; i<n; i++)
    {
        auto it = b.lower_bound(n-a[i]);

        if(it != b.end())
        {
            a[i] = (a[i] + (*it))%n;
            b.erase(it);
        }
        else
        {
            it = b.begin();

            a[i] = (a[i] + (*it))%n;
            b.erase(it);
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<' ';
    }

    return 0;
}