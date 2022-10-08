#include <iostream>
using namespace std;
int main()
{
    long long F[50],n,fibn;
    long long i,j,in;
    F[0]=0;
    F[1]=1;
    for (i=2;i<=44;i++)
    F[i]=F[i-1]+F[i-2];
    cin>>n;
    if (n==0)
    {
        cout<<"0 0 0"<<endl;
        return 0;
    }
    for (i=1;i<=44;i++)
    {
        if (n==F[i])
        {
            fibn=i;
            break;
        }
    }
    if (fibn==1)
    {
        cout<<"0 0 1"<<endl;
        return 0;
    }
    if (0+F[fibn-2]+F[fibn-1]!=n)
    cout<<"I'm too stupid to solve this problem"<<endl;
    else
    cout<<0<<" "<<F[fibn-2]<<" "<<F[fibn-1]<<endl;
    return 0;
}