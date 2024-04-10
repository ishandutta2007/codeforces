#include<bits/stdc++.h>
using namespace std;
struct linear_base
{
    int a[22],mxlog;
    linear_base()
    {
    	mxlog=20;
	}
    void Insert(int x)
    {
        for (int i=mxlog;i>=0;i--)
        {
            if (x&(1ll<<i))
            {
                if (!a[i]) 
                {
                    a[i]=x;
                    return;
                }
                else x^=a[i];
            }
        }
    }
    void merge(const linear_base &b) 
    {
        for (int i=mxlog;i>=0;i--) 
        {
            if (b.a[i]) Insert(b.a[i]);
        }
    }
    int findmax()
    {
        int res=0;
        for (int i=mxlog;i>=0;i--) 
        {
            if ((res^a[i])>res) res^=a[i];
        }
        return res;
    }
}L,p[555555];
pair<pair<int,int>,int> que[555555],nw[555555];
int aa[555555],q,ans[555555],n;
void solve(int l,int r,int ql,int qr)
{
	if (l==r)
	{
		for (int i=ql;i<=qr;i++)
		{
			ans[que[i].second]=aa[l];
		}
		return;
	}
	if (ql>qr) return;
	int mid=(l+r)>>1;
	memset(L.a,0,sizeof(L.a));
	for (int i=mid;i>=l;i--)
	{
		L.Insert(aa[i]);
		for (int j=0;j<=20;j++) p[i].a[j]=L.a[j]; 
	}
	memset(L.a,0,sizeof(L.a));
	for (int i=mid+1;i<=r;i++)
	{
		L.Insert(aa[i]);
		for (int j=0;j<=20;j++) p[i].a[j]=L.a[j]; 
	}
	int ll=ql,rr=qr;
	for (int i=ql;i<=qr;i++)
	{
		if (que[i].first.second<=mid) nw[ll++]=que[i];
		else if (que[i].first.first>mid) nw[rr--]=que[i];
		else
		{
			L=p[que[i].first.first];L.merge(p[que[i].first.second]);
			ans[que[i].second]=L.findmax(); 
		}
	}
	for (int i=ql;i<ll;i++) que[i]=nw[i];
	for (int i=rr+1;i<=qr;i++) que[i]=nw[i];
	solve(l,mid,ql,ll-1);solve(mid+1,r,rr+1,qr);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&aa[i]);
	scanf("%d",&q);
	for (int i=1;i<=q;i++) scanf("%d%d",&que[i].first.first,&que[i].first.second);
	for (int i=1;i<=q;i++) que[i].second=i;
	solve(1,n,1,q);
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}