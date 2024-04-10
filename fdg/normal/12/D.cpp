#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int max_tree[2000020]={0};

void update(int i,int l,int r,int pos,int val)
{
	if (l==r) max_tree[i]=val;
	else
	{
		int m=(l+r)>>1;
		if (pos<=m) update(2*i,l,m,pos,val);
		else update(2*i+1,m+1,r,pos,val);
		max_tree[i]=max(max_tree[2*i],max_tree[2*i+1]);
	}
}

int find(int i,int l,int r,int L,int R)
{
	if (l==L&&r==R) return max_tree[i];
	int m=(l+r)>>1;
	if (R<=m) return find(2*i,l,m,L,R);
	if (L>m) return find(2*i+1,m+1,r,L,R);
	return max(find(2*i,l,m,L,m),find(2*i+1,m+1,r,m+1,R));
}

struct item{
	item(int _x = 0,int _y = 0,int _z = 0) : x(_x), y(_y), z(_z) {};
	int x,y,z;
};

bool sortX(const item & a,const item & b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y||a.x==b.x&&a.y==b.y&&a.z<b.z;
}

bool sortY(const item & a,const item & b)
{
	return a.y<b.y||a.y==b.y&&a.x<b.x||a.x==b.x&&a.y==b.y&&a.z<b.z;
}

bool sortZ(const item & a,const item & b)
{
	return a.z<b.z||a.z==b.z&&a.y<b.y||a.z==b.z&&a.y==b.y&&a.x<b.x;
}

item v[500002];

int main()
{
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int n;
	scanf("%d",&n);
	memset(max_tree,0,sizeof(max_tree));
	for(int i=0;i<n;i++)
		scanf("%d",&v[i].x);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i].y);
	for(int i=0;i<n;i++)
		scanf("%d",&v[i].z);
	sort(v,v+n,sortZ);
	int cur=1,last=v[0].z;
	v[0].z=cur;
	for(int i=1;i<n;i++)
	{
		if (last!=v[i].z) cur++;
		last=v[i].z; v[i].z=cur;
	}
	sort(v,v+n,sortY);
	cur=1,last=v[0].y;
	v[0].y=cur;
	for(int i=1;i<n;i++)
	{
		if (last!=v[i].y) cur++;
		last=v[i].y; v[i].y=cur;
	}
	sort(v,v+n,sortX);
	cur=1,last=v[0].x;
	v[0].x=cur;
	for(int i=1;i<n;i++)
	{
		if (last!=v[i].x) cur++;
		last=v[i].x; v[i].x=cur;
	}
	int cnt=0,lx=v[n-1].x;
	for(int i=n-1;i>=0;i--)
	{
		if (v[i].x!=lx)
		{
			for(int j=i+1;j<n;j++)
			{
				if (v[j].x!=lx) break;
				int cval=find(1,0,500002,v[j].y,v[j].y);
				if (v[j].z>cval) update(1,0,500002,v[j].y,v[j].z);
			}
			lx=v[i].x;
		}
		int val=find(1,0,500002,v[i].y+1,500002);
		if (val>v[i].z) cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}