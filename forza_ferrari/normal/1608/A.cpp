#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
inline bool prime(int x)
{
    if(x==2)
        return 1;
    for(int i=2;i*i<=x;++i)
        if(x%i==0)
            return 0;
    return 1;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int cnt=1,num=2;
        while(cnt<=n)
        {
            if(prime(num))
            {
                cout<<num<<" ";
                ++cnt;
            }
            ++num;
        }
        cout<<endl;
    }
    return 0;
}