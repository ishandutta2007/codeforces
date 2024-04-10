#include<cstdio>
#include<iostream>
#include<cstring>
int a[20];
int v[200];
int n,ans;
char s[200][2];
int check()
{
    for (int i=1;i<=n;i++)
    {
        v[i]=0;
        if (a[s[i][0]-'0']) v[i]+=1<<(s[i][0]-'0');
        if (a[s[i][1]-'0']) v[i]+=1<<(s[i][1]-'0');
    }
    for (int i=1;i<=n;i++)
    for (int j=i+1;j<=n;j++)
    if (v[i]==v[j]&&(s[i][0]!=s[j][0]||s[i][1]!=s[j][1])) return 0;
    return 1;
}
void dfs(int i,int j)
{
    if (i==11) 
    {
        if (check()&&j<=ans) ans=j;
        return;
    }
    a[i]=1;dfs(i+1,j+1);
    
    a[i]=0;dfs(i+1,j);
}
int main()
{
    scanf("%d",&n);
    ans=0;
    for (int i=1;i<=n;i++) 
    {
        scanf("%s",s[i]);s[i][1]+=5;
        int c=s[i][0];int c2;
        if (c=='R') c2='1';
        if (c=='B') c2='2';
        if (c=='G') c2='3';
        if (c=='W') c2='4';
        if (c=='Y') c2='5';
        s[i][0]=c2;
        if (!v[s[i][0]]) ans++;
        if (!v[s[i][1]]) ans++;
        v[s[i][0]]=1;v[s[i][1]]=1;
    }
    ans-=2;
    memset(v,0,sizeof(v));
    dfs(1,0);
    printf("%d\n",ans);
    return 0;
}