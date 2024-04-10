#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,m,a[200001];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>s;
        int cnt=0;
        for(int i=0;i<n;++i)
            a[i]=0;
        for(int i=0;i<n;++i)
        {
            if(m==cnt)
                break;
            if((s[i]-'0')==(m&1))
            {
                a[i]=1;
                ++cnt;
            }
        }
        a[n-1]+=m-cnt;
        for(int i=0;i<n;++i)
            if((m-a[i])&1)
                s[i]=((s[i]-'0')^1)+'0';
        cout<<s<<'\n';
        for(int i=0;i<n;++i)
            cout<<a[i]<<" ";
        cout<<'\n';
    }
    return 0;
}