#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll t,n,i;
string s;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--)
    {
        vector<ll> N,H,h;
        cin>>s;
        n=s.length();
        for(i=0;i<n;i++)
        {
            if('0'<=s[i]&&s[i]<='9')
                N.pb(i);
            else
            if('a'<=s[i]&&s[i]<='z')
                h.pb(i);
            else
                H.pb(i);
        }
        if(N.size()==0&&H.size()==0)
        {
            s[0]='0';
            s[1]='A';
        }
        else
        if(N.size()==0&&h.size()==0)
        {
            s[0]='0';
            s[1]='a';
        }
        else
        if(h.size()==0&&H.size()==0)
        {
            s[0]='a';
            s[1]='A';
        }
        else
        if(h.size()==0)
        {
            if(H.size()>1)
                s[H[0]]='a';
            else
                s[N[0]]='a';
        }
        else
        if(H.size()==0)
        {
            if(h.size()>1)
                s[h[0]]='A';
            else
                s[N[0]]='A';
        }
        else
        if(N.size()==0)
        {
            //cout<<"\Alsd\n";
            //cout<<h[0]<<"\n";
            if(h.size()>1)
                s[h[0]]='0';
            else
                s[H[0]]='0';
        }
        cout<<s<<"\n";
    }
}