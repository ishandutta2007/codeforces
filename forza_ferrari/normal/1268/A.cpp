#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,a[2000001];
string s;
int main()
{
    scanf("%d%d",&n,&m);
    int flag=-1;
    cin>>s;
    s=" "+s;
    for(register int i=1;i<=n;++i)
    {
        a[i]=s[i]-'0';
        if(~flag)
            continue;
        if(a[i]>a[(i-1)%m+1])
            flag=1;
        if(a[i]<a[(i-1)%m+1])
            flag=0;
    }
    printf("%d\n",n);
    if(flag==1)
    {
        for(register int i=m;i;--i)
        {
            ++a[i];
            if(a[i]==10)
                a[i]=0;
            else
                break;
        }
    }
    for(register int i=1;i<=n;++i)
        printf("%d",a[(i-1)%m+1]);
    puts("");
    return 0;
}