#include<iostream>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>
#include<cstdio>
using namespace std;
int fi[52][52],a,b,c,ho[52],ve[52];
int main()
{
    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int i,j,n,m,sum=0,s1,s2,s3,r;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++){cin>>fi[n][m];ho[i]+=fi[n][m];ve[j]+=fi[n][m];}
    }
    cin>>a>>b>>c;
    for(r=1;r<m-1;r++){
        for(i=2;i<=(m-r);i++)
        {
            s1=0;
            for(j=0;j<r;j++)s1+=ve[i+j];
            if(s1==a||s1==b||s1==c)
            {
                s2=0;s3=0;
                for(j=1;j<i;j++)s2+=ve[j];
                for(j=i+r;j<=m;j++)s3+=ve[j];
                if(s1==a&&s2==b&&s3==c||s1==a&&s3==b&&s2==c||s2==a&&s1==b&&s3==c||s2==a&&s3==b&&s1==c||s3==a&&s1==b&&s2==c||s3==a&&s2==b&&s1==c){sum++;}
            }
            cout<<endl;
        }
    }
    for(r=1;r<n-1;r++){
        for(i=2;i<=(n-r);i++)
        {
            s1=0;
            for(j=0;j<r;j++)s1+=ho[i+j];
            {
                s2=0;s3=0;
                for(j=1;j<i;j++)s2+=ho[j];
                for(j=i+r;j<=n;j++)s3+=ho[j];
                if(s1==a&&s2==b&&s3==c||s1==a&&s3==b&&s2==c||s2==a&&s1==b&&s3==c||s2==a&&s3==b&&s1==c||s3==a&&s1==b&&s2==c||s3==a&&s2==b&&s1==c){sum++;}
            }
        }
    }
    cout<<sum;
    return 0;
}