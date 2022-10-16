#include<bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
struct node
{
	int x,y;
	bool operator<(const node &w)const
	{
		return x<w.x;
	}
}e[3000005];
int n;
int ans=0;
int maxxr[3000005];
int maxxl[3000005];
int minnl[3000005];
int minnr[3000005];
int t[3000005];
void solve(int l,int r)
{
	if(l==r)
	{
		maxxl[l]=maxxr[l]=minnl[l]=minnr[l]=e[l].y;
		ans++;
		return;
	}
	int mid=l+r>>1;
	solve(l,mid);
	solve(mid+1,r);
	int ll,rr;
	ll=mid+1,rr=mid;
	for(int x=mid;x>=l;x--)
	{
		int w=maxxr[x]-minnr[x];
		int y=w+x;
		if(mid<y&&y<=r)
		if(maxxr[x]>maxxl[y]&&minnr[x]<minnl[y])ans++;
		while(rr<r&&minnl[rr+1]>minnr[x])
		{
			rr++;
			t[maxxl[rr]-rr+n]++;
		}
		while(ll<=rr&&maxxl[ll]<=maxxr[x])
		{
			t[maxxl[ll]-ll+n]--;
			ll++;
		}
		ans+=t[minnr[x]-x+n];
	}
//	memset(t,0,sizeof(t));
	for(;ll<=rr;ll++)
	{
		t[maxxl[ll]-ll+n]--;
	}
	ll=mid+1,rr=mid;
	for(int y=mid+1;y<=r;y++)
	{
		int w=maxxl[y]-minnl[y];
		int x=y-w;
		if(l<=x&&x<=mid)
		if(maxxr[x]<maxxl[y]&&minnr[x]>minnl[y])ans++;
		while(ll>l&&minnr[ll-1]>minnl[y])
		{
			ll--;
			t[maxxr[ll]+ll]++;
		}
		while(rr>=ll&&maxxr[rr]<maxxl[y])
		{
			t[maxxr[rr]+rr]--;
			rr--;
		}
		ans+=t[minnl[y]+y];
	}
//	memset(t,0,sizeof(t));
	for(;ll<=rr;ll++)
	{
		t[maxxr[ll]+ll]--;
	}
	int w=0;
	int m=2147483647;
	for(int x=l;x<=mid;x++)w=max(w,e[x].y),m=min(m,e[x].y);
	for(int i=mid+1;i<=r;i++)
	{
		maxxl[i]=max(maxxl[i],w);
		minnl[i]=min(minnl[i],m);
	}
	w=0;
	m=2147483647;
	for(int x=mid+1;x<=r;x++)w=max(w,e[x].y),m=min(m,e[x].y);
	for(int i=l;i<=mid;i++)
	{
		maxxr[i]=max(maxxr[i],w);
		minnr[i]=min(minnr[i],m);
	}
//	for(int i=l;i<=r;i++)
//	{
//		cout<<e[i].y<<" ";
//	}
//	cout<<endl;
//	for(int i=l;i<=r;i++)
//	{
//		cout<<minnl[i]<<" ";
//	}
//	cout<<endl;
}
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		e[i].x=read();
		e[i].y=read();
	}
	sort(e+1,e+n+1);
	solve(1,n);
	cout<<ans<<endl;
	return 0;
}