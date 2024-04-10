#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    io
    long t,n,k,d1,d2,a,b,c;
    cin>>t;
    while(t--)
    {
        cin>>n>>k>>d1>>d2;
        if(n%3) {cout<<"no"<<endl;continue;}
        if((k-2*d2-d1)%3==0 && 2*d1+d2<=n-k && k-2*d2-d1>=0) {cout<<"yes"<<endl;continue;}
        if((k-d1-d2)%3==0 && 2*max(d1,d2)-min(d1,d2)<=n-k && k-d1-d2>=0) {cout<<"yes"<<endl;continue;}
        if((k-2*d1-d2)%3==0 && 2*d2+d1<=n-k && k-2*d1-d2>=0) {cout<<"yes"<<endl;continue;}
        if((k+d1+d2)%3==0 && d1+d2<=n-k && (k+d1+d2)/3>=max(d1,d2)) {cout<<"yes"<<endl;continue;}
        cout<<"no"<<endl;
    }
    return 0;
}