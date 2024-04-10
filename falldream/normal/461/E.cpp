#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#define pa pair<int,int>
#define MN 200006
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];
int d[MN+5],n,head[MN+5],cnt=0;
struct edge{int to,next,w;}e[MN*8+5];
inline void ins(int f,int t,int w){e[++cnt]=(edge){t,head[f],w};head[f]=cnt;}
priority_queue<pa,vector<pa>,greater<pa> >q;

namespace SAM
{
    #define MX 200000
    int n,cnt,last,c[MX+5][4],step[MX+5],fail[MX+5];
    void init(int len)
    {
        cnt=last=1;n=len;
        
    }
    void insert(int x)
    {
        int p=last,np=++cnt;step[np]=step[p]+1;
        for(;p&&!c[p][x];p=fail[p]) c[p][x]=np;
        if(!p) fail[np]=1;
        else 
        {
            int q=c[p][x];
            if(step[q]==step[p]+1) fail[np]=q;
            else 
            {
                int nq=++cnt;step[nq]=step[p]+1;
                memcpy(c[nq],c[q],sizeof(c[q]));
                fail[nq]=fail[q];fail[np]=fail[q]=nq;
                for(;c[p][x]==q;p=fail[p]) c[p][x]=nq;
            }    
        }
        last=np;
    }
    void Build(int x)
    {
    //	cout<<"Build"<<x<<endl;
    	ins(1,c[1][x],1);
    	for(int i=2;i<=cnt;++i) 
    		for(int j=0;j<4;++j) 
    			if(c[i][j]) ins(i,c[i][j],1);
    			else  ins(i,j+cnt+1,0);
    }
    #undef MX
}
long long L,ans=0;int num[5][5][5];

void Dij()
{
	memset(d,63,sizeof(d));d[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		while(!q.empty()&&d[q.top().second]!=q.top().first) q.pop();
		if(q.empty()) return;
		int x=q.top().second;q.pop();		
	//	cout<<"get"<<x<<" "<<d[x]<<endl;
		for(int i=head[x];i;i=e[i].next)
			if(d[x]+e[i].w<d[e[i].to]) q.push(make_pair(d[e[i].to]=d[x]+e[i].w,e[i].to));
	}	
}
int main()
{
	cin>>L;scanf("%s",st+1);n=strlen(st+1);	SAM::init(n<<1);
	for(int i=1;i<=n;++i)  SAM::insert(st[i]-'A');
	memset(num,63,sizeof(num));
	for(int i=0;i<4;++i) 
	{
		cnt=0;memset(head,0,sizeof(head));
		SAM::Build(i);Dij();
		for(int j=0;j<4;++j)
		{
			num[1][i][j]=d[(SAM::cnt)+j+1];
		//	cout<<i<<" "<<j<<" "<<num[1][i][j]<<endl;
		}
	}
	for(int i=2;i<=4;++i)
		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k)
				for(int l=0;l<4;++l)
					num[i][j][k]=min(num[i][j][k],num[i-1][j][l]+num[1][l][k]);
	for(int j=0;j<4;++j)
		for(int i=1;i<=4;++i) 
		{
			long long res=L/num[i][j][j]*i,left=L%num[i][j][j],mn=0;	
			for(int l=i;~l;--l)
			{
				for(int jj=0;jj<4;++jj)
				{
					int x=l==0?0:num[l][j][jj];
					if(x<=left) mn=max(mn,(long long)l+(x!=left)); 
					for(int ll=0;ll<4;++ll)
						for(int kk=0;kk<4;++kk)
						{
							int xx=ll==0?0:num[ll][kk][j];
							if(xx+x<=left) mn=max(mn,(long long)l+ll+(x+xx!=left));	
							if(res>0&&xx+x<=left+num[i][j][j])
								mn=max(mn,(long long)l+ll+((x+xx)!=(left+num[i][j][j]))-i);
						}
				}
			}
	//		cout<<i<<" "<<j<<" "<<num[i][j][j]<<" "<<res<<" "<<mn<<endl;
			ans=max(ans,res+mn); 
		}
	printf("%lld\n",ans);
	return 0;
}