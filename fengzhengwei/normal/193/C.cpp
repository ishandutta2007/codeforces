#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc()
{
	static char buf[1<<16],*s,*t;
	if(s==t)
	{
		t=(s=buf)+fread(buf,1,1<<16,stdin);
		if(s==t)return EOF;
	}
	return *s++;
}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);
	pc(op,0);
}
const int xx=1e6+5;
//int a[6][12]={
//1,1,1,0,0,0,1,0,0,0,0,0,
//1,1,0,0,1,1,0,1,0,0,0,0,
//1,0,1,1,0,1,0,0,1,0,0,0,
//1,0,0,1,1,0,0,0,0,1,0,0,
//0,1,1,1,1,0,0,0,0,0,1,0,
//0,1,0,1,0,1,0,0,0,0,0,1};
int a[6][13]=
{
	1,1,1,1,0,0,0,1,0,0,0,0,0,
	1,1,0,0,1,1,0,0,1,0,0,0,0,
	1,0,1,0,1,0,1,0,0,1,0,0,0,
	0,0,1,1,1,1,0,0,0,0,1,0,0,
	0,1,0,1,1,0,1,0,0,0,0,1,0,
	0,1,1,0,0,1,1,0,0,0,0,0,1,
};
struct gs
{
	double s[15];
} e[8];
int val[8];
int rval[8],rl[8];
int tb[]= {0,1,6,5,2,3,4,7};
int A[4][1000005];
int main()
{
//	freopen("a.out","w",stdout);
	for(int i=0; i<6; i++)for(int j=0; j<13; j++)e[i+1].s[j+1]=a[i][j];
	for(int i=1; i<=6; i++)
	{
		int j=i;
		while(j<=6&&!e[j].s[i])j++;
		if(j==6+1)
		{
//			puts("!!");
			exit(0);
		}
		swap(e[i],e[j]);
		double o=e[i].s[i];
		for(j=1; j<=13; j++)e[i].s[j]/=o;
		for(j=1; j<=6; j++)
		{
			if(i==j)continue;
			int t=e[j].s[i];
			for(int k=1; k<=13; k++)
				e[j].s[k]-=t*e[i].s[k];
		}
	}
	for(int i=1; i<=6; i++)val[i]=read();
	for(int i=1; i<=6; i++)
		for(int j=1; j<=6; j++)
		{
//			cerr<<e[j].s[7+i]<<" "<<j<<"\n";
			rval[j]+=e[j].s[7+i]*2*val[i];
		}
	for(int i=1; i<=6; i++)
	{
		if(rval[i]&1)
		{
			puts("-1");
			exit(0);
		}
	}
//	for(int i=1;i<=6;i++)cout<<rval[i]<<"\n";
	for(int i=1; i<=6; i++)rval[i]/=2;
	int mn=1e9,mnid=-1;
	for(int i=0; i<=1000000; i++)
	{
		for(int j=1; j<=6; j++)
		{
			if(e[j].s[7]==-1)
				rl[j]=i+rval[j];
			else
				rl[j]=rval[j]-i;
		}
		int vs=0;
		for(int j=1; j<=6; j++)if(rl[j]<0)vs=1;
		if(vs)continue;
		int sm=i;
		for(int j=1; j<=6; j++)sm+=rl[j];
		if(mn>sm)
			mn=sm,mnid=i;
	}
//	cerr<<mnid<<"\n";
	if(mnid==-1)
	{
		puts("-1");
		exit(0);
	}
	int i=mnid;
	for(int j=1; j<=6; j++)
	{
		if(e[j].s[7]==-1)
			rl[j]=i+rval[j];
		else
			rl[j]=rval[j]-i;
	}
	int sm=i;
	for(int j=1; j<=6; j++)sm+=rl[j];
	cout<<mn<<"\n";
	rl[7]=i;
//	cerr<<i<<"!!!\n";
	int tt=0;
	for(int j=1; j<=7; j++)
	{
//		cerr<<j<<" "<<rl[j]<<"\n";
		while(rl[j]--)
		{
			tt++;
			for(int i=0; i<4; i++)
			{
				if(tb[j]>>i&1)
					A[i][tt]=1;
			}
		}
	}
	for(int i=0; i<4; i++)
	{
		for(int j=1; j<=mn; j++)
		{
			if(A[i][j])
				cout<<"a";
			else cout<<"b";
		}
		puts("");
	}
//	for(int i=1;i<=6;i++)for(int j=1;j<=13;j++)cout<<e[i].s[j]<<"	\n"[j==13];
	pc('1',1);
	return 0;
}