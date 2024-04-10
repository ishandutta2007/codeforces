#include<algorithm>
#include<iostream>
#include<cstdio>
#define pa pair<int,int>
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
pa s[MN+5];long long ans=1e18;
int n,K,rk[MN+5],pos[MN+5],q[MN+5],top;
bool cmp(int x,int y){return s[x].second<s[y].second;}
inline int R(int x){return max(1,x+1>>1);}
int main()
{
	n=read();K=read();
	for(int i=1;i<=n;++i) s[i].first=read(),s[i].second=read(),rk[i]=i,s[i].first+=read(),s[i].second+=read();
	sort(s+1,s+n+1);sort(rk+1,rk+n+1,cmp);
	for(int i=1;i<=n;++i) pos[rk[i]]=i;
	for(int j=0;j<=K;++j) for(int k=0;j+k<=K;++k)
	{
		top=0;
		for(int i=1;i<=n;++i) if(pos[i]>j&&pos[i]<n+1-k) q[++top]=i;
		int Len=R(s[rk[n-k]].second-s[rk[j+1]].second);
		//cout<<j<<" "<<k<<" "<<Len<<endl;
		for(int i=1;i+n-K-1<=top;++i) ans=min(ans,1LL*Len*R(s[q[i+n-K-1]].first-s[q[i]].first));
	}
	cout<<ans;
	return 0;
}