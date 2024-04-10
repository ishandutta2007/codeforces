    #include<cstdio>
    #include<cstring>
    #include<algorithm>
    using namespace std;
    const int N=2e5+9,INF=0x3f3f3f3f;
    #define ls (x<<1)
    #define rs (x<<1|1)
    struct Node
    {
    	int ad,ab,cd,bc;
    } tr[N<<2];
    int m,n;
    char ch[N];
    bool g[3][N];
    /*
    a b
    c d
    */
    inline int chk(int a){return min(a,INF);}
     
    inline void update(int x)
    {
    	tr[x].ab=chk(min(tr[ls].ab+tr[rs].ab,tr[ls].ad+tr[rs].bc)+1);
    	tr[x].ad=chk(min(tr[ls].ab+tr[rs].ad,tr[ls].ad+tr[rs].cd)+1);
    	tr[x].bc=chk(min(tr[ls].cd+tr[rs].bc,tr[ls].bc+tr[rs].ab)+1);
    	tr[x].cd=chk(min(tr[ls].cd+tr[rs].cd,tr[ls].bc+tr[rs].ad)+1);
    }
     
    void build(int x,int l,int r)
    {
    	// printf("%d %d %d\n",x,l,r);
    	// system("pause");
    	if(l==r)
    	{
    		tr[x].ab=tr[x].ad=tr[x].cd=tr[x].bc=INF;
    		if(!g[1][l]) tr[x].ab=0;
    		if(!g[2][l]) tr[x].cd=0;
    		if(!g[2][l]&&!g[1][l]) tr[x].ad=tr[x].bc=1;
    		return;
    	}
    	int mid=(l+r)>>1;
    	build(ls,l,mid);
    	build(rs,mid+1,r);
    	update(x);
    }
     
    Node query(int x,int l,int r,int L,int R)
    {
    	// if(l==1&&r==2) printf("%d\n",tr[x].ab);
    	if(L<=l&&r<=R) return tr[x];
    	int mid=(l+r)>>1;
    	Node res1,res2,res;
    	if(R<=mid) return query(ls,l,mid,L,R);
    	if(L>mid) return query(rs,mid+1,r,L,R);
    	res1=query(ls,l,mid,L,R);res2=query(rs,mid+1,r,L,R);
    	res.ab=chk(min(res1.ab+res2.ab,res1.ad+res2.bc)+1);
    	res.ad=chk(min(res1.ab+res2.ad,res1.ad+res2.cd)+1);
    	res.bc=chk(min(res1.cd+res2.bc,res1.bc+res2.ab)+1);
    	res.cd=chk(min(res1.cd+res2.cd,res1.bc+res2.ad)+1);
    	return res;
    }
     
    int main()
    {
    	scanf("%d%d",&n,&m);
    	scanf("%s",ch+1);
    	for(int i=1;i<=n;i++) g[1][i]=(ch[i]=='X');
    	// printf("%d\n",g[1][2]);
    	scanf("%s",ch+1);
    	for(int i=1;i<=n;i++) g[2][i]=(ch[i]=='X');
    	// puts("Debug");
    	build(1,1,n);
    	while(m--)
    	{
    		int x,y;
    		scanf("%d%d",&x,&y);
    		int X=x,Y=y,ans;
    		if(x>n) X-=n;
    		if(y>n) Y-=n;
    		if(X>Y) swap(x,y),swap(X,Y);
    		Node res = query(1,1,n,X,Y);
    		if(x<=n&&y<=n) ans=res.ab;
    		if(x<=n&&y>n) ans=res.ad;
    		if(x>n&&y<=n) ans=res.bc;
    		if(x>n&&y>n) ans=res.cd;
    		if(ans>=INF) puts("-1");
    		else printf("%d\n",ans);
    	}
    	return 0;	
    }