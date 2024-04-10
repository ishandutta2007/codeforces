#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll k,has,q,x,y,i,d[1010][1010],t,h1,h2,NZ;
string n,m;
ll depe(ll aa,ll bb)
{
    if(bb<0)
        return 0;
    else
    if(aa==0)
        return 1;
    if(d[aa][bb]==-1)
    {
        d[aa][bb]=depe(aa-1,bb)+depe(aa-1,bb-1)*9;
    }
    return d[aa][bb];
}
ll com(string aa)
{
    ll NN=aa.length();
    if(NN==1)
        return (aa[0]-'0'-1);
    ll ii,H=-1,zs=3;
    for(ii=0;ii<NN;ii++)
    {
        if(aa[ii]=='0')
        {
            continue;
        }
        zs--;
        H+=depe(NN-ii-1,zs+1);
        H+=depe(NN-ii-1,zs)*(aa[ii]-'0'-1);
       // if(ii+1==NN)
       //     H+=depe(NN-ii-1,zs);
    }
    return H;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(d,-1,sizeof(d));
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        h1=com(n);
        h2=com(m);
    //    cout<<h1<<" "<<h2<<"\n";
        has=h2-h1;
        NZ=0;
        for(i=0;i<m.length();i++)
            if(m[i]!='0')
                NZ++;
        if(NZ<=3)
            has++;
        cout<<has<<"\n";
    }
}