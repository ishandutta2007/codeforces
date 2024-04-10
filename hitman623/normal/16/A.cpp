#include <iostream>

using namespace std;

int main()
{
    int n,m,f=1,i,j;
    cin>>n>>m;
    char a[101],b;
    for(i=0;i<n;++i)
    {  cin>>a;
    if(i>0 && a[0]==b) f=0; 
    b=a[0];
        for(j=1;a[j]!=0;++j)
        {
           if(b!=a[j]) f=0;
        }
    }
    if(f==0)cout<<"NO";
    else cout<<"YES";
    return 0;
}