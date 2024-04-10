#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,cnt[2],pi[500001];
string s,ans;
int main()
{
    cin>>s;
    m=s.length();
    for(int i=0;i<m;++i)
        ++cnt[s[i]-'0'];
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=2;i<=n;++i)
    {
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j+1])
            j=pi[j];
        if(s[i]==s[j+1])
            ++j;
        pi[i]=j;
    }
    int p=0;
    for(int i=1;i<=m;++i)
    {
        while(p>0&&!cnt[s[p+1]-'0'])
            p=pi[p];
        if(!cnt[s[p+1]-'0'])
        {
            ans.push_back(((s[p+1]-'0')^1)+'0');
            --cnt[(s[p+1]-'0')^1];
            p=0;
        }
        else
        {
            ans.push_back(s[p+1]);
            --cnt[s[p+1]-'0'];
            ++p;
            if(p==n)
                p=pi[p];
        }
    }
    cout<<ans<<'\n';
    return 0;
}