#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    int a[n], st1[n<<1], st2[n<<1], st3[n<<1];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];

        st1[n+i]=a[i];
        st2[n+i]=a[i];
        st3[n+i]=1;
    }

    for(int i=n-1; i>=1; i--)
    {
        st1[i]=__gcd(st1[(i<<1)],st1[(i<<1)|1]);

        st2[i]=min(st2[(i<<1)],st2[(i<<1)|1]);

        st3[i]=0;
        if(st2[(i<<1)]==st2[i]) st3[i]+=st3[(i<<1)];
        if(st2[(i<<1)|1]==st2[i]) st3[i]+=st3[(i<<1)|1];
    }

    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;

        int rng=r-l+1;

        l+=n-1;
        r+=n;

        int t1=-1,t2=-1,t3=-1;

        while(l<r)
        {
            if(l&1)
            {
                if(t1==-1) t1=st1[l];
                else t1=__gcd(t1,st1[l]);

                if(t2==-1||st2[l]<t2)
                {
                    t2=st2[l];
                    t3=st3[l];
                }
                else if(st2[l]==t2)
                {
                    t3+=st3[l];
                }

                l++;
            }
            if(r&1)
            {
                r--;
                
                if(t1==-1) t1=st1[r];
                else t1=__gcd(t1,st1[r]);

                if(t2==-1||st2[r]<t2)
                {
                    t2=st2[r];
                    t3=st3[r];
                }
                else if(st2[r]==t2)
                {
                    t3+=st3[r];
                }
            }
            l>>=1;
            r>>=1;
        }

        if(t1==t2) cout<<rng-t3<<'\n';
        else cout<<rng<<'\n';
    }

    return 0;
}