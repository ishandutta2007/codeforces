#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,q,MOD,a[300005],b[300005],d[300005],f[300005],cnt;
void modify(int pos,int val)
{
	if(pos>n)	return ;
	int tmp=d[pos];
	d[pos]+=val;
	d[pos]%=MOD;
	d[pos]+=MOD;
	d[pos]%=MOD;
	if(d[pos] && !tmp)	++cnt;
	if(!d[pos] && tmp)	--cnt;
}
int main(){
	scanf("%d %d %d",&n,&q,&MOD);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)	scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)
	{
		a[i]-=b[i];
		a[i]%=MOD;
		a[i]+=MOD;
		a[i]%=MOD;
	}
	for(int i=1;i<=n;++i)	d[i]=(a[i]-a[i-1]-(i==1?0:a[i-2])),d[i]%=MOD,d[i]+=MOD,d[i]%=MOD;
	for(int i=1;i<=n;++i)	cnt+=int(d[i]!=0);
	f[1]=f[2]=1;
	for(int i=3;i<=n;++i)	f[i]=(f[i-1]+f[i-2])%MOD;
	while(q-->0)
	{
		char op[2];
		scanf("%s",op);
		if(*op=='A')
		{
			int l,r;
			scanf("%d %d",&l,&r);
			if(l==r)
			{
				modify(l,1);
				modify(l+1,-1);
				modify(l+2,-1);
			}
			else if(l+1==r)
			{
				modify(l,1);
				modify(l+2,-2);
				modify(l+3,-1);
			}
			else
			{
				modify(l,1);
				int p=r-l+1;
				modify(r+1,MOD-(f[p]+f[p-1])%MOD);
				modify(r+2,MOD-f[p]);
			}
		}
		else
		{
			int l,r;
			scanf("%d %d",&l,&r);
			if(l==r)
			{
				modify(l,-1);
				modify(l+1,1);
				modify(l+2,1);
			}
			else if(l+1==r)
			{
				modify(l,-1);
				modify(l+2,2);
				modify(l+3,1);
			}
			else
			{
				modify(l,-1);
				int p=r-l+1;
				modify(r+1,(f[p]+f[p-1])%MOD);
				modify(r+2,f[p]);
			}
		}
		puts(cnt==0?"YES":"NO");
	}
	return 0;
}