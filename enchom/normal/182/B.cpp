#include <iostream>
using namespace std;
int main()
{
    int month;
    int a[2001];
    int d;
    int i;
    int n;
    int ctr=0;
    
    cin>>d>>n;
    
    for (i=1;i<=n;i++)
    cin>>a[i];
    
    for (i=1;i<=n-1;i++)
    {
        if (a[i]!=d)
        {
            ctr=ctr+(d-a[i]);
        }
    }
    cout<<ctr<<endl;
    return 0;
}