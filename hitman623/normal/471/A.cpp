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
    long l[10]={0},x,i,a=0,b=0,f=0;
    for(i=0;i<6;++i)
    {
        cin>>x;
        l[x]++;
        if(l[x]==4) f=1;
    }
    if(f==0) {cout<<"Alien";exit(0);}
    for(i=0;i<10;++i)
    if(l[i]!=4 && l[i]!=0)
    {
        if(a==0)
        {
            a=i;
            if(l[i]==6 || l[i]==2)
            b=i;
        }
        else b=i;
    }
    if(a==b) cout<<"Elephant";
    else if(a<b) cout<<"Bear";
    return 0;
}