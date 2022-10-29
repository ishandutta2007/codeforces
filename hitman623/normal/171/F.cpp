#include <bits/stdc++.h>
using namespace std;
long long t,a,b,c[5000001],i,j,n,cnt=0,m;
vector <long> s;
long long rev(long long num)
{
    long re=0;
    while(num>0)
    {
        re=re*10+num%10;
        num/=10;
    }
    return re;
}
int main()
{
    cin>>n;
    for(i=0;i<5000001;++i)
        c[i]=1;
        c[0]=0;
        c[1]=0;
    for(i=2;i<5000001;++i)
    {
        if(c[i]==1)
        {
            for(j=2*i;j<5000001;j+=i)
            {
                c[j]=0;
            }
        }
    }
    for(i=10;i<5000001;++i)
    {
        m=rev(i);
        if(c[i] && c[m] && i!=m)
        cnt++;
        if(cnt==n)
        break;
    }
    cout<<i;
    return 0;
}