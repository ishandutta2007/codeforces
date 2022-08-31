#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=300005;
int h[maxn<<2],minn[maxn],maxx[maxn],a[maxn],n,ans;
void js(int l,int r)
{
	if(l==r)
	{
		ans++;
		return ;
	}
	int mid=l+r>>1;
	js(l,mid);
	js(mid+1,r);
	minn[mid]=maxx[mid]=a[mid];
	minn[mid+1]=maxx[mid+1]=a[mid+1];
	for(int i=mid+2;i<=r;i++)
	{
		minn[i]=min(minn[i-1],a[i]);
		maxx[i]=max(maxx[i-1],a[i]);
	}
	for(int i=mid-1;i>=l;i--)
	{
		minn[i]=min(minn[i+1],a[i]);
		maxx[i]=max(maxx[i+1],a[i]);
	}
	for(int i=l;i<=mid;i++)
	{
		int j=maxx[i]-minn[i]+i;
		if(mid<j&&j<=r&&minn[i]<minn[j]&&maxx[j]<maxx[i])ans++;
	}
	for(int i=r;i>mid;i--)
	{
		int j=i-maxx[i]+minn[i];
		if(l<=j&&j<=mid&&minn[i]<minn[j]&&maxx[j]<maxx[i])ans++;
	}
	int head=mid+1,tail=mid+1;
	for(int i=mid;i>=l;i--)
	{
		while(tail<=r&&minn[tail]>minn[i])
		
		{
			h[maxx[tail]-tail+n]++;
			tail++;
		}
		while(head<tail&&head<=r&&maxx[head]<=maxx[i])
		{
			h[maxx[head]-head+n]--;
			head++;
		}
		ans+=h[minn[i]-i+n];
	}
	for(int i=head;i<tail;i++)h[maxx[i]-i+n]=0;
	head=tail=mid;
	for(int j=mid+1;j<=r;j++)
	{
		while(tail>=l&&minn[tail]>minn[j])
		{
			h[maxx[tail]+tail]++;
			tail--;
			
		}
		while(head>tail&&head>=l&&maxx[head]<maxx[j])
		{
			h[maxx[head]+head]--;
			head--;
		}
		ans+=h[minn[j]+j];
	}
	for(int i=head;i>tail;i--)h[maxx[i]+i]=0;
}
signed main(){
	int x,y;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);a[x]=y;
	}
	js(1,n);
	cout<<ans<<endl;
	return 0;
}