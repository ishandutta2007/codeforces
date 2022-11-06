#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
string s;
ll n,has,hz,i;
char seb;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    n=s.length();
    s=s+s;
    seb='x';
    for(i=0;i<n*2;i++)
    {
        if(s[i]!=seb)
        {
            hz++;
        }
        else
        {
            hz=1;
        }
        has=max(has,hz);
        seb=s[i];
    }
    has=min(has,n);
    cout<<has<<"\n";
}