#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int n,q,nxt[100005][26],p[4],lst[26],dp[251][251][251];
bool vis[100001];
string s[4],t;
int main()
{
    cin>>n>>q>>t;
    t=" "+t;
    for(int i=0;i<26;++i)
        nxt[n+1][i]=nxt[n][i]=lst[i]=n+1;
    lst[t[n]-'a']=n;
    for(int i=n-1;i;--i)
    {
        for(int j=0;j<26;++j)
            nxt[i][j]=lst[j];
        lst[t[i]-'a']=i;
    }
    for(int i=0;i<26;++i)
        nxt[0][i]=lst[i];
    for(int i=0;i<=250;++i)
        for(int j=0;j<=250;++j)
            for(int k=0;k<=250;++k)
                dp[i][j][k]=n+1;
    dp[0][0][0]=0;
    s[1].push_back(' ');
    s[2].push_back(' ');
    s[3].push_back(' ');
    while(q--)
    {
        char opt,c;
        int x;
        cin>>opt>>x;
        if(opt=='+')
        {
            cin>>c;
            s[x].push_back(c);
            for(int i=(x==1? (int)s[1].length()-1:0);i<(int)s[1].length();++i)
                for(int j=(x==2? (int)s[2].length()-1:0);j<(int)s[2].length();++j)
                    for(int k=(x==3? (int)s[3].length()-1:0);k<(int)s[3].length();++k)
                    {
                        dp[i][j][k]=n+1;
                        if(i)
                            dp[i][j][k]=min(dp[i][j][k],nxt[dp[i-1][j][k]][s[1][i]-'a']);
                        if(j)
                            dp[i][j][k]=min(dp[i][j][k],nxt[dp[i][j-1][k]][s[2][j]-'a']);
                        if(k)
                            dp[i][j][k]=min(dp[i][j][k],nxt[dp[i][j][k-1]][s[3][k]-'a']);
                    }
        }
        else
            s[x].pop_back();
        cout<<(dp[s[1].length()-1][s[2].length()-1][s[3].length()-1]>n? "NO":"YES")<<endl;
    }
    return 0;
}