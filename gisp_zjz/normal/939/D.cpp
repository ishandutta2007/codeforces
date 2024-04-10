#include<bits/stdc++.h>
#define maxn 304030

using namespace std;
char s[maxn],t[maxn];
int pre[maxn],n,p,q,u,v,ans;
vector <int> h[26];

int ffind(int x)
{
    if (pre[x]!=x) pre[x]=ffind(pre[x]);
    return pre[x];
}

void sub_union(int x,int y)
{
    pre[y]=x;
}

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    scanf("%s",t);
    for (int i=0;i<26;i++) pre[i]=i;
    for (int i=0;i<n;i++)
    {
        u=ffind(s[i]-'a');
        v=ffind(t[i]-'a');
        if (u!=v) sub_union(u,v);
    }
    ans=26;
    for (int i=0;i<26;i++) ans-=(ffind(i)==i);
    printf("%d\n",ans);
    for (int i=0;i<26;i++) h[ffind(i)].push_back(i);
    for (int i=0;i<26;i++)
        if (h[i].size()>1)
        for (int j=0;j<h[i].size()-1;j++)
            printf("%c %c\n",'a'+char(h[i][j]),'a'+char(h[i][j+1]));
    return 0;
}