#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,sum[2];
inline int calc1(int a,int b)
{
    int p=1,res=0;
    while(a||b)
    {
        int x=a%k,y=b%k;
        a/=k,b/=k;
        res+=(x+y)%k*p;
        p*=k;
    }
    return res;
}
inline int calc2(int a,int b)
{
    int p=1,res=0;
    while(a||b)
    {
        int x=a%k,y=b%k;
        a/=k,b/=k;
        res+=(x-y+k)%k*p;
        p*=k;
    }
    return res;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        sum[0]=sum[1]=0;
        for(register int i=0;i<n;++i)
        {
            if(i&1)
            {
                cout<<calc2(sum[0],calc1(sum[1],i))<<endl;
                sum[1]=calc1(sum[1],calc2(sum[0],calc1(sum[1],i)));
            }
            else
            {
                cout<<calc2(calc1(sum[1],i),sum[0])<<endl;
                sum[0]=calc1(sum[0],calc2(calc1(sum[1],i),sum[0]));
            }
            int x;
            cin>>x;
            if(x)
                break;
        }
    }
    return 0;
}