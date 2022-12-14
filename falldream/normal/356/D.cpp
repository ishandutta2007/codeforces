#include<bits/stdc++.h>
#define MN 70000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
#ifdef BITSET_COUNT
int numbit[1<<16];
#endif
struct Bitset
{
// Bitset Template by FallDream 2018.6.26
#define BITLEN 70000
#define ull unsigned long long
	ull s[BITLEN/64+1];int len;
	Bitset(){}
	void reset(int k=0){memset(s,k?255:0,sizeof(s));}
	void flip(int x){s[x>>6]^=1ULL<<(x&63);}
	void set(int x,int k=1){k?s[x>>6]|=1ULL<<(x&63):s[x>>6]&=-(1ULL<<(x&63))-1;}
	bool operator [](int x){return bool(s[x>>6]&(1ULL<<(x&63)));}
	bool any()
	{
		for(int i=0;i<=BITLEN/64;++i)
			if(s[i]) return true;
		return false;	
	}
	int count()
	{
#ifndef BITSET_COUNT 
	return 0;
#else
	int res=0;
	for(int i=0;i<=BITLEN/64;++i) 
		res+=numbit[s[i]&65535]+numbit[(s[i]>>16)&63555]
			+numbit[(s[i]>>32)&65535]+numbit[(s[i]>>48)&65535];
	return res;
#endif
	}
	int lowbit()
	{
		for(int i=0;i<=BITLEN/64;++i)if(s[i])
		{
			int l=0,r=63,mid,res;
			while(l<=r)
				if(s[i]>>(mid=l+r>>1)) res=mid,l=mid+1;
				else r=mid-1;
			return res+(i<<6);
		}
		return -1;
	}
	inline void Cut(){if((BITLEN&63)<63)s[BITLEN/64]&=(1ULL<<(BITLEN&63)+1)-1;}
	Bitset operator ~ (){
		Bitset c;c.reset();
		for(int i=0;i<=BITLEN/64;++i)c.s[i]=s[i]^(ull)-1;
		c.Cut();return c;
	}
	Bitset operator << (int len)
	{
		Bitset c;c.reset();int tlen=len>>6;len&=63;ull la=0;
		for(int i=tlen,j=0;i<=BITLEN/64;++i,++j)
			c.s[i]=(s[j]<<len)|la,la=len?s[j]>>(64-len):0;
		c.Cut();return c;
	}
	Bitset operator >> (int len)
	{
		Bitset c;c.reset();int tlen=len>>6;len&=63;ull la=0;
		for(int i=BITLEN/64-tlen,j=BITLEN/64;i>=0;--i,--j)
			c.s[i]=(s[j]>>len)|la,la=len?(s[j]&((1<<len)-1))<<(64-len):0;
		c.Cut();return c;
	}
	Bitset operator | (const Bitset&y)
	{
		Bitset c;
		for(int i=0;i<=BITLEN/64;++i) c.s[i]=s[i]|y.s[i];
		return c;
	}
	Bitset operator & (const Bitset&y)
	{
		Bitset c;
		for(int i=0;i<=BITLEN/64;++i) c.s[i]=s[i]&y.s[i];
		return c;	
	}
	void operator &= (const Bitset&y){(*this)=(*this)&y;}
	void operator |= (const Bitset&y){(*this)=(*this)|y;}
}b,B;
int n,s,ch[MN+5],f[MN+5],fir[MN+5],nxt[MN+5];
pair<int,int> a[MN+5];
int main()
{
#ifdef BITSET_COUNT
	for(int i=1;i<1<<16;++i) numbit[i]=numbit[i>>1]+(i&1);
#endif
	n=read();s=read();
	for(int i=1;i<=n;++i) a[i]=make_pair(f[i]=read(),i);
	sort(a+1,a+n+1,greater<pair<int,int> >());
	fir[a[1].first]=1;b.set(a[1].first);
	for(int i=2;i<=n;++i) 
	{
		Bitset c=b<<a[i].first;
		B=c&(~b);b|=c;int low;
		while((low=B.lowbit())>=0) fir[low]=i,B.set(low,0);
	}
	if(!b[s]) return 0*puts("-1");
	for(int j=n,k=s;j;--j)
		if(fir[k]>=j) k-=a[j].first,ch[a[j].second]=1;
	int la=0;
	for(int j=n;j;--j) if(!ch[a[j].second])
		nxt[a[j].second]=la,la=a[j].second;
	nxt[a[1].second]=la;
	for(int i=1;i<=n;++i)
	{
		printf("%d ",nxt[i]?f[i]-f[nxt[i]]:f[i]);	
		if(nxt[i]) printf("1 %d\n",nxt[i]);
		else puts("0");
	}
	return 0;
}