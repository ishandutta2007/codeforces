#include <iostream>
using namespace std;

typedef long long Int;

Int mem[20000001];

bool Prime(Int num)
{
    Int i;
    if (num==1)
    return false;
    for (i=2;i*i<=num;i++)
    {
        if (num%i==0)
        return false;
    }
    return true;
}

Int Calc(Int num)
{
    Int i;
    Int calc1,calc2;
    Int max=-1;
    
    if (num<=20000000)
    if (mem[num]!=-1)
    return mem[num];
    
    if (num==1)
    return 0;
    
    if ( Prime(num) )
    {
        if (num<=20000000)
        mem[num]=1;
        return 1;
    }
    
    
    
    for (i=2;i*i<=num;i++)
    {
        if (num%i!=0)
        continue;
        
        calc1=Calc(i);
        calc2=Calc(num/i);
        
        if (i+calc1>max)
        max=i+calc1;
        
        if (num/i + calc2>max)
        max=num/i + calc2;
    }
    if (num<=20000000)
    mem[num]=max;
    return max;
}

int main()
{
    Int n;
    Int i;
    for (i=0;i<=20000000;i++)
    mem[i]=-1;
    cin>>n;
    cout<<n+Calc(n)<<endl;
    return 0;
}