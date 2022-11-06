#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,i,a[1010101],jum[1010101],h1,h2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        vector<ll> v;
        for(i=1;i<=n;i++)
        {
            jum[a[i]]++;
            if(jum[a[i]]==2)
            {
                v.pb(a[i]);
                jum[a[i]]=0;
            }
        }
        sort(v.begin(),v.end());
        h1=v[0];
        h2=v[1];
        for(i=2;i<v.size();i++)
        {
            if((h1*v[i])<(h2*v[i-1]))
            {
                h1=v[i-1];
                h2=v[i];
            }
        }
        cout<<h1<<" "<<h1<<" "<<h2<<" "<<h2<<"\n";
        for(i=1;i<=n;i++)jum[a[i]]=0;
    }
}