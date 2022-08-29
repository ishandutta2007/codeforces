#include<cstdio>
#include<cstring>
#define re register
using namespace std;
struct node{
    int ch[26];
    int len,fa;
}p[1000002];
struct edge{
    int to,next;
}e[1000002];
int head[400002],cnt,n,tot,l;
inline void add(re int x,re int y){
    e[++cnt].to=y;
    e[cnt].next=head[x];
    head[x]=cnt;
}
long long a[400002],ans;
inline long long max(re long long x,re long long y){
	return x>y?x:y; 
}
inline void insert(re int c,re int o){
    re int x=l,np=l=++tot;a[tot]=o;
    p[np].len=p[x].len+1;
    for(;x&&!p[x].ch[c];x=p[x].fa)p[x].ch[c]=np;
    if(!x)p[np].fa=1;
    else{
        re int q=p[x].ch[c];
        if(p[x].len==p[x].len+1)p[np].fa=q;
        else
        {
            re int nq=++tot;
            p[nq]=p[q];p[nq].len=p[x].len+1;
            p[q].fa=p[np].fa=nq;
            for(;x&&p[x].ch[c]==q;x=p[x].fa)p[x].ch[c]=nq;
        }
    }
}
char s[2000010],s1[200002];
inline void dfs(re int x)
{
    for(re int i=head[x];i;i=e[i].next)
    {
        dfs(e[i].to);
        a[x]+=a[e[i].to];
    }
    ans=max(ans,a[x]*p[x].len);
}
int main(){
	tot=l=1;
    scanf("%d%s%s",&n,s,s1);
    for(re int i=0;i<n;++i)insert(s[i]-'a',(s1[i]-'0')^1);
    for(re int i=2;i<=tot;++i)add(p[i].fa,i);
    dfs(1);
    printf("%lld",ans);
}