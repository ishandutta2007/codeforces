#include<bits/stdc++.h>
#define ll long long
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
	pc(x%10+'0',0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
const int xx=2e6+5;
ll f[xx][4],t;
struct Pr{int lx,ly;};
Pr ty[xx][4];
//00,11,20,31 
//ex/fn 
int n,a,b;
//len>10 
int lsh[xx],tt,A[xx],B[xx];
int id[xx],len[xx],zt[xx];
void ad(ll &a,ll b,Pr&now,Pr ls)
{
	if(a<b)a=b,now=ls;
}
//	{(a<b)?a=b:0;}
vector<int>cg;
vector<Pr>fire;
void re(int x,int y)
{
//	cout<<x<<" "<<y<<"ASD\n";
	if(x==0)return;
	int Tx=ty[x][y].lx,Ty=ty[x][y].ly;
	// 
	if((Ty^y)&1)
	{
		cg.push_back(id[x]);
		return re(Tx,Ty);
	}
	if(y==0||y==1)
	{
		if(zt[x]>>y&1)// 
		{
			if(Tx==x)// 
			{
				//kt+k? 
				fire.push_back({id[x]-f[x][y],y});
				return re(Tx,Ty);
			}
			else 
			{
				// 
				fire.push_back({id[x]-f[x][y],y});
				return re(Tx,Ty);
			}
		}
		return re(Tx,Ty);
	}
	// 
	return re(Tx,Ty);
}
int stk[xx],top;
int main(){
	//a 
	n=read(),a=read(),b=read(),t=read();
	for(int i=1;i<=a;i++)lsh[++tt]=A[i]=read();
	for(int i=1;i<=b;i++)lsh[++tt]=B[i]=read();
	sort(lsh+1,lsh+tt+1);
	tt=unique(lsh+1,lsh+tt+1)-lsh-1;
	int ls=-1,ts=0;
	lsh[++tt]=n+2;//n+2n+1 
	for(int i=1;i<=tt;i++)
	{
		if(lsh[i]-ls>1)id[++ts]=ls+1,len[ts]=lsh[i]-ls-1;//id 
		id[++ts]=lsh[i],len[ts]=1;
		ls=lsh[i];
	}
	for(int i=1;i<=a;i++)
		A[i]=lower_bound(id+1,id+ts+1,A[i])-id,zt[A[i]]|=1;//y=0 
	for(int i=1;i<=b;i++)
		B[i]=lower_bound(id+1,id+ts+1,B[i])-id,zt[B[i]]|=2;//y=1
	memset(f,-0x3f,sizeof(f));
	//-1 
	f[0][2]=-1;// 
//	=f[0][3]=-1;
//	cout<<id[1]<<"%$^$%^\n";
	--ts,len[0]=1;
	//ts+1n+2 
	for(int i=0;i<ts;i++)
	{
//		for(int j=0;j<4;j++)cout<<i<<" "<<j<<" "<<f[i][j]<<"!!\n";
		if(!zt[i])
		{
			if(i!=0)
			{
				ad(f[i][2],min(f[i][1],t),ty[i][2],{i,1});
				ad(f[i][2],min(f[i][3],t),ty[i][2],{i,3});
				ad(f[i][3],min(f[i][0],t),ty[i][3],{i,0});
				ad(f[i][3],min(f[i][2],t),ty[i][3],{i,2});
			}
			for(int j=0;j<4;j++)f[i][j]+=len[i]-1;
			for(int j=0;j<4;j++)ad(f[i+1][j],f[i][j]+1,ty[i+1][j],{i,j});
		}
		if(zt[i]==1)
		{
			// 
			//>=t+1 
			if(f[i][0]>=t+1)f[i][0]-=t;
			else f[i][0]=-1e18;
			if(f[i][2]>=t+1)ad(f[i][0],f[i][2]-t,ty[i][0],{i,2});
			f[i][2]=-1e18;// 
			ad(f[i][3],min(f[i][0],t),ty[i][3],{i,0});
			ad(f[i][3],min(f[i][2],t),ty[i][3],{i,2});// 
			//len=1 
			for(int j=0;j<4;j++)ad(f[i+1][j],f[i][j]+1,ty[i+1][j],{i,j});
		}
		if(zt[i]==2)
		{
			if(f[i][1]>=t+1)f[i][1]-=t;
			else f[i][1]=-1e18;
			if(f[i][3]>=t+1)ad(f[i][1],f[i][3]-t,ty[i][1],{i,3});
			f[i][3]=-1e18;// 
			ad(f[i][2],min(f[i][1],t),ty[i][2],{i,1});
			ad(f[i][2],min(f[i][3],t),ty[i][2],{i,3});// 
			//len=1 
			for(int j=0;j<4;j++)ad(f[i+1][j],f[i][j]+1,ty[i+1][j],{i,j});
		}
		if(zt[i]==3)
		{
			
			if(f[i][0]>=t+1)f[i][0]-=t;
			else f[i][0]=-1e18;
			if(f[i][2]>=t+1)ad(f[i][0],f[i][2]-t,ty[i][0],{i,2});
			f[i][2]=-1e18;
			
			if(f[i][1]>=t+1)f[i][1]-=t;
			else f[i][1]=-1e18;
			if(f[i][3]>=t+1)ad(f[i][1],f[i][3]-t,ty[i][1],{i,3});
			f[i][3]=-1e18;
			
			for(int j=0;j<4;j++)ad(f[i+1][j],f[i][j]+1,ty[i+1][j],{i,j});
		}
		
	}
	int cr=0;
	for(int i=0;i<4;i++)if(f[ts][i]>=0)cr=1;
	if(cr)
	{
		puts("Yes");
		int Id=0;
		// 
//		for(int i=3;i>=0;i--)if(f[ts][i]>=0)Id=i;
		for(int i=0;i<=3;i++)if(f[ts][i]>=0)Id=i;
		re(ts,Id);
		reverse(cg.begin(),cg.end());
		reverse(fire.begin(),fire.end());
		int sz=cg.size();
		for(auto it:cg)
		{
			if(top&&stk[top]==it)top--;
			else stk[++top]=it;
		}
		cout<<top<<"\n";
		for(int i=1;i<=top;i++)cout<<stk[i]<<" ";
		puts("");
//		cout<<cg.size()<<"\n";
//		for(auto it:cg)cout<<it<<" ";
//		puts("");
		
		cout<<fire.size()<<"\n";
		for(auto it:fire)cout<<it.lx<<" "<<it.ly+1<<"\n";
		puts("");
//		cerr<<id[ts]<<"ASDAD\n";
	}
	else 
	{
		puts("No");
	}
	pc('1',1);
	return 0;
}