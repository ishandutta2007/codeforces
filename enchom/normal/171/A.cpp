#include <iostream>
using namespace std;

int digits[11];

int Dig(int a)
{
    int k=0;
    if (a==0)
    return 1;
    while (a>0)
    {
        k++;
        a=a/10;
    }
    return k;
}

int main()
{
    int a,b;
    int i,j;
    int num=0;
    int copy;
    cin>>a>>b;
    copy=b;
    
    for (i=1;i<=Dig(copy);i++)
    {
        digits[i]=b%10;
        b=b/10;
    }
    for (i=1;i<=Dig(copy);i++)
    {
        num=num*10+digits[i];
    }
    cout<<num+a<<endl;
    return 0;
}