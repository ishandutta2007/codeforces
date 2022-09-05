//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
typedef long long ll;
const int Imx=2147483647;
const int mod=1000000007;
const ll Lbg=2e18;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c>='0'&&c<='9')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
int q;
ll pw2[111],sum[31];
ll calc(int t,int qx,int qy,int k,int bs=0)
{
	if(qx<=0||qy<=0||k<=0)return 0;
	if(t==0)return bs+1;
	if(qx>qy)return calc(t,qy,qx,k,bs);
//	cout<<"calc:"<<t<<" "<<qx<<" "<<qy<<" "<<k<<" "<<bs<<endl;
	int l=1<<t,hl=l>>1;
	if(qx==l&&qy==l)
	{
		if(k>=l)return (sum[t]+1ll*bs*pw2[t*2])%mod;
		else
		{
			return (calc(t-1,hl,hl,k,bs)*2+calc(t-1,hl,hl,k-hl,bs+hl)*2)%mod;
		}
	}
	int xu=min(hl,qx),xd=max(0,qx-hl);
	int yl=min(hl,qy),yr=max(0,qy-hl);
	if(qy==l&&k>=l)
	{
		ll ret=0;
		return (calc(t-1,xu,hl,k,bs)*2+calc(t-1,xd,hl,k,bs)*2+1ll*hl*qx%mod*hl)%mod;
	}
	else
	{
		ll ret=0;
		ret+=calc(t-1,xd,yr,k,bs);
		ret+=calc(t-1,xu,yl,k,bs);
		ret+=calc(t-1,xd,yl,k-hl,bs+hl);
		ret+=calc(t-1,xu,yr,k-hl,bs+hl);
		return ret%mod;
	}
}
int main()
{
	pw2[0]=1;
	for(int i=1;i<=100;i++)pw2[i]=pw2[i-1]*2%mod;
	sum[0]=1;
	for(int i=1;i<=30;i++)sum[i]=(sum[i-1]*4+pw2[3*(i-1)+1])%mod;
	geti(q);
	while(q--)
	{
		int X1,Y1,X2,Y2,k;
		getiii(X1,Y1,X2);
		getii(Y2,k);
		ll ans1=+calc(30,X2,Y2,k);
		ll ans2=-calc(30,X1-1,Y2,k);
		ll ans3=-calc(30,X2,Y1-1,k);
		ll ans4=+calc(30,X1-1,Y1-1,k);
//		cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4<<endl;
		putsi(((ans1+ans2+ans3+ans4)%mod+mod)%mod);
	}
	return 0;
}