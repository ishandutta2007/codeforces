#include<iostream>
#include<cstdlib>
using namespace std;
char a[310][310];
int main(){
    int n,m,k,i,j,r;
    cin>>n>>m>>k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(r=1;r<n;r++)  
    {
        for(i=r+1;i<=n&&r+i<=n;i++)
        {
            for(j=r+1;j<=m&&r+j<=m;j++)
            {
                if(a[i][j]=='*'&&a[i-r][j]=='*'&&a[i+r][j]=='*'&&a[i][j-r]=='*'&&a[i][j+r]=='*'){
                    k--;
                    if(k==0)
                    {
                            cout<<i<<" "<<j<<endl<<i-r<<" "<<j<<endl<<i+r<<" "<<j<<endl<<i<<" "<<j-r<<endl<<i<<" "<<j+r<<endl;
                            return 0;
                    }
                }
            }
        }
    }
    cout<<"-1";
    return 0;
}