#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int T,n;
string s,t;
vector<int> v[3];
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>s>>t;
        s=" "+s;
        t=" "+t;
        v[0].clear(),v[1].clear(),v[2].clear();
        string qs,qt;
        for(int i=1;i<=n;++i)
        {
            v[s[i]-'a'].emplace_back(i);
            if(s[i]!='b')
                qs.push_back(s[i]);
            if(t[i]!='b')
                qt.push_back(t[i]);
        }
        if(qs!=qt)
        {
            cout<<"NO\n";
            continue;
        }
        int cnt[3]={0};
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(t[i]=='a')
                if(v[0][cnt[0]++]>i)
                {
                    flag=0;
                    break;
                }
            if(t[i]=='c')
                if(v[2][cnt[2]++]<i)
                {
                    flag=0;
                    break;
                }
        }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}