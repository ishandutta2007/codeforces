#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,cnt,sum[1000001][3];
string s;
inline bool check(int len)
{
    for(int i=1,j=len;j<=n;++i,++j)
    {
        int a=sum[j][0]-sum[i-1][0],b=sum[j][1]-sum[i-1][1],c=sum[j][2]-sum[i-1][2];
        if(a>b&&a>c)
            return 1;
    }
    return 0;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        s=" "+s;
        sum[0][0]=sum[0][1]=sum[0][2]=0;
        for(int i=1;i<=n;++i)
        {
            sum[i][0]=sum[i-1][0];
            sum[i][1]=sum[i-1][1];
            sum[i][2]=sum[i-1][2];
            ++sum[i][s[i]-'a'];
        }
        bool flag=0;
        for(int i=2;i<=min(n,200);++i)
            if(check(i))
            {
                flag=1;
                cout<<i<<endl;
                break;
            }
        if(!flag)
            cout<<-1<<endl;
    }
    return 0;
}