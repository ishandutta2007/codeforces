#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 2000000000
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int a[15];
int n,m,len2;
int len[1005];
int b[1005];
char s[1005],s2[1005];
int x[1005][1005];
int f[1005][1005];
int sa[1005][1005];
int rk[1005][1005];
int v[1002];
void sort()
{
	for(int i=1;i<=n;i++) rk[0][i]=INF;
	for(int i=1;i<=n;i++) sa[0][i]=i;
	for(int i=1;i<=m;i++)
	{
		memset(v,0,sizeof(v));
		for(int j=1;j<=n;j++) v[x[j][i]]++;
		for(int j=9;j>=0;j--) v[j]+=v[j+1];
		for(int j=n;j;j--) rk[i][sa[i-1][j]]=v[x[sa[i-1][j]][i]]--;
		for(int j=1;j<=n;j++) sa[i][rk[i][j]]=j;
	}
//	for(int i=1;i<=m;i++)
//		for(int j=1;j<=n;j++)
	//	//	cout<<i<<" "<<j<<" "<<rk[i][j]<<endl;
}

int work(int k,int ad,int&tot)
{
	int en=n,fn=0,i;
	for(register int ii=1;ii<=n;ii++)
	{
		i=sa[k][ii];b[i]=0;
		int xx=x[i][k]+ad;
		if(en==n&&xx<10) en=ii-1;
		if(k>len2&&len[i]<k&&xx==0) continue;
		fn+=a[xx%10];tot+=(xx>=10);b[i]=xx;
	}
	if(f[k-1][0]>=0) f[k][en]=max(f[k][en],f[k-1][0]+fn);
//	cout<<k<<" "<<ad<<" "<<en<<" "<<fn<<" "<<tot<<endl;
	return fn;
}

void ins(int i,int j,int ad,int&num,int&into)
{
	//cout<<"ins"<<i<<" "<<j<<" "<<ad<<" "<<num<<" "<<into<<endl;
	int xx=x[j][i]+ad;
	num=num-a[xx%10]+a[(xx+1)%10];
	if(i>len2&&i>len[j]&&b[j]==0)
		num+=a[xx%10];
	into+=(xx==9);
}

int main()
{
	m=1000;
	scanf("%s",s+1);len2=strlen(s+1);
	for(int i=len2,j=1;i;i--,j++) s2[j]=s[i];
	for(int i=len2+1;i<=m;i++) s2[i]='0';
	n=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);len[i]=strlen(s+1);
		for(int j=len[i],k=1;j;j--,k++)
			x[i][k]=s[j]-'0';
	}
	for(int i=0;i<10;i++) a[i]=read();
	sort();
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++) f[i][j]=-INF;
	f[0][0]=0;
	for(register int i=1;i<=m;i++)
	{
		if(s2[i]=='?')
		{
			for(register int th=0;th<10;th++)
			{
				if(th==0&&i==len2) continue;
				int into=0;
				int num=work(i,th,into);
				for(register int j=1;j<=n;j++)
				{
					ins(i,sa[i-1][j],th,num,into);
					if(f[i-1][j]>=0) 
					{
						f[i][into]=max(f[i][into],f[i-1][j]+num);
					}
				}
			}
		}
		else 
		{
			int th=s2[i]-'0';
			int into=0;
			int num=work(i,th,into);
			for(register int j=1;j<=n;j++)
			{
				ins(i,sa[i-1][j],th,num,into);
				if(f[i-1][j]>=0) 
					f[i][into]=max(f[i][into],f[i-1][j]+num);
			}
		}
	}
	int ans=0;
	for(register int i=0;i<=n;i++) ans=max(ans,f[m][i]+i*a[1]);
	printf("%d",ans);
	return 0;
}