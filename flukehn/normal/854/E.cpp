#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
struct nod{
	int id,x;
}arr[20*200005];
int ak[20*200005];
int n,q;
int ak666[20*2000005],lson[20*2000005],rson[20*2000005];
int tot=1;
#define mid (l+r>>1)
void ins(int rt,int &now,int l,int r,int pos,int num)
{
	if (!now){
		now=++tot;
		ak666[now]=lson[now]=rson[now]=0;
	}
	if (l==r){
		ak666[now]+=num;
		return;
	}
	if (pos<=mid)
	{
		ins(lson[rt],lson[now],l,mid,pos,num);
		rson[now]=rson[rt];
	}
	else
	{
		ins(rson[rt],rson[now],mid+1,r,pos,num);
		lson[now]=lson[rt];
	}
	ak666[now]=ak666[lson[now]]+ak666[rson[now]];
	return;
}
int x1,y1,x2,y2;
int ak233(int rt,int l,int r,int L,int R)
{
	if (rt==0) return 0;
	if (L>R) return 0;
	if (rt==0) return 0;
	if (L<=l && r<=R)
		return ak666[rt];
	int ak666=0;
	if (L<=mid)
		ak666+=ak233(lson[rt],l,mid,L,R);
	if (R>=mid+1)
		ak666+=ak233(rson[rt],mid+1,r,L,R);
	return ak666;
}
long long akakak(long long t)
{
	return (t-1)*t/2;
}
int main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	ak[0]=1;
	for (int i=1;i<=n;i++)
	{
		cin>>arr[i].x;
		arr[i].id=i;
		ins(ak[i-1],ak[i],1,n,arr[i].x,1);
	}
		while (q--)
		{
			cin>>x1>>y1>>x2>>y2;
			long long t1=0,t2=0,t3=0,t4=0;
			t1=max(0,x1-1);
			t2=ak233(ak[n],1,n,1,y1-1);
			t3=max(0,n-x2);
			t4=ak233(ak[n],1,n,y2+1,n);
			long long ak666=akakak(n);
			ak666-=(akakak(t1)+akakak(t2)+akakak(t3)+akakak(t4));
			t1=ak233(ak[x1-1],1,n,1,y1-1);
			t2=ak233(ak[x1-1],1,n,y2+1,n);
			t3=ak233(ak[n],1,n,1,y1-1)-ak233(ak[x2],1,n,1,y1-1);
			t4=ak233(ak[n],1,n,y2+1,n)-ak233(ak[x2],1,n,y2+1,n);
			ak666+=(akakak(t1)+akakak(t2)+akakak(t3)+akakak(t4));
			printf("%lld\n",ak666);
		}
}