#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
#define Maxn 5005
char s[Maxn];
int ch[Maxn][26],fa[Maxn],l=0;
int trans[Maxn],fail[Maxn],len[Maxn];
int last=1,tot=1;
int cnt[Maxn];
int f[Maxn];
ll ans[Maxn];

inline int getfail(int x){
    while(s[l-len[x]-1]!=s[l])x=fail[x];
    return x;
}
inline int gethalf(int x,int p){
    while(s[l-len[x]-1]!=s[l]||len[x]>p)x=fail[x];
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
        if(len[tot]<=2)trans[tot]=fail[tot];
        else trans[tot]=ch[gethalf(trans[tmp],(len[tot]>>1)-2)][dir];
        ch[tmp][dir]=tot;
    }
    last=ch[tmp][dir];
    cnt[last]++;
}

inline void solve(){
    for(register int i=tot;i>=2;--i)cnt[fail[i]]+=cnt[i];
    for(register int i=2;i<=tot;++i){
        if(trans[i]>1&&len[trans[i]]==len[i]/2)f[i]=f[trans[i]]+1;
        else f[i]=1;
        ans[f[i]]+=cnt[i];
    }
}

int main(){
    memset(ch[0],0,sizeof(ch[0]));
    memset(ch[1],0,sizeof(ch[1]));
    fail[0]=trans[0]=1;
    len[1]=-1;
    s[0]=-1;
    scanf("%s",s+1);
    n=strlen(s+1);
    for(register int i=1;i<=n;++i)insert(s[i]-'a');
    solve();
    for(register int i=23;i>=1;--i)ans[i]+=ans[i+1];
    for(register int i=1;i<=n&&i<=23;++i)printf("%lld ",ans[i]);
    for(register int i=24;i<=n;++i)printf("%lld ",ans[i]);
    return 0;
}