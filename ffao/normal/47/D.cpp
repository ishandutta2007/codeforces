    #include <bits/stdc++.h>
    #define inf 1000000007
    #define mod 1000000007
    //#pragma GCC optimize(2)
    //#define int long long
    using namespace std;
    template <typename T> void read(T &x){
    	x=0;char ch=getchar();int fh=1;
    	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
    	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    	x*=fh;
    }
    template <typename T> void write(T x) {
    	if (x<0) x=-x,putchar('-');
    	if (x>9) write(x/10);
    	putchar(x%10+'0');
    }
    template <typename T> void writeln(T x) {
    	write(x);
    	puts("");
    }
    int n,m,res;
    char ans[40];
    char s[15][40];
    int c[15];
    void dfs(int x,int y)
    {
    	if(x==n+1)
    	{
    		bool flag=true;
    		for(int i=2;i<=m;i++)
    		{
    			int cnt=0;
    			for(int j=1;j<=n;j++)
    				if(ans[j]==s[i][j])
    					cnt++;
    			if(cnt!=c[i])
    			{
    				flag=false;
    				break;
    			}
    		}
    		if(flag)
    			res++;
    		return;
    	}
    	if(y+1<=c[1])
    	{
    		ans[x]=(s[1][x]=='0'?'0':'1');
    		dfs(x+1,y+1);
    	}
    	if(c[1]-y!=n-x+1)
    	{
    		ans[x]=(s[1][x]=='0'?'1':'0');
    		dfs(x+1,y);
    	}
    }
    signed main()
    {
    	//freopen(".in","r",stdin);
    	//freopen(".out","w",stdout);
    	ios::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
    	cin>>n>>m;
    	for(int i=1;i<=m;i++)
    		cin>>s[i]+1>>c[i];
    	dfs(1,0);
    	cout<<res<<endl;
    	return 0;
    }