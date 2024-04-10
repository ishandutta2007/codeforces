#include<bits/stdc++.h>
#define ll long long
#define dd double
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
int n,k;
const int xx=75;
string op[6]={">","<",">=","<=","=","="};// 
vector<pair<int,int> >v[xx];//ij 
int get(string s)
{
	for(int i=0;i<6;i++)
		if(s==op[i])return i;
	return 0;
}
ll f[xx][xx][2];
//ij 
int main(){
	n=read(),k=read();
	for(int i=1;i<=k;i++)
	{
		int a=read();
		string o;
		cin>>o;
		int b=read();
		v[a].push_back(make_pair(b,get(o)));
		v[b].push_back(make_pair(a,get(o)^1));
	}
	ll ans=0;
	// 
	for(int Q=1;Q<n+n;Q++)// 
	{
		memset(f,0,sizeof(f));
		f[0][0][0]=1;
		// 
		for(int i=0;i<n+n;i++)
			for(int j=0;j<=i;j++)
		for(int k=0;k<=1;k++)
		{
			if(!f[i][j][k])continue;
			if(i+1!=n+n&&!((i&1)&&k==1))
			//() 
			{
				int vs=1;
				for(auto it:v[j+1])// 
				{
					int Op=it.second;
					if(it.first<=Q&&j>=it.first)// 
					{
						if(Op==4||Op==5||Op==3)// 
						{
							if(!(((i&1)&&k==0)&&j==it.first)){vs=0;break;}// 
						}
						if(Op==2)//>= 
							continue;
						if(Op==1){vs=0;break;}// 
						if(Op==0)
						{
							if(((i&1)&&k==0)&&j==it.first){vs=0;break;}
							// 
						}
					}
					if(it.first>=Q+1&&i-j>=n+n-it.first+1)// 
					{
						if(Op==4||Op==5||Op==3)// 
						{
							vs=0;break;
						}// 
						if(Op==2||Op==0)
							continue;
						if(Op==1){vs=0;break;}
					}
				}
				if(vs)f[i+1][j+1][0]+=f[i][j][k];
			}
			if(i+1!=n+n-1)// 
			{
				int vs=1;
				for(auto it:v[n+n-(i+1-j)+1])// 
				{
					int Op=it.second;
					if(it.first<=Q&&j>=it.first)// 
					{
						if(Op==4||Op==5||Op==3)// 
						{
							if(!(((i&1)&&k==0)&&j==it.first)){vs=0;break;}
						}
						if(Op==2)//>= 
							continue;
						if(Op==1){vs=0;break;}// 
						if(Op==0)
						{
							if(((i&1)&&k==0)&&j==it.first){vs=0;break;}
							// 
						}
					}
					if(it.first>=Q+1&&i-j>=n+n-it.first+1)// 
					{
						if(Op==4||Op==5||Op==3)// 
						{
							if(!(((i&1)&&k==1)&&n+n-(i-j)+1==it.first)){vs=0;break;}
						}
						// 
						if(Op==2)
							continue;
						if(Op==1){vs=0;break;}// 
						if(Op==0)
						{
							if(((i&1)&&k==1)&&n+n-(i-j)+1==it.first){vs=0;break;}
							// 
						}
					}
				}
				if(vs)f[i+1][j][1]+=f[i][j][k];
//				{
//					cout<<n+n-(i+1-j)+1<<" ss "<<j<<" "<<i+1-j<<" "<<f[i][j][k]<<"\n";
//				}
			}
		}
//		if(f[n+n][Q][1])
//		{
//			cout<<Q<<"QQQ\n";
//		}
		ans+=f[n+n][Q][1];
	}
	cout<<ans<<"\n";
	return 0;
}