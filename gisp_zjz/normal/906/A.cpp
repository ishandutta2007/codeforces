#include<bits/stdc++.h>
#define maxn 30

using namespace std;

int n,m;
bool f[maxn],g[maxn],h;
char s[200000],c[1];
int ans,cnt;

int main()
{
    scanf("%d",&n); ans=0; cnt=26;
    memset(f,true,sizeof(f));
    while (n--)
    {
        scanf("%s",c);scanf("%s",s);m=strlen(s);
        if (c[0]=='!'){
            if (cnt==1) ans++;
            memset(g,false,sizeof(g));
            for (int i=0;i<m;i++) g[s[i]-'a']=true;
            for (int i=0;i<26;i++) if (f[i]&&!g[i]) f[i]=false,cnt--;
        }
        else if (c[0]=='.'){
            memset(g,true,sizeof(g));
            for (int i=0;i<m;i++) g[s[i]-'a']=false;
            for (int i=0;i<26;i++) if (f[i]&&!g[i]) f[i]=false,cnt--;
        }
        else {
            if (cnt==1&&!f[s[0]-'a']) ans++;
            if (n&&f[s[0]-'a']) f[s[0]-'a']=false,cnt--;
        }
    }
    printf("%d\n",ans);
    return 0;
}