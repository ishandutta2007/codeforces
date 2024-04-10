#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
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
const int mod=998244353;
int n,k,ans;
vector<int>s;
bool check()
{
	vector<int>now;
	now=s;
	int t=k-1;
	while(t--)
	{
		vector<int>lin;
		reverse(now.begin(),now.end());
		int res=0,re=1;
		for(auto it:now)
		{
			res+=it*re;
			if(res>n)return 0;
			while(it--)lin.push_back(re);
			re++;
		}
		swap(lin,now);
//		cout<<res<<"!!\n";
	}
//	for(auto it:s)cout<<it<<" ";
//	puts("");
	return 1;
}
void dfs(int lst)
{
	for(int i=lst;;i++)
	{
		s.push_back(i);
		int cr;
		if(cr=check())ans++,dfs(i);
		s.pop_back();
		if(!cr)break;
	}
}
int f[2022][2022];///lst 
//struct nod
//{
//	int tt,sum,lst;
//	bool operator<(const nod&w)const{return tt==w.tt?sum==w.sum?lst<w.lst}
//}
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int main(){
	n=read(),k=read();
	if(k>=3)//1s 
	{
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	if(k==1)//sigma<=n Cf1s 
	{
		f[0][1]=1;
		int ans=0;//n^2 
		for(int i=0;i<=n;i++)
			for(int j=1;j<=n;j++)
			{
				if(!f[i][j])continue;
				ad(ans,f[i][j]);
				for(int k=j;k+i<=n;k++)
					ad(f[i+k][k],f[i][j]);
			}
		cout<<(ans-1+mod)%mod<<"\n";
		exit(0);
	}
	if(k==2)
	{
		//40 
		//40 
		// 
		f[0][0]=1;//itotsum .
		int ans=0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(i)ad(ans,f[i][j]);
				if(j+(i+1)<=n)
				ad(f[i+1][j+(i+1)],f[i][j]);
				if(j+(1+i)*i/2<=n)
				ad(f[i][j+(1+i)*i/2],f[i][j]);
			}
		}
		cout<<ans<<"\n";
//		f[0][1]=1;
//		int ans=0;
//		for(int i=0;i<=n;i++)
//			for(int j=1;j<=n;j++)
//			{
//				if(!f[i][j])continue;
//				ad(ans,f[i][j]);
//				///fn 
////				cout<<i<<" "<<j<<" "<<f[i][j]<<"\n";
//				//sum... 
//				for(int k=j;k+i+i<=n;k++)
//					ad(f[k+i+i][k],f[i][j]);
//			}
//		cout<<(ans-1+mod)%mod<<"\n";
		exit(0);
	}
	pc('1',1);
	return 0;
}