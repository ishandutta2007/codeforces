#include<iostream>
using namespace std;
int n,sum,i,j;
bool sq[100000000];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    sq[i*i]=true;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n && i*i+j*j<=n*n;j++)
        {
            if(sq[i*i+j*j])sum++;
        }
    }
    cout<<sum;
    return 0;
}