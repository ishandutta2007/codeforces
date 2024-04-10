#include<bits/stdc++.h>
#define maxn 1002
using namespace std;
char s[maxn][maxn];
int p[maxn],n,ans,t,f,o,bl;
bool vis[maxn];
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) scanf("%d",&p[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            s[i][j]='.';
    for (int i=1;i<=n;i++) if (p[i]!=i&&!vis[i]){
        int x=i; bl=t+1;
        if (!f) x=p[x],o=i,ans++;
        int st=x; vis[x]=true;
        while (p[x]!=st){
            t++;
            if (p[x]<x) s[t][p[x]]=s[t][x]='\\';
            else s[t][p[x]]=s[t][x]='/';
            x=p[x]; vis[x]=true;
        }
        if (!f) f=1,o=i; else {
            t++;
            s[t][x]=s[t][o]='\\';
            s[bl][o]='/';
        }
    }
    cout << n-ans << endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=n;j++) printf("%c",s[i][j]);
        printf("\n");
    }
    return 0;
}