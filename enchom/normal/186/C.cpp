#include <iostream>
using namespace std;

long long MOD=1000000007;

long long POWER(long long k,long long p)
{
    long long answer;
    
    if (p==0)
    return 1;
    if (p==1)
    return k%MOD;
    if (p==2)
    return (k*k)%MOD;
    
    if (p%2==0)
    {
        answer=POWER(k,p/2);
        return (answer*answer)%MOD;
    }
    else
    {
        answer=POWER(k,(p-1)/2 );
        answer=(answer*answer)%MOD;
        return (answer*k)%MOD;
    }
}

int main()
{
    long long n;
    long long ans;
    long long power21,power22;
    
    cin>>n;
    n++;
    
    if (n==1)
    {
        cout<<1<<endl;
        return 0;
    }
    
    ans=POWER(4,n-1);
    power21=POWER(2,2*n-3);
    power22=POWER(2,n-2);
    
    if (power21<power22)
    power21+=MOD;
    
    ans=ans-(power21-power22);
    
    if (ans<0)
    ans=ans+MOD;
    
    ans=ans%MOD;
    
    cout<<ans<<endl;
    
    return 0;
}