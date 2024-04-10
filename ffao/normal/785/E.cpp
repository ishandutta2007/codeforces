    #include <iostream>
    #include <cstdio>
    #define ll long long
    using namespace std;
    const int N=2e5+10,M=5e4+10;
    int n;
    int val[N],t[N];
    ll ans[M];
    struct node
    {
    	int a,b,c;
    	int type,id;
    }v[N+4*M],w[N+4*M];
    inline int lowbit(int x)
    {
    	return x&(-x);
    }
    inline void change(int x,int c)
    {
    	for(int i=x;i<=n;i+=lowbit(i))
    		t[i]+=c;
    }
    inline int query(int x)
    {
    	int res=0;
    	for(int i=x;i>=1;i-=lowbit(i))
    		res+=t[i];
    	return res;
    }
    inline void CDQ(int l,int r)
    {
    	if(l==r) return;
    	int mid=(l+r)/2,p,q;
    	CDQ(l,mid),CDQ(mid+1,r);
    	p=l,q=mid+1;
    	while(q<=r)// 
    	{
    		while(p<=mid&&v[p].b<=v[q].b) change(v[p].c,v[p].type),p++;
    		ans[v[q].id]+=v[q].type*(query(n)-query(v[q].c)),q++;
    	}
    	for(int i=l;i<p;i++) change(v[i].c,-v[i].type);
    	p=mid,q=r;
    	while(q>mid)// 
    	{
    		while(p>=l&&v[p].b>=v[q].b) change(v[p].c,v[p].type),p--;
    		ans[v[q].id]+=v[q].type*query(v[q].c-1),q--;
    	}
    	for(int i=mid;i>p;i--) change(v[i].c,-v[i].type);
    	p=l,q=mid+1;
    	for(int i=l;i<=r;i++)//
    	{
    		if((p<=mid&&v[p].b<=v[q].b)||q>r) w[i]=v[p++];
    		else w[i]=v[q++];
    	} 
    	for(int i=l;i<=r;i++) v[i]=w[i];
    }
    int main()
    {
    	int m,tot=0,a,b;
    	scanf("%d%d",&n,&m);
    	for(int i=1;i<=n;i++)
    		val[i]=i,v[++tot]=(node){tot,i,i,1,0};
    	for(int i=1;i<=m;i++)
    	{
    		scanf("%d%d",&a,&b);
    		v[++tot]=(node){tot,a,val[a],-1,i};
    		v[++tot]=(node){tot,b,val[b],-1,i};
    		v[++tot]=(node){tot,a,val[b],1,i};
    		v[++tot]=(node){tot,b,val[a],1,i};
    		swap(val[a],val[b]);
    	}
    	CDQ(1,tot);
    	for(int i=1;i<=m;i++)
    		ans[i]+=ans[i-1];
    	for(int i=1;i<=m;i++)
    		printf("%lld\n",ans[i]);
    	return 0;
    }