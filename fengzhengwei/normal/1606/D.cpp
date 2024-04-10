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
	((op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf));
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(c,0);
}
vector<vector<int> >v;
const int xx=5e5+5;
vector<vector<int> >vmx,vmn;
int lmx[xx],lmn[xx],ans[xx];
int main(){
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		v.clear();
		vmx.clear();
		vmn.clear();
		v.resize(n+1);
		vmx.resize(n+1);
		vmn.resize(n+1);
		for(int i=1;i<=n;i++)
		{
			v[i].resize(m+1);
			vmx[i].resize(m+1);
			vmn[i].resize(m+1);
			for(int j=1;j<=m;j++)
				v[i][j]=read();
		}
		for(int j=m;j>=1;j--)
		{
			for(int i=1;i<=n;i++)
			{
				if(j==m)vmx[i][j]=vmn[i][j]=v[i][j];
				else vmx[i][j]=max(v[i][j],vmx[i][j+1]),vmn[i][j]=min(v[i][j],vmn[i][j+1]);
			}
		}
		for(int j=1;j<m;j++)
		{
			vector<pair<int,int> >V;
			for(int i=1;i<=n;i++)
			{
				if(j==1)lmx[i]=lmn[i]=v[i][j];
				else lmx[i]=max(lmx[i],v[i][j]),lmn[i]=min(lmn[i],v[i][j]);
			}
			for(int i=1;i<=n;i++)V.push_back(make_pair(-vmx[i][j+1],i));
			sort(V.begin(),V.end());
			//
			// 
			multiset<int>red,blue;
			for(int i=1;i<=n;i++)red.insert(lmn[i]);
			int blu=1e9;
			for(int i=0;i<n-1;i++)// 
			{
				int x=V[i].second;
				blue.insert(lmx[x]);
				red.erase(red.find(lmn[x]));
				blu=min(blu,vmn[x][j+1]);
				if(*--blue.end()>=*red.begin())continue;
				if(blu>-V[i+1].first)
				{
					puts("YES");
					for(int k=1;k<=n;k++)ans[k]=0;
					for(int k=0;k<=i;k++)ans[V[k].second]=1;//1 
					for(int k=1;k<=n;k++)
					{
						if(ans[k]==1)cout<<"B";
						else cout<<"R";
					}
					cout<<" "<<j<<'\n';
					goto I;
				}
			}
		}
		puts("NO");
		I:;
	}
	return 0;
}