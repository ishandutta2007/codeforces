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
	pc('0'+x%10,0);
}
void wts(int x,char c)
{
	if(x<0)x=-x,pc('-',0);
	wt(x);pc(c,0);
}
const int xx=1e5+5;
int vs[xx],prim[xx];
ll fi[xx];
void pre()
{
	int cnt=0;
	for(int i=2;i<xx;i++)
	{
		if(!vs[i])prim[++cnt]=i,fi[i]=i-1;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>=xx)break;
			vs[prim[j]*i]=1;
			if(i%prim[j]==0)
			{
				fi[i*prim[j]]=fi[i]*prim[j];
				break;
			}
			fi[i*prim[j]]=fi[i]*fi[prim[j]];
		}
	}
	fi[1]=1;
	for(int i=2;i<xx;i++)fi[i]+=fi[i-1];
}
ll S[201][xx];
ll w(int L,int R)
{
	if(L>R)return 1e18;
//	if(L<=200&&S[L][R]!=-1)return S[L][R];
	ll ans=0;
	for(int l=L,r;l<=R;l=r+1)
	{
		r=(R/(R/l));
		ans+=fi[R/l]*(r-l+1);
	}
//	if(L<=200)return S[L][R]=ans;
	return ans;
}
ll f[xx][19],now;
void ef(int l,int r,int L,int R)
{
//	cout<<l<<" "<<r<<" "<<L<<" "<<R<<"!\n";
	if(l>r)return;
	if(L==R)
	{
		
		for(int i=l;i<=r;i++)
		{
			f[i][now]=f[L-1][now-1]+w(L,i);
//			if(i==4975)cout<<L<<"!!\n";
		}
		return;
	}
	int mid=l+r>>1,zy=L;
	ll zval=f[L-1][now-1]+w(L,mid);
	for(int i=L+1;i<=min(R,mid);i++)
	{
		ll a;
		if((a=f[i-1][now-1]+w(i,mid))<zval)zval=a,zy=i;
	}
//	cout<<mid<<" "<<L<<" "<<R<<" "<<zval<<" "<<zy<<" "<<w(1,mid)<<" "<<f[L-1][now-1]<<"!!\n";
	f[mid][now]=zval;
	ef(l,mid-1,L,zy);
	ef(mid+1,r,zy,R);
}
int main(){
	memset(S,-1,sizeof(S));
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	pre();
	for(int i=1;i<=16;i++)now=i,ef(1,1e5,1,1e5);
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		if(k>=(int)log2(n)+1){cout<<n<<"\n";continue;}
		cout<<f[n][k]<<"\n";
	}
	pc('1',1);
	return 0;
}