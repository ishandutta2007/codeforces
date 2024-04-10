#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        if(s[n-1]=='A')
        {
            cout<<"NO\n";
            continue;
        }
        int cnt=0;
        bool flag=1;
        for(int i=0;i<n;++i)
        {
            cnt+=(s[i]=='A'? 1:-1);
            if(cnt<0)
            {
                flag=0;
                break;
            }
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}