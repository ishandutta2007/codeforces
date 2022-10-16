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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
//23.51
int f[77][77][77],n;//i,V,K 
char s[78];
vector<int>pos[3];
int to[500],sz[3];
struct nod
{
	int sum[77];
	void pr(){for(int i=1;i<=n;i++)sum[i]+=sum[i-1];}
	void col(vector<int>&v,int sz)
	{
		if(!sz)return;
		vector<int>::iterator it=--v.end();
		while(sz--)sum[*it--]=1;
	}
	void cls(){memset(sum,0,sizeof(sum));}
}fK,fV,fi,flp;
void ad(int &a,int b){a>b?a=b:0;}
signed main(){
	for(int i=0;i<500;i++)to[i]=2;
	to['V']=0,to['K']=1;
	memset(f,0x3f,sizeof(f));
	n=read();
	scanf("%s",s+1);
	s[++n]='A';// 
	for(int i=1;i<=n;i++)pos[to[s[i]]].push_back(i);
	for(int i=0;i<3;i++)sz[i]=pos[i].size();
	f[0][0][0]=0;
//	cout<<sz[0]<<" "<<sz[1]<<" "<<sz[2]<<"!!\n";
	for(int i=0;i<sz[2];i++)
	{
		for(int j=0;j<=sz[0];j++)
		{
			for(int k=0;k<=sz[1];k++)
			{
				fK.cls();
				fK.col(pos[2],sz[2]-i);
				fK.col(pos[0],sz[0]-j);fK.pr();
				for(int a=0;a+j<=sz[0];a++)
				{
					fi.cls();
					fi.col(pos[0],sz[0]-j-a);
					fi.col(pos[1],sz[1]-k);fi.pr();
					int Tok=0,Toi=fi.sum[pos[2][i]],Tov=0;
					fV.cls();
					fV.col(pos[2],sz[2]-i);
					fV.col(pos[1],sz[1]-k);fV.pr();
					for(int s=j+1;s<=j+a;s++)Tov+=fV.sum[pos[0][s-1]];
					flp.cls();
					for(int s=j+1;s<=j+a;s++)flp.sum[n-pos[0][s-1]+1]=1;
					flp.pr();
					for(int b=0;b+k<=sz[1];b++)
					{
						if(b!=0)Tok+=fK.sum[pos[1][k+b-1]];
						if(b!=0)Toi-=pos[2][i]>=pos[1][k+b-1];
						if(b!=0)Tov-=flp.sum[n-pos[1][k+b-1]+1];
//						if(f[i][j][k]>19)continue;
						int To=Tok+Toi+Tov;
//						//k For K 
//						memset(sum,0,sizeof(sum));
//						col(pos[2],sz[2]-i);
//						col(pos[0],sz[0]-j);pr();
//						for(int s=k+1;s<=k+b;s++)To+=sum[pos[1][s-1]];
//						
//						//v For V 
//						memset(sum,0,sizeof(sum));
//						col(pos[2],sz[2]-i);
//						col(pos[1],sz[1]-k-b);pr();
//						for(int s=j+1;s<=j+a;s++)To+=sum[pos[0][s-1]];
//						
//						// For i 
//						memset(sum,0,sizeof(sum));
//						col(pos[0],sz[0]-j-a);
//						col(pos[1],sz[1]-k-b);pr();
//						To+=sum[pos[2][i]];
//						
						ad(f[i+1][j+a][k+b],f[i][j][k]+To);
//						cout<<i<<" "<<j<<" "<<k<<" "<<a<<" "<<b<<" "<<To<<"\n";
					}
				}
			}
		}
	}
	cout<<f[sz[2]][sz[0]][sz[1]]<<'\n';
	pc('1',1);
	return 0;
}