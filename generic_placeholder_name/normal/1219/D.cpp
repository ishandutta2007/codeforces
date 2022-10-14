#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n; ll k; cin>>n>>k; ll x[n]; for(int i=0; i<n; i++) cin>>x[i];
    ll a, c[n]; cin>>a; for(int i=0; i<n; i++) cin>>c[i];
    int prev=0; ll ans=0; vector <ll> aux;
    for(int i=0; i<n; i++) {
        if (x[i]>k) {
            ll t=ceil((double)(x[i]-k)/(double)a);
            for(int j=prev; j<=i; j++) aux.push_back(c[j]);
            if(aux.size()<t) {
                cout<<-1; return 0;
            }
            else {
                sort(aux.begin(), aux.end(), greater<ll> ());
                for(int j=1; j<=t; j++) {
                    ans+=aux[aux.size()-1]; aux.pop_back();
                }
                prev=i+1;
                k+=a*t;
            }
        }
    }
    cout<<ans; return 0;
}