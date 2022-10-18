#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,cnt[10];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        s=" "+s;
        for(int i=0;i<10;++i)
            cnt[i]=0;
        int p=0;
        for(int i=0;i<10;++i)
        {
            for(int j=p+1;j<=n;++j)
                if(s[j]-'0'==i)
                {
                    cout<<i;
                    for(int k=p+1;k<j;++k)
                        ++cnt[min(s[k]-'0'+1,9)];
                    p=j;
                }
            while(cnt[i]--)
                cout<<i;
        }
        cout<<'\n';
    }
    return 0;
}