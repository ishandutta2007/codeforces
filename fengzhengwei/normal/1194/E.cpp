#include<bits/stdc++.h>
#define ll long long
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
	int x1,x2,y1,y2;
	bool operator<(const node&w)const
	{
		return y2<w.y2;
	}
}h[100005],l[100005];
int cnt1,cnt2;
int n;
int sum[300005];
int lb(int x)
{
	return x&(-x);
}
void add(int x,int y)
{
	for(;x<=10003;x+=lb(x))sum[x]+=y;
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=lb(x))ans+=sum[x];
	return ans;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		a=read()+5001;
		b=read()+5001;
		c=read()+5001;
		d=read()+5001;
		if(a>c)swap(a,c);
		if(b>d)swap(b,d);
		if(b==d)h[++cnt1]=(node){a,c,b,d};
		else l[++cnt2]=(node){a,c,b,d};
	}
	sort(h+1,h+cnt1+1);
	sort(l+1,l+cnt2+1);
	queue<int>q;
	ll ans=0;
	for(int i=1;i<=cnt1;i++)
	{
		memset(sum,0,sizeof(sum));
		while(!q.empty())q.pop();
//		cout<<h[i].x1<<" "<<h[i].x2<<" "<<h[i].y1<<endl;
		for(int j=1;j<=cnt2;j++)
		{
//				cout<<j<<endl;
			if(h[i].x1<=l[j].x1&&l[j].x1<=h[i].x2&&l[j].y1<=h[i].y1&&h[i].y1<=l[j].y2)
			{
				q.push(j);
				add(l[j].x1,1);
			}
		}
		for(int j=i+1;j<=cnt1;j++)
		{
			while(!q.empty()&&l[q.front()].y2<h[j].y1)add(l[q.front()].x1,-1),q.pop();
			int l=max(h[i].x1,h[j].x1),r=min(h[i].x2,h[j].x2);
			if(l<r)
			{
				ll s=ask(r)-ask(l-1);
//				cout<<s<<endl;
				ans+=s*(s-1)/2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}