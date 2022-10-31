#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct rec {int a,b,c;};
const int N=1000010;
rec t[N*4];
char s[N];
int n,m;
rec operator + (rec a,rec b) 
{
	int t=min(a.b,b.c);
	return (rec){a.a+b.a+t,a.b+b.b-t,a.c+b.c-t};
}
void build(int i,int l,int r)
{
	if (l==r)
	{
		t[i]=(rec){0,0,0};
		if (s[l]=='(') t[i].b=1;else t[i].c=1;
		return;
	}
	int mid=(l+r)>>1;
	build(i*2,l,mid);
	build(i*2+1,mid+1,r);
	t[i]=t[i*2]+t[i*2+1];
}
rec query(int i,int l,int r,int ll,int rr)
{
	if (ll<=l&&r<=rr) return t[i];
	int mid=(l+r)>>1;
	if (rr<=mid) return query(i*2,l,mid,ll,rr);
	if (ll> mid) return query(i*2+1,mid+1,r,ll,rr);
	return query(i*2,l,mid,ll,rr)+query(i*2+1,mid+1,r,ll,rr);
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	build(1,1,n);
	scanf("%d",&m);
	while (m--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,1,n,l,r).a*2);
	}
	return 0;
}