#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int inf=1e9;
int n;
#define Maxn 1000010
char str1[Maxn],str2[Maxn];
char s[Maxn];
int l=0;
int fa[Maxn],ch[Maxn][26],fail[Maxn];
int len[Maxn];
int anc[Maxn];
int f[Maxn],g[Maxn];
int last=1,tot=1;
int remf[Maxn],remg[Maxn];

inline int getfail(int x){
    while(s[l-len[x]-1]!=s[l])x=fail[x];
    return x;
}
inline void insert(int dir){
    l++;
    int tmp=getfail(last);
    if(!ch[tmp][dir]){
        tot++;
        memset(ch[tot],0,sizeof(ch[tot]));
        len[tot]=len[tmp]+2;fa[tot]=tmp;
        fail[tot]=ch[getfail(fail[tmp])][dir];
        ch[tmp][dir]=tot;
        anc[tot]=((fail[tot]>1&&len[tot]-len[fail[tot]]==len[fail[tot]]-len[fail[fail[tot]]])?anc[fail[tot]]:tot);
    }
    last=ch[tmp][dir];
}

int main(){
    memset(ch[0],0,sizeof(ch[0]));
    memset(ch[1],0,sizeof(ch[1]));
    fail[0]=1;
    len[1]=-1;
    s[0]=-1;
    scanf("%s",str1+1);
    scanf("%s",str2+1);
    n=strlen(str1+1);
    for(register int i=1;i<=n;++i)s[(i<<1)-1]=str1[i];
    for(register int i=1;i<=n;++i)s[i<<1]=str2[i];
    n<<=1;anc[0]=0;anc[1]=1;
    remf[0]=remf[1]=inf;
    for(register int i=1;i<=n;++i){
        f[i]=inf;
        insert(s[i]-'a');
        for(int u=last;u>1;u=fail[anc[u]]){
            remf[u]=f[i-len[anc[u]]];remg[u]=i-len[anc[u]];
            if(anc[u]!=u&&remf[fail[u]]<remf[u])remf[u]=remf[fail[u]],remg[u]=remg[fail[u]];
            if((!(i&1))&&f[i]>remf[u]+1)f[i]=remf[u]+1,g[i]=remg[u];
        }
        if((!(i&1))&&s[i-1]==s[i]&&f[i-2]<f[i])f[i]=f[i-2],g[i]=i-2;
    }
    if(f[n]==inf){puts("-1");return 0;}
    printf("%d\n",f[n]);
    for(int i=n;i;i=g[i])
        if(i-g[i]>2)printf("%d %d\n",(g[i]>>1)+1,i>>1);
    return 0;
}