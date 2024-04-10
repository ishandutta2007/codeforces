#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
string s,t,str;
int n,pi[125001<<1],ans[125001],cnt;
map<char,int> p;
char c[6];
inline void kmp()
{
    pi[1]=0;
    bool flag=0;
    for(int i=2;i<(int)str.length();++i)
    {
        int j=pi[i-1];
        while(j>0&&p[str[i]]!=p[str[j+1]])
            j=pi[j];
        if(p[str[i]]==p[str[j+1]])
            ++j;
        pi[i]=j;
        if(str[i]=='#')
            flag=1;
        if(flag&&pi[i]==n)
            ans[i-n-n]=min(ans[i-n-n],6-cnt);
    }
}
inline void dfs(char k)
{
    if(k>'f')
    {
        kmp();
        return;
    }
    p[k]=k;
    c[++cnt]=k;
    dfs(k+1);
    --cnt;
    for(int i=1;i<=cnt;++i)
    {
        p[k]=c[i];
        dfs(k+1);
    }
}
int main()
{
    cin>>s>>t;
    n=t.length();
    p['#']='#';
    str=" "+t+"#"+s;
    for(int i=1;i<=s.length()-t.length()+1;++i)
        ans[i]=1e9;
    dfs('a');
    for(int i=1;i<=s.length()-t.length()+1;++i)
        cout<<ans[i]<<" ";
    cout<<'\n';
    return 0;
}