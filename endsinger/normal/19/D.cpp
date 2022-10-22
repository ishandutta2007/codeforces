#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t[N],x[N],y[N],n,tr[N<<2];
vector<int>vx,vy;
set<int>s[N];
char ch[10];
void update(int k,int l,int r,int x,int v)
{
	if(l==r)
	{
		tr[k]=v;
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(k<<1,l,mid,x,v);
	else update(k<<1|1,mid+1,r,x,v);
	tr[k]=max(tr[k<<1],tr[k<<1|1]);
}
int query(int k,int l,int r,int a,int b)
{
	if(l==a&&r==b)
		return tr[k];
	int mid=l+r>>1;
	if(b<=mid) return query(k<<1,l,mid,a,b);
	else if(a>mid) return query(k<<1|1,mid+1,r,a,b);
	else return max(query(k<<1,l,mid,a,mid),query(k<<1|1,mid+1,r,mid+1,b));
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d%d",ch,&x[i],&y[i]);
		if(ch[0]=='a')
			t[i]=1;
		if(ch[0]=='r')
			t[i]=2;
		if(ch[0]=='f')
			t[i]=3,x[i]++,y[i]++;
		vx.emplace_back(x[i]);
		vy.emplace_back(y[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	for(int i=1;i<=n;i++)
	{
		x[i]=lower_bound(vx.begin(),vx.end(),x[i])-vx.begin()+1;
		y[i]=lower_bound(vy.begin(),vy.end(),y[i])-vy.begin()+1;
	}
	for(int i=1;i<=n;i++)
	{
		if(t[i]==1)
		{
			s[x[i]].insert(-y[i]);
			update(1,1,n,x[i],-(*s[x[i]].begin()));
		}
		if(t[i]==2)
		{
			s[x[i]].erase(-y[i]);
			update(1,1,n,x[i],-(*s[x[i]].begin()));
		}
		if(t[i]==3)
		{
			int l=x[i]-1,r=vx.size();
			while(r-l>1)
			{
				int mid=l+r>>1;
				if(query(1,1,n,x[i],mid)>=y[i])
					r=mid;
				else
					l=mid;
			}
			int kx=r,ky;
			if(query(1,1,n,x[i],r)<y[i])
			{
				puts("-1");
				continue;
			}
			auto it=s[r].upper_bound(-y[i]);
			it--;
			ky=-(*it);
			printf("%d %d\n",vx[kx-1],vy[ky-1]);
		}
	}
	return 0;
}