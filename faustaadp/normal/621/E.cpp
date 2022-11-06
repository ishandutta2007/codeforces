#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,b,k,x,i,ta,a[11],M[110][110],j,mat[110][110],tem[110][110],mo=1000000007;
ll pan(ll aa)
{
    ll ii,jj,kk;
    for(ii=0;ii<x;ii++)
        mat[ii][ii]=1;
    while(aa>0)
    {
        if(aa%2==1)
        {
            for(ii=0;ii<x;ii++)
                for(jj=0;jj<x;jj++)
                {
                    tem[ii][jj]=0;
                    for(kk=0;kk<x;kk++)
                        tem[ii][jj]=(tem[ii][jj]+mat[ii][kk]*M[kk][jj])%mo;
                }
            for(ii=0;ii<x;ii++)
                for(jj=0;jj<x;jj++)
                    mat[ii][jj]=tem[ii][jj];
        }
        aa/=2;
        for(ii=0;ii<x;ii++)
                for(jj=0;jj<x;jj++)
                {
                    tem[ii][jj]=0;
                    for(kk=0;kk<x;kk++)
                        tem[ii][jj]=(tem[ii][jj]+M[ii][kk]*M[kk][jj])%mo;
                }
        for(ii=0;ii<x;ii++)
            for(jj=0;jj<x;jj++)
                M[ii][jj]=tem[ii][jj];
    }
    /*for(ii=0;ii<x;ii++)
    {
        for(jj=0;jj<x;jj++)
            cout<<mat[ii][jj]<<" ";
        cout<<"\n";
    }*/
    return mat[0][k];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>b>>k>>x;
	for(i=1;i<=n;i++)
    {
        cin>>ta;
        a[ta]++;
    }
    for(i=0;i<x;i++)
        for(j=1;j<=9;j++)
            M[i][(i*10+j)%x]+=a[j];
    /*for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)
            cout<<M[i][j]<<" ";
        cout<<"\n";
    }*/
    cout<<pan(b)<<"\n";
}