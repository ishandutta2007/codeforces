#include<bits/stdc++.h>
using namespace std;

int f[233];
int n,q;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline int gcd(int x,int y) { return (!y)?x:gcd(y,x%y); }

int main()
{
f[2]=1;
f[3]=1;
f[4]=5;
f[5]=1;
f[6]=21;
f[7]=1;
f[8]=85;
f[9]=73;
f[10]=341;
f[11]=89;
f[12]=1365;
f[13]=1;
f[14]=5461;
f[15]=4681;
f[16]=21845;
f[17]=1;
f[18]=87381;
f[19]=1;
f[20]=349525;
f[21]=299593;
f[22]=1398101;
f[23]=178481;
f[24]=5592405;
f[25]=1082401;
	q=rd();
	while (q--)
	{
		n=rd();
		bool flag=false;
		for (int i=2;i<=25;i++) if (n==(1<<i)-1) { printf("%d\n",f[i]);flag=true;break; }
		if (flag) continue;
		for (int i=2;i<=25;i++) if (n<=(1<<i)-1) { printf("%d\n",(1<<i)-1);break; }
	}
	return 0;
}