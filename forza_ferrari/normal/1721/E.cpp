#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,pi[1000101],val[1000101][26];
string s,t;
int main()
{
    cin>>s>>m;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;++i)
    {
        pi[i]=val[i-1][s[i]-'a'];
        for(int j=0;j<26;++j)
            val[i][j]=val[pi[i]][j];
        val[i][s[pi[i]+1]-'a']=pi[i]+1;
    }
    while(m--)
    {
        cin>>t;
        int len=t.length();
        s+=t;
        for(int i=n+1;i<=n+len;++i)
        {
            cout<<(pi[i]=val[i-1][s[i]-'a'])<<" ";
            for(int j=0;j<26;++j)
                val[i][j]=val[pi[i]][j];
            val[i][s[pi[i]+1]-'a']=pi[i]+1;
        }
        cout<<'\n';
        for(int i=1;i<=len;++i)
            s.pop_back();
    }
    return 0;
}