#include<bits/stdc++.h>
#define maxn 203400

using namespace std;
typedef long long ll;
char s[maxn],p;
int n,m,f[26],a[26],b[26],cnt,t[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s);
    if (m>n){
        p='z';
        for (int i=0;i<n;i++) p=min(p,s[i]);
        printf("%s",s);
        for (int i=n;i<m;i++) printf("%c",p);
        printf("\n");
        return 0;
    }
    for (int i=0;i<n;i++) f[s[i]-'a']=1;
    for (int i=0;i<26;i++) if (f[i]) b[i]=cnt,a[cnt++]=i;
    for (int i=0;i<m;i++) t[i]=b[s[i]-'a']; t[m-1]++;
    int j=m-1; while (t[j]==cnt) t[j]=0,t[--j]++;
    for (int i=0;i<m;i++) printf("%c",'a'+a[t[i]]);
    printf("\n");
    return 0;
}