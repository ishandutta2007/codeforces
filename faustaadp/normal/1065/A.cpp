#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,s,a,b,c,paket,sisa,dapat;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s>>a>>b>>c;
        paket=s/(a*c);
        sisa=s%(a*c);
        dapat=paket*(a+b)+sisa/c;
        cout<<dapat<<"\n";
    }
}