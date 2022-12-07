#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,t,S[200005],T[200005],l[200005],r[200005],sum[800005],tag[800005];
void build(int k,int l,int r)
{
	if(l==r)
	{
		sum[k]=T[l];
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	sum[k]=sum[k*2]+sum[k*2+1];
}
void Set(int k,int l,int r,int v)
{
	tag[k]=v;
	sum[k]=(v-1)*(r-l+1);
}
void pushdown(int k,int l,int r)
{
	if(tag[k]==0) return;
	int mid=(l+r)/2; 
	Set(k*2+1,mid+1,r,tag[k]);
	Set(k*2,l,mid,tag[k]);
	tag[k]=0;
}
long long query(int k,int l,int r,int x,int y)
{
	if(l>=x&&r<=y) return sum[k];
	int mid=(l+r)/2;
	long long res=0;
	pushdown(k,l,r);
	if(x<=mid) res+=query(k*2,l,mid,x,y);
	if(mid<y) res+=query(k*2+1,mid+1,r,x,y);
	return res;
}
void modify(int k,int l,int r,int x,int y,int v)
{
	if(l>=x&&r<=y) return Set(k,l,r,v);
	int mid=(l+r)/2;
	pushdown(k,l,r);
	if(x<=mid) modify(k*2,l,mid,x,y,v);
	if(mid<y) modify(k*2+1,mid+1,r,x,y,v);
	sum[k]=sum[k*2]+sum[k*2+1];
}
int main()
{
	scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
        for(int i=1;i<=n;i++)
        {
            char tmp;
            scanf(" %c",&tmp);
            S[i]=tmp-'0';
        }
        for(int i=1;i<=n;i++)
        {
            char tmp;
            scanf(" %c",&tmp);
            T[i]=tmp-'0';
        }
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
        }
        for(int i=1;i<=4*n;i++)
        {
            sum[i]=tag[i]=0;
        }
        build(1,1,n);
        bool flag=false;
        for(int i=q;i>=1;i--)
        {
            int Now=query(1,1,n,l[i],r[i]);
            if(Now*2==(r[i]-l[i]+1))
            {
                flag=true;
                printf("NO\n");
                break;
            }
            if(Now*2>(r[i]-l[i]+1))
            {
                modify(1,1,n,l[i],r[i],2);
            }
            else
            {
                modify(1,1,n,l[i],r[i],1);
            }
        }
        if(flag) continue;
        for(int i=1;i<=n;i++)
        {
            if(query(1,1,n,i,i)!=S[i])
            {
                flag=true;
                printf("NO\n");
                break;
            } 
        }
        if(!flag) printf("YES\n");
    }
}