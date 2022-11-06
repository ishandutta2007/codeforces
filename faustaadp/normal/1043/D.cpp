#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,m,i,j,a[12][101010],las[11],pos[12][101010],has,hz;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            cin>>a[i][j];
            pos[i][a[i][j]]=j;
        }
    for(i=2;i<=m;i++)
        las[i]=pos[i][a[1][1]];
    for(i=1;i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            las[j]++;
            if(a[j][las[j]]!=a[1][i])
            {
                has+=((hz*(hz+1))/2);
                hz=-1;
                break;
            }
        }
        if(hz==-1)
        {
            for(j=2;j<=m;j++)
                las[j]=pos[j][a[1][i]];
            hz=0;
        }
        hz++;
     //   cout<<hz<<"\n";
    }
    has+=(hz*(hz+1)/2);
    cout<<has<<"\n";
}