#include<iostream>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    REP(i,0,n)
    {
        cin>>a[i];
    }
    vector<ll> v;
    v.push_back(1);
    REP(i,1,n)
    {
         if(a[i]%2==a[i-1]%2) v[v.size()-1]++;
         else v.push_back(1);
    }
    vector<ll> st;
    REP(i,0,v.size())
    {
        if(v[i]%2) 
        {
            if(st.size()==0) st.push_back(i%2);
            else if(st.back()==i%2) st.pop_back();
            else st.push_back(i%2);
        }
    }
    if(st.size()>1) cout<<"NO";
    else cout<<"YES";
}