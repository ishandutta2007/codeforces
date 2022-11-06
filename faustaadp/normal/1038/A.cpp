#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,k,i,p[1010],mi,j;
char c[101010];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>c[i];
        p[c[i]-'A']++;
    }
    mi=1e18;
    for(j=0;j<k;j++)
        mi=min(mi,p[j]);
    mi*=k;
    cout<<mi<<"\n";
}