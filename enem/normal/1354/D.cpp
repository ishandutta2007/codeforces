#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    static int n,i,q,t,pt,st[1<<21];

    for(int i=0;i<(1<<21);i++)
        st[i]=0;
    
    cin>>n>>q;

    for(i=0;i<n;i++)
    {
        cin>>t;

        st[(1<<20)+t]++;
    }

    for(i=(1<<20)-1;i>0;i--)
    {
        st[i]=st[(i<<1)]+st[(i<<1)|1];
    }

    for(i=0;i<q;i++)
    {
        cin>>t;

        if(t>0)
        {
            pt=(1<<20)+t;

            while(pt>0)
            {
                st[pt]++;
                pt>>=1;
            }
        }
        else
        {
            pt=1;
            t=-t;

            while(pt<(1<<20))
            {
                if(st[pt<<1]>=t)
                {
                    pt<<=1;
                }
                else
                {
                    t-=st[pt<<1];
                    pt=((pt<<1)|1);
                }
            }

            while(pt>0)
            {
                st[pt]--;
                pt>>=1;
            }
        }
    }
    if(st[1]==0) cout<<0;
    else
    {
        for(i=0;i<(1<<20);i++)
        {
            if(st[(1<<20)+i]>0)
            {
                cout<<i;
                break;
            }
        }
    }

    return 0;
}