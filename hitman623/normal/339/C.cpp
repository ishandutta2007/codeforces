#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vl vv;
string s;
long m,i,v[11]={0},f=0,last=0,j,l=0,r=0;
long solve(long i,long m,long l,long r,long ff)
{
    long j,f=0;
    if(m==0) return 1;
    for(j=1;j<=10;++j)
    if(i!=j && v[j] && ff==0 && l+j>r)
    {
        f=solve(j,m-1,l+j,r,1);
        if(f) {vv.pb(j);break;}
    }
    else if(i!=j && v[j] && ff==1 && r+j>l)
    {
        f=solve(j,m-1,l,r+j,0);
        if(f) {vv.pb(j);break;}
    }
    return f;
}
int main()
{
    io
    cin>>s>>m;
    for(i=0;i<10;++i)
    v[i+1]=(s[i]=='1');
    for(i=1;i<=10;++i)
    {
        vv.clear();
        if(v[i])
        {
            if(solve(i,m-1,i,0,1))
            {vv.pb(i);break;}
        }
    }
    if(vv.size()==0) {cout<<"NO";exit(0);}
    reverse(vv.begin(),vv.end());
    cout<<"YES\n";
    for(i=0;i<vv.size();++i)
    cout<<vv[i]<<" ";
    return 0;
}