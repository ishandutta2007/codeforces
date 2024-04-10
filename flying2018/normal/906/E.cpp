#include<iostream>
#include<cstdio>
#include<cstring>
#define N 1000010
#define C 26
using namespace std;
char s[N],t[N],a[N];
int n,nxt[N],len[N],ch[N][C],las,tot=1;
int get_nxt(int u){while(s[n-len[u]-1]!=s[n]) u=nxt[u];return u;}
int insert(int c)
{
	int u=get_nxt(las);
	if(!ch[u][c])
	{
		nxt[++tot]=ch[get_nxt(nxt[u])][c];
		len[tot]=len[u]+2;
		ch[u][c]=tot;
	}
	return ch[u][c];
}
int f[N],pre[N];
int main()
{
	scanf("%s%s",a+1,t+1);
	int n=strlen(a+1);
	int m=strlen(t+1);
	for(int i=1;i<=n;i++) s[i*2-1]=a[i],s[i*2]=t[i];
	n<<=1;
	for(int i=1;i<=n;i++) f[i]=1000000000;
	len[1]=-1;
	nxt[0]=1;
	for(int i=1;i<=n;i++)
	{
		::n=i;
		las=insert(s[i]-'a');
		if(i&1) continue;
		if(s[i]==s[i-1] && f[i-2]<f[i]) f[i]=f[i-2],pre[i]=i-2;
		for(int j=las;len[j];j=nxt[j])
		if(f[i-len[j]]+1<f[i]) f[i]=f[i-len[j]]+1,pre[i]=i-len[j];
	}
	if(f[n]>=1000000000){puts("-1");return 0;}
	printf("%d\n",f[n]);
	for(int u=n;u;u=pre[u])
	if(pre[u]!=u-2) printf("%d %d\n",(pre[u]+1)/2+1,(u+1)/2);
	return 0;
}