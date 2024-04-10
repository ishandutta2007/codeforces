#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define N 10
#define M 60
#define C 56
using namespace std;
char s[M*2];int l[N];
int id(char c){return c<='Z'?c-'A'+1:c-'a'+27;}
char nid(int c){return c>26?'a'+(c-26)-1:'A'+c-1;}
int nxt[N][M*2][M],pos[N][M*2][2];
string f[M][1<<N];int n;
bool vis[M][1<<N];
string F(int c,int S)
{
    if(vis[c][S]) return f[c][S];
    vis[c][S]=true;f[c][S]="";
    int tmp[N];
    if(c==0) for(int i=0;i<n;i++) tmp[i]=1;
    else for(int i=0;i<n;i++) tmp[i]=pos[i][c][S>>i&1]+1;
    string ans="";
    for(int i=1;i<=C;i++)
    {
        bool can=true;
        for(int j=0;j<n;j++) if(nxt[j][tmp[j]][i]>l[j]){can=false;break;}
        if(!can) continue;
        int T=0;
        for(int j=0;j<n;j++) if(nxt[j][tmp[j]][i]==pos[j][i][1]) T|=1<<j;
        string res=F(i,T);
        if(res.size()+1>ans.size()) ans=nid(i)+res;
    }
    return f[c][S]=ans;
}
int main()
{
    int t;scanf("%d",&t);
    while(t --> 0)
    {
        memset(l,0,sizeof(l));
        memset(vis,0,sizeof(vis));
        memset(nxt,0x3f,sizeof(nxt));
        memset(pos,0x3f,sizeof(pos));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%s",s+1);l[i]=strlen(s+1);
            for(int j=1;j<=l[i];j++) if(pos[i][id(s[j])][0]<=l[i]) pos[i][id(s[j])][1]=j;
            else pos[i][id(s[j])][0]=j;
            for(int j=l[i];j;j--)
            {
                memcpy(nxt[i][j],nxt[i][j+1],sizeof(nxt[i][j]));
                nxt[i][j][id(s[j])]=j;
            }
        }
        string ans=F(0,0);
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    return 0;
}