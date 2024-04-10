#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    static const int N=8005;
    static int ntc,n,i,j,sm,a[N];
    static bool flag[N];
    cin>>ntc;
    while(ntc--)
    {
        cin>>n;
        for(i=0;i<N;i++)
        {
            flag[i]=false;
        }
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=0;i<n;i++)
        {
            sm=a[i];
            for(j=i+1;j<n;j++)
            {
                sm+=a[j];
                if(sm>=N) break;
                flag[sm]=true;
            }
        }
        sm=0;
        for(i=0;i<n;i++)
        {
            if(flag[a[i]]) sm++;
        }
        cout<<sm<<'\n';
    }

    return 0;
}