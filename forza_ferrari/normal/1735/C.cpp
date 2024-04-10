#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,bin[26],ans[26],cnt;
string s;
bool vis[26];
inline int anc(int k)
{
    if(bin[k]==-1)
        return k;
    return bin[k]=anc(bin[k]);
}
inline void link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        bin[y]=x;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        s=" "+s;
        for(int i=0;i<26;++i)
            ans[i]=bin[i]=-1,vis[i]=0;
        cnt=0;
        for(int i=1;i<=n;++i)
        {
            if(ans[s[i]-'a']==-1)
                for(int j=0;j<26;++j)
                    if(s[i]-'a'!=j&&!vis[j])
                        if(cnt==25||anc(s[i]-'a')!=anc(j))
                        {
                            ans[s[i]-'a']=j;
                            vis[j]=1;
                            ++cnt;
                            link(s[i]-'a',j);
                            break;
                        }
            cout<<(char)(ans[s[i]-'a']+'a');
        }
        cout<<'\n';
    }
    return 0;
}