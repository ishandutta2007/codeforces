#include<iostream>
#include<cstdio>
using namespace std;
long long n,p,w,d;
int main()
{
    cin>>n>>p>>w>>d;
    for(register int i=0;i<=w&&d*i<=p;++i)
        if((p-d*i)%w==0&&(p-d*i)/w+i<=n)
        {
            cout<<(p-d*i)/w<<" "<<i<<" "<<n-(p-d*i)/w-i<<endl;
            return 0;
        }
    cout<<-1<<endl;
    return 0;
}