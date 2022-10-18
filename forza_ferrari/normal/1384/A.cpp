#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,a[101],maxn;
string s1,s2;
int main()
{
    cin>>t;
    while(t--)
    {
        maxn=0;
        s1=s2="";
        cin>>n;
        for(register int i=1;i<=n;++i)
        {
            cin>>a[i];
            maxn=max(a[i],maxn);
        }
        ++maxn;
        for(register int i=1;i<=maxn;++i)
            s2+='a';
        cout<<s2<<endl;
        for(register int i=1;i<=n;++i)
        {
            s1=s2;
            if(s2[a[i]]=='z')
                s2[a[i]]='a';
            else
                ++s2[a[i]];
            cout<<s2<<endl;
        }
    }
    return 0;
}