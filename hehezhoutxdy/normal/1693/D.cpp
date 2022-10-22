//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define ll long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003],in[1000003],de[1000003],f[1000003],n=read();
void update(int i)
{
	if(i==n) return;
    int In=n+1,De=0;
    if(a[i-1]<a[i]) De=max(De,de[i-1]);
    if(in[i-1]<a[i]) De=max(De,a[i-1]);
    if(a[i-1]>a[i]) In=min(In,in[i-1]);
    if(de[i-1]>a[i]) In=min(In,a[i-1]);
    if(in[i]==In&&de[i]==De) return ;
    in[i]=In,de[i]=De,f[i]=0;
    if(in[i]<=n||de[i]>0) update(i+1),f[i]=f[i+1]+1;
    return ;
}
int main()
{
    for(int i=0; i<n; ++i) a[i]=read();
    ll ans=0;
    for(int i=n-1; i>=0; --i)
    	in[i]=0,de[i]=n+1,update(i+1),ans+=(f[i]=f[i+1]+1);
   	printf("%lld\n",ans);
    return 0;
}