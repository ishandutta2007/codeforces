#include <iostream>

using namespace std;

int main()
{
    int n,m,k,a[100],b[100][100],i,j,t=0,ii,jj,temp;
    cin>>n>>m>>k;
    for(i=0;i<k;++i)
        cin>>a[i];
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
          cin>>b[i][j];
    for(i=0;i<n;++i)
    {
        for(j=0;j<m;++j)
        {
            for(ii=0;ii<k;++ii)
            {
                if(b[i][j]==a[ii])
                {
                    t+=ii+1;temp=a[ii];

                    for(jj=ii;jj>0;jj--)
                    {
                        a[jj]=a[jj-1];
                    }
                    a[jj]=temp;
                    break;
                }
            }
        }
    }
    cout<<t;
    return 0;
}