#include <bits/stdc++.h>

using namespace std;

long long n,i,m=1000000007;
int check(string a)
{
    long i,m,f=0;
    m=a.length();
    for(i=0;i<m;++i)
        {
            if((a[i]!='0' && a[i]!='1') || (a[i]=='1' && f==1))
        return 0;
        if(a[i]=='1') f=1;}
    return 1;
}
int str(long a)
{
    if(a/100000) return 5;
    if(a/10000) return 4;
    if(a/1000) return 3;
    if(a/100) return 2;
    if(a/10) return 1;
    return 0;
}
int main()
{
    char p[100005],x[100005];
    vector <string> a;
    long l=0,s=0;
    cin>>n;
    for(i=0;i<n;++i)
        {cin>>x;
        a.push_back(x);}
    for(i=0;i<n;++i)
    {
        if(a[i][0]=='0') {cout<<0;exit(0);}
        if(check(a[i]))
        {
            s=a[i].length()-1;
            while(s--)
            p[l++]='0';
        }
        else m=i;
    }
    p[l]=0;
    //cout<<m<<" "<<p<<endl;
    if(m==1000000007) m=-1;
    if(m!=-1) cout<<a[m];
    else cout<<1;
    cout<<p;
    return 0;
}