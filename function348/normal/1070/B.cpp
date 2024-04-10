#include<cstdio>
#include<iostream>
#include<set>
#include<queue>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
#define FR first
#define SC second
#define MP make_pair
using namespace std;
void upmax(int &a,int b) { if (a<b) a=b;}
void upmin(int &a,int b) { if (a>b) a=b;}
typedef long long LL;
typedef pair<int,int> PII;
//---------------------------------
const int N=400101;
int cas,n,num,ans,flag;
unsigned a[N],b[N];
int d[N*33];
int ch[N*33][2];
void cover(int i,unsigned j,int de)
{
	if (i==0&&de>0) return;
	if (d[i]==2) return;
	if (d[i]==1) 
	{
		ans++;
		a[ans]=j<<(32-de);
		b[ans]=de;
		return;
	}
	cover(ch[i][0],j*2,de+1);
	cover(ch[i][1],j*2+1,de+1);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		char s[30];int a,b,c,cc,dd,e;
		scanf("%s",s);
		if (s[0]=='-') c=1;else c=2;
		if (sscanf(s+1,"%d.%d.%d.%d/%d",&a,&b,&cc,&dd,&e)==4) e=32;
		a=(a<<24)+(b<<16)+(cc<<8)+dd;
		int now=0;
	//	printf("%d ",e);
		for (int i=31;i>=31-e+1;i--)
		{
			int j=(a>>i)&1;
			if (ch[now][j]==0) ch[now][j]=++num;
			now=ch[now][j];
		}
		d[now]|=c;
	}
	for (int i=num;i>=0;i--)
	{
		if (d[i]==0) d[i]=d[ch[i][0]]|d[ch[i][1]];else
		{
			d[i]|=d[ch[i][0]];
			d[i]|=d[ch[i][1]];
			if (d[i]==3) flag=1;
		}
	}
	if (flag) 
	{
		printf("-1\n");
		return 0;
	}
	cover(0,0,0);
	printf("%d\n",ans);
	for (int i=1;i<=ans;i++)
		printf("%d.%d.%d.%d/%d\n",(a[i]>>24)&255
				,(a[i]>>16)&255,(a[i]>>8)&255,a[i]&0xff,b[i]);
}