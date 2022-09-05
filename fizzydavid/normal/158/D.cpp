#include<iostream>
#include<cstdlib>
using namespace std;
int n,a[20005];
int main()
{
    int i,j,k;
    long long s,S=0;
    cin>>n;
    for(i=1;i<=n;i++){cin>>a[i];S+=a[i];}
    for(i=2;i<(n/2);i++)
    {
        if(n%i==0)
        {
            for(j=1;j<=i;j++)
            {
                s=0;
                for(k=0;k<(n/i);k++)s+=a[k*i+j];
                if(s>S)S=s;
            }
        }
    }
    cout<<S;
    return 0;
}