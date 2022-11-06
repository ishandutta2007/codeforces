#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,q,i,a[1010],p[1010],ta,tb;
string s1,s2,st;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    cin>>s1>>s2;
    if(n>=m)
    {
        st=s1.substr(0,m);
        if(st==s2)
            a[1]=1;
        for(i=m;i<n;i++)
        {
            st+=s1[i];
            st=st.substr(1,m);
            if(st==s2)
                a[i-m+2]=1;
        }
        for(i=1;i<=n;i++)
            p[i]=p[i-1]+a[i];
    }
    while(q--)
    {
        cin>>ta>>tb;
        tb=tb-m+1;
        if(ta>tb)
            cout<<0<<"\n";
        else
            cout<<p[tb]-p[ta-1]<<"\n";
    }
}