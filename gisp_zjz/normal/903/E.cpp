#include<bits/stdc++.h>
#define maxn 5020

using namespace std;

char s[maxn][maxn];

int n,m,c[5],r,dis[maxn],a[maxn];
bool f,g;
int cnt[maxn][26];

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%s",s[i]);
    r=0;
    for (int i=1;i<n;i++)
    {
        dis[i]=0;
        for (int j=0;j<m;j++) dis[i]+=(s[0][j]!=s[i][j]);
    }
    memset(cnt,0,sizeof(cnt));g=true;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) cnt[i][s[i][j]-'a']++;
    for (int i=1;i<n;i++) for (int j=0;j<26;j++) if (cnt[i][j]!=cnt[0][j]){printf("-1\n");return 0;}
    for (int i=0;i<26;i++) if (cnt[0][i]>1) g=false;
    for (int i=0;i<m;i++)
    {
        for (int j=i+1;j<m;j++)
        {
            for (int k=1;k<n;k++)
            {
                a[k]=dis[k];
                a[k]-=(s[0][i]!=s[k][i]);
                a[k]-=(s[0][j]!=s[k][j]);
                a[k]+=(s[0][i]!=s[k][j]);
                a[k]+=(s[0][j]!=s[k][i]);
            }
            f=true;
            for (int k=1;k<n;k++) if (a[k]==1||a[k]>2||g&&a[k]==0) f=false;
            if (f){
                swap(s[0][i],s[0][j]);
                printf("%s\n",s[0]);
                return 0;
            }
        }
    }
    printf("-1\n");return 0;
}