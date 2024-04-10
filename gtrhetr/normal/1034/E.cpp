#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long

ull a[2097152],b[2097152];
int cnt[2097152],n;
char s1[2100010],s2[2100010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void fwt(ull *a,int n,int on) { for (int w=2;w<=n;w<<=1) for (int k=0;k<n;k+=w) for (int j=k;j<k+(w>>1);j++) (on==1)?(a[j+(w>>1)]+=a[j]):(a[j+(w>>1)]-=a[j]); }

int main()
{
	n=rd();
	scanf("%s%s",s1,s2);
	for (int i=0;i<(1<<n);i++) a[i]=(ull)s1[i]-'0';
	for (int i=0;i<(1<<n);i++) b[i]=(ull)s2[i]-'0';
	for (int i=1;i<(1<<n);i++) cnt[i]=cnt[i>>1]+(i&1);
	for (int i=0;i<(1<<n);i++) a[i]<<=(cnt[i]<<1),b[i]<<=(cnt[i]<<1);
	fwt(a,1<<n,1);fwt(b,1<<n,1);
	for (int i=0;i<(1<<n);i++) a[i]=a[i]*b[i];
	fwt(a,1<<n,-1);
	for (int i=0;i<(1<<n);i++) a[i]=(a[i]>>(cnt[i]<<1))&3;
	for (int i=0;i<(1<<n);i++) putchar(a[i]+'0');
	putchar('\n');
	return 0;
}