#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,k1,k2,i,x,c=0;
    vector < long > a,b;
    map < pair < vector < long > , vector < long > > ,long > mp;
    cin>>n;
    cin>>k1;
    for(i=0;i<k1;++i)
    {
        cin>>x;
        a.pb(x);
    }
    cin>>k2;
    for(i=0;i<k2;++i)
    {
        cin>>x;
        b.pb(x);
    }
    while(1)
    {
        if(a[0]<b[0])
        {
            b.insert(b.end(),a[0]);
            b.insert(b.end(),b[0]);
            a.erase(a.begin());
            b.erase(b.begin());
        }
        else
        {
            a.insert(a.end(),b[0]);
            a.insert(a.end(),a[0]);
            a.erase(a.begin());
            b.erase(b.begin());
        }
        c++;
        if(mp[{a,b}]==1) {cout<<-1;exit(0);}
        if(a.empty()) {cout<<c<<" "<<2;exit(0);}
        if(b.empty()) {cout<<c<<" "<<1;exit(0);}
        mp[{a,b}]=1;
    }
    return 0;
}