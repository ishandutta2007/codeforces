#include<bits/stdc++.h>
#define ll long long
#define dd double
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
int n,q,s,d,a[xx];
struct nod
{
	int I,K,id;
	bool operator<(const nod&w)const{return K<w.K;}
}Q[xx];
struct N
{
	int fa[1000005];
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	void init(){for(int i=1;i<=1e6+1;i++)fa[i]=i;}
}Y,Z;
struct no
{
	int id,k,op;
	bool operator<(const no&w)const{return k>w.k;}
};
/*
0 / 
1  // 
*/
int vs[1000005];
//  
priority_queue<no>qq;
// 
// 
void run(int x)
{
//	cerr<<x<<" "<<vs[x]<<"!!\n";
	int A,I;
	I=a[x];vs[I]=1,Y.fa[I]=I+1,Z.fa[I]=I-1;
	//push 
	// 
	if(I+d<=1e6){A=Y.find(I+d);if(A!=1e6+1)qq.push({A,A-(I+d),0});}
	int W=max(1,I-d);A=Y.find(W);if(A!=1e6+1)qq.push({A,A-(I-d),0});
	W=min(1000000,I+d);A=Z.find(W);if(A!=0)qq.push({A,(I+d)-A,1});
//	if(I+d<=1e6){A=Z.find(I+d);if(A!=0)qq.push({A,(I+d)-A,1});}
	if(I-d>0){A=Z.find(I-d);if(A!=0)qq.push({A,(I-d)-A,1});}
}
int to[1000005],VVV[1000005][2];//VVV 
int ans[xx];
int main(){
	Y.init(),Z.init();
	n=read(),q=read(),s=read(),d=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)to[a[i]]=i;
	for(int i=1;i<=q;i++)
		Q[i].I=read(),Q[i].K=read(),Q[i].id=i;
	sort(Q+1,Q+q+1);
	int tt=1;
	//id 
	//push4 
	// 
	// 
	for(int k=0;k<=1000000;k++)
	{
//		if(k%100==0)cerr<<k<<"!!\n";
		if(k==0)run(s);
		//push 
		//vspush 
		while(!qq.empty()&&qq.top().k<=k)
		{
			no now=qq.top();qq.pop();
			int x=now.id;
//			cout<<x<<"!\n";
			if(!vs[x])
			{
				if(to[x])run(to[x]);
				else vs[x]=1,Y.fa[x]=x+1,Z.fa[x]=x-1;
			}
//			cout<<Y.fa[4]<<"D\n";
//			cout<<Y.find(4)<<"!!\n";
//			puts("!SDA");
			if(!VVV[x][now.op])
			{
				VVV[x][now.op]=1;
				if(now.op==0)
				{
					int To=Y.find(x);
					if(To!=1e6+1)qq.push({To,now.k+To-x,0});
				}
				else 
				{
					int To=Z.find(x);
					if(To!=0)qq.push({To,now.k+x-To,1});
				}
			}
		}
		while(tt<=q&&Q[tt].K==k)
		{
//			for(int i=1;i<=n;i++)cout<<vs[a[i]]<<" ";
//			puts("");
//			cerr<<Q[tt].K<<" "<<k<<"!DASD\n";
			if(vs[a[Q[tt].I]])ans[Q[tt].id]=1;
			else ans[Q[tt].id]=-1;
			tt++;
		}
	}
	for(int i=1;i<=q;i++)
	{
		if(ans[i]==1)puts("YES");
		else puts("No");
	}
	pc('1',1);
	return 0;
}