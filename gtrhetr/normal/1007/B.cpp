#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll ans;
int have[10][10],len[10];
int id[10][10];
int g[100010][8];
short f[100010][8];
int h4[100010],h5[100010],h6[100010],t4,t5,t6;
int h1[100010],h2[100010],h3[100010],h[100010],H[100010],num[100010],t1,t2,t3,tt;
int to[10][10],t,a,b,c;
bool bo[10][10];

char buf[1000010],*cur=buf+1000010;

inline char getc()
{
	(cur==buf+1000010)?fread(cur=buf,1,1000010,stdin):0;
	return *(cur++);
}

inline ll rd()
{
	ll x=0,f=1;char ch=getc();
	for (;ch<'0'||ch>'9';ch=getc()) if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getc()) x=x*10+ch-'0';
	return x*f;
}

char buff[1000010],*curr=buff;

inline void flush() { fwrite(buff,1,curr-buff,stdout); }

inline void putc(const char &ch)
{
	(curr==buff+1000010)?fwrite(curr=buff,1,1000010,stdout):0;
	*curr++=ch;
}

inline void print(ll x)
{
	static char s[233];
	if (!x) { putc('0');putc('\n');return; }
	int tot=0;
	for (;x;x/=10) s[++tot]=x%10+'0';
	for (;tot;tot--) putc(s[tot]);
	putc('\n');
}

inline void gao2(int *a,int *b,int *c,int t1,int t2,int t3)
{
	int now1=0,now2=0;
	for (int i=1;i<=t3;i++)
	{
		while (now1<t1&&a[now1+1]<=c[i]) now1++;
		while (now2<t2&&b[now2+1]<=c[i]) now2++;
		if (a[now1]==c[i]&&b[now2]==c[i]) ans++;
	}
}

inline int calc(int x,int y)
{
	int res=0;
	for (register int i=1;i<=3;i++) for (register int j=i+1;j<=3;j++) if (((((1<<(i-1))&x)&&((1<<(j-1))&y))||(((1<<(i-1))&y)&&((1<<(j-1))&x)))) res|=(1<<(id[i][j]-1));
	return res;
}

inline bool check(int x,int y)
{
	if ((x&1)&&(y&4)) return true;
	if ((x&2)&&(y&1)) return true;
	if ((x&4)&&(y&2)) return true;
	return false;
}

int main()
{
	t=rd();
	id[1][2]=1;id[2][3]=2;id[1][3]=3;
	for (int i=0;i<8;i++) for (int j=0;j<8;j++) to[j][i]=calc(i,j),bo[i][j]=check(i,j);
	for (int i=0;i<8;i++) for (int j=0;j<8;j++) if (bo[j][i]) have[i][++len[i]]=j;
	while (t--)
	{
		a=rd();b=rd();c=rd();
		t1=t2=t3=t4=t5=t6=0;
		for (int i=1;i*i<=a;i++) if (a%i==0)
		{
			h1[++t1]=i;
			if (i*i!=a) h4[++t4]=a/i;
		}
		for (int i=1;i*i<=b;i++) if (b%i==0)
		{
			h2[++t2]=i;
			if (i*i!=b) h5[++t5]=b/i;
		}
		for (int i=1;i*i<=c;i++) if (c%i==0)
		{
			h3[++t3]=i;
			if (i*i!=c) h6[++t6]=c/i;
		}
		for (int i=t4;i;i--) h1[++t1]=h4[i];
		for (int i=t5;i;i--) h2[++t2]=h5[i];
		for (int i=t6;i;i--) h3[++t3]=h6[i];
		ans=0;
		gao2(h1,h2,h3,t1,t2,t3);
		tt=0;
		int now1=1,now2=1;
		int ttt=0;
		while (now1<=tt||now2<=t1)
		{
			if (now1<=tt&&now2<=t1&&h[now1]==h1[now2]) { now2++;continue; }
			if (now1>tt) H[++ttt]=h1[now2++];
			else if (now2>t1) H[++ttt]=h[now1++];
			else if (h[now1]<h1[now2]) H[++ttt]=h[now1++];
			else H[++ttt]=h1[now2++];
		}
		tt=ttt;
		for (int i=1;i<=tt;i++) h[i]=H[i];
		now1=1,now2=1;
		ttt=0;
		while (now1<=tt||now2<=t2)
		{
			if (now1<=tt&&now2<=t2&&h[now1]==h2[now2]) { now2++;continue; }
			if (now1>tt) H[++ttt]=h2[now2++];
			else if (now2>t2) H[++ttt]=h[now1++];
			else if (h[now1]<h2[now2]) H[++ttt]=h[now1++];
			else H[++ttt]=h2[now2++];
		}
		tt=ttt;
		for (int i=1;i<=tt;i++) h[i]=H[i];
		now1=1,now2=1;
		ttt=0;
		while (now1<=tt||now2<=t3)
		{
			if (now1<=tt&&now2<=t3&&h[now1]==h3[now2]) { now2++;continue; }
			if (now1>tt) H[++ttt]=h3[now2++];
			else if (now2>t3) H[++ttt]=h[now1++];
			else if (h[now1]<h3[now2]) H[++ttt]=h[now1++];
			else H[++ttt]=h3[now2++];
		}
		tt=ttt;
		for (int i=1;i<=tt;i++) h[i]=H[i];
		for (int i=0;i<=tt;i++) memset(f[i],0,sizeof(f[i])),memset(g[i],0,sizeof(g[i]));
		for (int i=0;i<=tt;i++) num[i]=0;
		int now=0;
		for (int i=1;i<=t1;i++)
		{
			while (now<tt&&h[now+1]<=h1[i]) now++;
			num[now]|=1;
		}
		now=0;
		for (int i=1;i<=t2;i++)
		{
			while (now<tt&&h[now+1]<=h2[i]) now++;
			num[now]|=2;
		}
		now=0;
		for (int i=1;i<=t3;i++)
		{
			while (now<tt&&h[now+1]<=h3[i]) now++;
			num[now]|=4;
		}
		for (int i=1;i<=tt;i++)
		{
			for (register int j=1;j<=len[num[i]];j++) ans+=g[i-1][have[num[i]][j]];
			memcpy(f[i],f[i-1],sizeof(f[i]));
			memcpy(g[i],g[i-1],sizeof(g[i]));
			for (register int j=0;j<8;j++) g[i][to[num[i]][j]]+=f[i-1][j];
			f[i][num[i]]++;
		}
		for (int i=0;i<=tt;i++) memset(f[i],0,sizeof(f[i]));
		for (int i=1;i<=tt;i++)
		{
			for (register int j=1;j<=len[num[i]];j++) ans+=f[i-1][have[num[i]][j]];
			memcpy(f[i],f[i-1],sizeof(f[i]));
			f[i][to[num[i]][num[i]]]++;
		}
		reverse(h+1,h+tt+1);
		reverse(num+1,num+tt+1);
		for (int i=0;i<=tt;i++) memset(f[i],0,sizeof(f[i]));
		for (int i=1;i<=tt;i++)
		{
			for (register int j=1;j<=len[num[i]];j++) ans+=f[i-1][have[num[i]][j]];
			memcpy(f[i],f[i-1],sizeof(f[i]));
			f[i][to[num[i]][num[i]]]++;
		}
		print(ans);
	}
	flush();
	return 0;
}