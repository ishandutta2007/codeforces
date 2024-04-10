#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,j,bin,poi;
string s1,s2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    cin>>s1>>s2;
    bin=-1;
    for(i=0;i<n;i++)
        if(s1[i]=='*')
            bin=i;
    if(bin==-1)
    {
        if(s1==s2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    else
    {
        poi=0;
        for(i=0;i<m;i++)
        {
            if(poi==bin)
                break;
            if(s1[poi]!=s2[i])
            {
                cout<<"NO\n";
                return 0;
            }
            s2[i]='0';
            poi++;
        }
        if(poi!=bin)
        {
            cout<<"NO\n";
            return 0;
        }
        //cout<<s2<<"\n";
        poi=n-1;
        for(i=m-1;i>=0;i--)
        {
            if(poi==bin)
                break;
            if(s1[poi]!=s2[i])
            {
                cout<<"NO\n";
                return 0;
            }
            s2[i]='0';
            poi--;
        }
        if(poi!=bin)
        {
            cout<<"NO\n";
            return 0;
        }
        cout<<"YES\n";
    }
}