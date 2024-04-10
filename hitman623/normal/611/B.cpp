#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a,b,l=0,i,m=0,an=0;
    char c[100],d[100];
    cin>>a>>b;
    while(a!=0)
    {
        if(a%2==0) c[l++]='0';
        else c[l++]='1';
        a/=2;
    }
    c[l]=0;
    strrev(c);
    while(b!=0)
    {
        if(b%2==0) d[m++]='0';
        else d[m++]='1';
        b/=2;
    }
    d[m]=0;
    strrev(d);
    //cout<<c<<endl<<d<<endl;
    if(l!=m)
    {  an=0;
        for(i=0;i<l;++i)
    if(c[i]=='0') {an=l-i;break;}
    if(m-2-l>=0)
    {
       an+=(m-l-1)*l+((m-l-2)*(m-l-1))/2;
    }
    for(i=1;i<m;++i)
    {
        if(d[i]!='1') break;
    }
    an+=i-1;
    a=0;
    for(i=0;i<m;++i)
            if(d[i]=='0') a++;
    if(a==1) an++;
    cout<<an;
    }
    else
    {    a=0;
        for(i=0;i<m;++i)
            if(d[i]=='0') a++;
           // if(a>1) {cout<<0;exit(0);}
            if(a==1)an=1;else an=0;
        for(i=0;i<l;++i)
    if(c[i]=='0') {b=i;break;}
    if(i==l)b=i;
       for(i=0;i<m;++i)
    {
        if(d[i]!='1') break;
    }
    if(i-b>=0) an+=i-b;
    cout<<an;
    }
    return 0;
}