#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
	int x = 0 , f = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1;  ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}
int c[200005][26],step[200005],fail[200005];
long long val[200005];long long sum[200005];
char s[200005];
int cnt=1,last=1,n;

void ins(int x)
{
    int p=last,np=++cnt;step[np]=step[last]+1;val[np]=1;
    for(;p&&!c[p][x];p=fail[p])c[p][x]=np;
    if(!p)fail[np]=1;
    else
    {
        int q=c[p][x];
        if(step[q]==step[p]+1) fail[np]=q;
        else
        {
            int nq=++cnt;step[nq]=step[p]+1;
            for(int i=0;i<26;i++)c[nq][i]=c[q][i];
            fail[nq]=fail[q];fail[q]=fail[np]=nq;
            for(;c[p][x]==q;p=fail[p])c[p][x]=nq;
        }
    }
    last=np;
}

int v[200005],rk[200005];
void work()
{
	memset(v,0,sizeof(v));
    for(int i=1;i<=cnt;i++)v[step[i]]++;
    for(int i=1;i<=n;i++)v[i]+=v[i-1];
    for(int i=cnt;i;i--) rk[v[step[i]]--]=i;
    for(int i=cnt;i;i--) val[fail[rk[i]]]+=val[rk[i]];
}

//char q[111111],top=0;;
bool vis[200000];

long long Dfs(int x)
{
	if(vis[x]) return sum[x];
	if(x!=1)sum[x]=1LL*val[x]*val[x];vis[x]=1; 
//	for(int i=1;i<=top;++i) cout<<q[i];cout<<" = "<<x<<" "<<val[x]<<endl;
	for(int i=0;i<26;++i) if(c[x][i])// q[++top]=(char)(i+'a'),
	sum[x]+=Dfs(c[x][i]);	
//	--top;
	return sum[x];
}

int main()
{
	for(int T=read();T;--T)
	{
		memset(c,0,sizeof(c));		
		memset(fail,0,sizeof(fail)); 
		memset(step,0,sizeof(step));
		memset(vis,0,sizeof(vis));
		memset(sum,0,sizeof(sum));
		memset(val,0,sizeof(val));
		cnt=last=1;
    	scanf("%s",s+1);n=strlen(s+1);
    	for(int i=1;s[i];ins(s[i++]-'a'));
  //  scanf("%d%d",&T,&k);
    	work();
    	cout<<Dfs(1)<<endl;
	}
    return 0;
}