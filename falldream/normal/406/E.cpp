#include<algorithm>
#include<iostream>
#include<cstdio>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int L[MN+5],n,m,num[2][MN+5],pre[2][MN+5],suf[2][MN+5],flag=0,N,mn=1e9;long long ans=0;
pair<int,int> s[MN+5];
void R(int x,long long y){if(x<mn)mn=x,ans=y;else if(x==mn)ans+=y;}
int main()
{
	N=read();m=read();
	for(int i=1,j;i<=m;++i) j=read(),s[i]=make_pair(read(),j);
	sort(s+1,s+m+1);
	for(int i=1;i<=m;++i) L[i]=s[i].first;
	n=unique(L+1,L+m+1)-L-1;
	for(int i=1;i<=m;++i) s[i].first=lower_bound(L+1,L+n+1,s[i].first)-L,++num[s[i].second][s[i].first];
	for(int i=1;i<=n;++i) for(int j=0;j<2;++j) pre[j][i]=pre[j][i-1]+num[j][i];
	for(int i=n;i>=1;--i) for(int j=0;j<2;++j) suf[j][i]=suf[j][i+1]+num[j][i];
	for(int i=1;i<=n;++i)
	{
		flag|=(num[0][i]&&num[1][i]);
		for(int j=0;j<2;++j)
			if(num[j][i]&&pre[j^1][i-1]&&suf[j^1][i+1]) flag=1;	
	}
//	cout<<"flag="<<flag<<endl;
	if(!flag)
	{
		mn=1e9;
		for(int j=0;j<2;++j) if(pre[j][n])
		{
			int i,k;
			for(i=n;pre[j][i]==pre[j][n];--i);++i;
			for(k=1;suf[j][k]==suf[j][1];++k);--k;
		//	cout<<j<<" "<<i<<" "<<k<<endl;
			R(N-L[i]+L[k],i==k?1LL*num[j][i]*(num[j][i]-1)*(num[j][i]-2)/6:
				1LL*num[j][i]*num[j][k]*(m-num[j][i]-num[j][k])+1LL*num[j][i]*(num[j][i]-1)/2*num[j][k]+1LL*num[j][k]*(num[j][k]-1)/2*num[j][i]);
		}
		for(int c=0;c<2;++c)
			for(int i=1,last=0;i<=n;++i) if(num[c][i])
			{
				if(pre[c^1][i]>=2) 
				{
					int La=num[c^1][last],LLa=pre[c^1][last]-La;
					R(L[i]-L[last],1LL*num[c][i]*La*(La-1)/2+1LL*num[c][i]*La*LLa);	
			//		cout<<c<<" "<<i<<" prelast= "<<last<<" "<<La<<" "<<LLa<<endl;
				}
			}
			else if(num[c^1][i]) last=i;
		for(int c=0;c<2;++c)
			for(int i=n,last=0;i;--i) if(num[c][i])
			{
				if(suf[c^1][i]>=2)
				{
					int La=num[c^1][last],LLa=suf[c^1][last]-La;
					R(L[last]-L[i],1LL*num[c][i]*La*(La-1)/2+1LL*num[c][i]*La*LLa);	
			//		cout<<c<<" "<<i<<" suflast= "<<last<<" "<<La<<" "<<LLa<<endl;
				}
			}
			else if(num[c^1][i]) last=i;
		return 0*printf("%lld\n",ans);
	}
	else 
	{
		for(int i=1;i<=n;++i) 
			for(int j=0;j<2;++j) 
				ans+=1LL*num[j][i]*(pre[j^1][i]-num[j^1][i])*(suf[j^1][i]-num[j^1][i]),
				ans+=1LL*num[j][i]*num[j^1][i]*(num[j^1][i]-1)/2,
				ans+=1LL*num[j][i]*num[j^1][i]*(suf[j^1][1]-num[j^1][i]);
		printf("%lld\n",ans);
	}
	return 0;
}