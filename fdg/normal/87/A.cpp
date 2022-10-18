#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define ll long long

using namespace std;

ll gcd(ll a,ll b) { return b==0 ? a : gcd(b,a%b); };

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    ll a,b,lcm;
    cin >> a >> b;
    lcm=a*b/gcd(a,b);
    vector < pair<ll,int> > v;
    for(int k=1;k*a<lcm;k++)
        v.push_back(make_pair(k*a,0));
    for(int k=1;k*b<lcm;k++)
        v.push_back(make_pair(k*b,1));
    sort(v.begin(),v.end());
    ll s1=0;
    for(int i=0;i<v.size();i++)
        if (v[i].second==0)
        {
            if (i==0) s1+=v[i].first;
            else s1+=v[i].first-v[i-1].first;
        }
    if (a>b) s1+=b;
    if (s1==lcm-s1) puts("Equal");
    else if (s1>lcm-s1) puts("Dasha");
    else puts("Masha");
    return 0;
}