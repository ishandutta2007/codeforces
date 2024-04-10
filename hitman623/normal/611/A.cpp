#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[100];
    int f=0,n=0,i=0;
    gets(a);
    for(i=0;i<strlen(a);++i)
        if(a[i]=='w') f=1;
    if(a[i+1]=='w') f=1;
    if(f==1)
    {
        if(a[0]=='5' || a[0]=='6') cout<<53;
        else cout<<52;
    }
    else
    {
        n=a[0]-'0';
        if(a[1]!=' ') n=n*10+a[1]-'0';
        if(n<=29) cout<<12;
        else if(n==30) cout<<11;
        else cout<<7;
    }
    return 0;
}