//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n;
int a[100111],b[100111],c[100111];
vector<int>v;
void update(int x,int y){for(int i=x;i<=100005;i+=i&(-i))b[i]=max(b[i],y);}
int query(int x){int ret=0;for(int i=x;i>0;i-=i&(-i))ret=max(ret,b[i]);return ret;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		v.PB(x);
		a[i]=x;
	}
	sort(v.begin(),v.end());
	for(int i=1;i<=n;i++)a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
	for(int i=n;i>=1;i--)
	{
		c[i]=query(a[i]-1);
		if(c[i]==0)c[i]=-1;else c[i]=c[i]-i-1;
		update(a[i],i);
	}
	for(int i=1;i<=n;i++)printf("%d ",c[i]);
	return 0;
}