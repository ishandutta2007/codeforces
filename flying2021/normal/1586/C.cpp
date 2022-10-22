#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 1000010
using namespace std;
string s[N];
int ql[N];
vector<int>q[N];
bool ans[N];
int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    while(t --> 0)
    {
        int n,m;cin>>n>>m;
        s[0].resize(m+1);
        for(int i=1;i<=n;i++) cin>>s[i];
        int Q;cin>>Q;
        for(int i=1,r;i<=Q;i++) cin>>ql[i]>>r,r--,ql[i]--,q[r].push_back(i);
        for(int v:q[0]) ans[v]=true;
        int left=0;
        for(int i=1;i<m;i++)
        {
            bool can=true;
            for(int j=1;j<=n && can;j++)
                if(j!=1 && (s[j-1][i]=='X') && (s[j][i-1]=='X')) can=false;
            if(!can) left=i;
            for(int v:q[i]) ans[v]=(ql[v]>=left);
        }
        for(int i=1;i<=Q;i++) cout<<(ans[i]?"YES":"NO")<<endl;
    }
    return 0;
}