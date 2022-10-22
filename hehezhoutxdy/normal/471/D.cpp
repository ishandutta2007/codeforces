#include<bits/stdc++.h>
#define ri register
#define inf 0x7fffffff
#define E (1)
using namespace std; const int N=400010;
inline int read()
{
	int s=0, w=1; ri char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48), ch=getchar(); return s*w;
}
int n,w,nxt[N]={-1},ans,a[N],b[N],p[N],q[N];
int main()
{
	n=read(), w=read();
	for(ri int i=0;i<n;i++) a[i]=read();
	for(ri int i=0;i<w;i++) b[i]=read();
	for(ri int i=0;i<n-1;i++) p[i]=a[i]-a[i+1];
	for(ri int i=0;i<w-1;i++) q[i]=b[i]-b[i+1];
	if(w==1) { return 0&printf("%d\n",n); }
	for(ri int i=1;i<w;i++)
	{
		int j=nxt[i-1];
		while(q[i]^q[j+1]&&j>=0) j=nxt[j];
		if(q[i]==q[j+1]) nxt[i]=j+1;
		else nxt[i]=-1;
	}
	int i,j; i=j=0;
	while(i<n-1&&j<w-1)
	{
		if(p[i]==q[j]) i++, j++;
		else
		{
			if(!j) i++;
			else j=nxt[j-1]+1;
		}
		if(j==w-1) ans++, j=nxt[j-1]+1;
	}
	printf("%d\n",ans);
	return 0;
}