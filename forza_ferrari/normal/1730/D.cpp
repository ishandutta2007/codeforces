#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int t,n;
string a,b;
map<int,int> mp;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>a>>b;
        mp.clear();
        a=" "+a;
        b=" "+b;
        for(int i=1;i<=n;++i)
        {
            int x=min(a[i]-'a',b[n-i+1]-'a'),y=max(a[i]-'a',b[n-i+1]-'a');
            ++mp[x*100+y];
        }
        bool flag=1;
        int cnt=0;
        for(auto i:mp)
            if(i.second&1)
            {
                if(i.first%100!=i.first/100)
                {
                    flag=0;
                    break;
                }
                ++cnt;
            }
        cout<<(flag&&cnt<=1? "YES":"NO")<<'\n';
    }
    return 0;
}