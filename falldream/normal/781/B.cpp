#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#define ll long long
using namespace std;
inline int read()
{
   int  x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}
int n,dn=0;
char ch[10005][5];
char s[10005];
int h1[10005],h2[10005],q[20005];
bool inq[10005];
struct edge{
    int to,next;
}e[8000000];
int head[10005],dfn[10005],low[10005],bel[10005],col[10005],in[10005];
int cnt=0,cc,top=0,cft[10005];
queue<int> qu;

void ins(int f,int t)
{
    e[++cnt].next=head[f];head[f]=cnt;
    e[cnt].to=t;
}

void hashh(int k)
{
 //   cout<<k<<" "<<ch[k][1]<<" "<<ch[k][2]<<" "<<ch[k][3]<<" "<<ch[k][4]<<endl;
    int hash1,hash2;
    hash1=hash2=(ch[k][1]-'A')*26+ch[k][2]-'A';
    hash1=hash1*26+(ch[k][3]-'A');
    hash2=hash2*26+(ch[k][4]-'A');
    h1[k]=hash1;h2[k]=hash2;
}

void tj(int x)
{
    //cout<<"tj"<<x<<endl;
    dfn[x]=low[x]=++dn;inq[x]=1;q[++top]=x;
    for(int i=head[x];i;i=e[i].next)
    {
        int v=e[i].to;
        if(!dfn[v]){tj(v);low[x]=min(low[x],low[v]);}
        else {if(inq[v])low[x]=min(low[x],dfn[v]);}
    }
    if(dfn[x]==low[x])
        for(++cc;q[top+1]!=x;bel[q[top]]=cc,inq[q[top]]=0,top--);
}

void rebuild()
{
    for(int i=1;i<=n<<1;i++)
        for(int j=head[i];j;j=e[j].next)
            if(bel[i]!=bel[e[j].to])
                ins(bel[i],bel[e[j].to]),in[e[j].to]++;
}

void topsort()
{
    for(int i=n*2+1;i<=cc;i++)
        if(in[i]==0) qu.push(i);
    while(!qu.empty())
    {
        int u=qu.front();qu.pop();
        if(!col[u])
			for(int j=1;j<=n<<1;j++)
			   if(bel[j]==u)
			       col[bel[j>n?j-n:j+n]]=1;	
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            --in[v];
            if(!in[v]) qu.push(v);
        }
    }
}

int main()
{
    n=read();cc=n<<1;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);
        ch[i][1]=s[1];ch[i][2]=s[2];ch[i][3]=s[3];
        scanf("%s",s+1);ch[i][4]=s[1];
        hashh(i);
    }
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(h1[i]==h1[j]&&h2[i]==h2[j]) return 0*puts("NO");
            if(h1[i]==h1[j]){ins(i,j+n);ins(j,i+n);ins(i+n,j+n);ins(j+n,i+n);}
            if(h1[i]==h2[j]){ins(i,j);ins(j+n,i+n);}
            if(h2[i]==h1[j]){ins(i+n,j+n);ins(j,i);}
            if(h2[i]==h2[j]){ins(i+n,j);ins(j+n,i);}
        }
    for(int i=1;i<=n*2;i++)if(!dfn[i])tj(i);
    //for(int i=1;i<=n;i++)cout<<bel[i]<<" "<<bel[i+n]<<endl;
    for(int i=1;i<=n;i++)if(bel[i]==bel[i+n])return 0*puts("NO");
    rebuild();
    topsort();
    puts("YES");
    for(int i=1;i<=n;i++)if(col[bel[i]]==0)printf("%c%c%c\n",ch[i][1],ch[i][2],ch[i][3]);
    else printf("%c%c%c\n",ch[i][1],ch[i][2],ch[i][4]);
    return 0;
}