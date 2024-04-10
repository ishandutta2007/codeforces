#include <iostream>
using namespace std;

bool TFO[102][102];
int arr[102][102];

int main()
{
    int n,i,j;
    int sum=0;
    
    for (i=0;i<=101;i++)
    {
        for (j=0;j<=101;j++)
        TFO[i][j]=false;
    }
    
    cin>>n;
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    for (i=1,j=1;i<=n,j<=n;i++,j++)
    {
        if (!TFO[i][j])
        {
            sum=sum+arr[i][j];
            TFO[i][j]=true;
        }
    }
    
    for (i=1,j=n;i<=n,j>=1;i++,j--)
    {
        if (!TFO[i][j])
        {
            sum=sum+arr[i][j];
            TFO[i][j]=true;
        }
    }
    
    for (i=1;i<=n;i++)
    {
        if (!TFO[ (n+1)/2 ][i])
        {
            sum=sum+arr[ (n+1)/2 ][i];
            TFO[ (n+1)/2 ][i]=true;
        }
    }
    
    for (i=1;i<=n;i++)
    {
        if (!TFO[i][ (n+1)/2 ])
        {
            sum=sum+arr[i][ (n+1)/2 ];
            TFO[i][ (n+1)/2 ]=true;
        }
    }
    
    cout<<sum<<endl;
    return 0;
}