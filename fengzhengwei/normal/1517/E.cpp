#include<bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=2e5+5;
ll a[xx];
ll sum[xx];
ll suf[xx]; 
const int mod=998244353;
struct node
{
	ll sum;
	int l,r;
}e[xx*48];
int cst;
void insert(int &k,ll l,ll r,int x,int op)
{
	if(!k)k=++cst,e[k].sum=e[k].l=e[k].r=0;
	e[k].sum+=op;
	if(l==r)return;
	ll mid=l+r>>1;
	if(x<=mid)insert(e[k].l,l,mid,x,op);
	else insert(e[k].r,mid+1,r,x,op);
}
int ask(int k,ll l,ll r,ll x,ll y)
{
	if(x>y)return 0;
	if(x<=l&&r<=y)return e[k].sum;
	ll mid=l+r>>1;
	ll s=0;
	if(x<=mid)s+=ask(e[k].l,l,mid,x,y);
	if(mid<y)s+=ask(e[k].r,mid+1,r,x,y);
	return s;
}
const ll L=-200000000000001ll;
const ll R=200000000000001ll;
signed main(){
//	cout<<sizeof(e)/1024/1024<<"\n";
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
		ll ans=0;
		for(int i=1;i<=n;i++)if(sum[i]!=sum[n]-sum[i])ans++;// 
		//CP()(CP)2~n-1 
		suf[n-1]=a[n-1]; 
//		cout<<ans<<"ssdasda \n";
		for(int i=n-2;i>=2;i--) suf[i]=suf[i+2]+a[i]-a[i+1];//pcpcpc//C 
		int root0=0,root1=0;//01 
//		suf[1]=suf[3]-a[2];
//		for(int i=n-1;i>=1;i--) cout<<i<<" "<<suf[i]<<"\n";
		for(int i=3;i<=n;i++)//1 ()()
		{
			if(i&1)insert(root1,L,R,suf[i]-(sum[i-1]-sum[1]),1);
			else insert(root0,L,R,suf[i]-(sum[i-1]-sum[1]),1);
//			cout<<i<<" "<<suf[i]-(sum[i-1]-sum[1])<<"\n";
		}
		//pcP
		ll ns=0;
		for(int i=n;i>=3;i--)//pi~n-1 sum[n-1]-sum[i-1] (2,2)
		{
			if(i!=n)//c 
			{
				ns=sum[n-1]-sum[i-1]+a[1]-a[n]-suf[i];//p  c
				if(i&1)ans+=ask(root1,L,R,-ns+1,R);
				else ans+=ask(root0,L,R,-ns+1,R);
			}// 
			ns=sum[n-1]-sum[i-1]+a[1]+a[n]-suf[i];//p  p
//				cout<<i<<"\n";
//				cout<<"1:"<<ans<<" "<<ns<<"\n";
			if(i&1)ans+=ask(root1,L,R,-ns+1,R);
			else ans+=ask(root0,L,R,-ns+1,R);
			ans%=mod;
			if(i&1)insert(root1,L,R,suf[i]-(sum[i-1]-sum[1]),-1);
			else insert(root0,L,R,suf[i]-(sum[i-1]-sum[1]),-1);
//				cout<<"2:"<<ans<<"\n";
		}
//		cout<<ans<<"asdaaa \n";
		for(int i=2;i<n;i++)//1 () 
		{
			if(i&1)insert(root1,L,R,suf[i]-(sum[i-1]-sum[1]),1);
			else insert(root0,L,R,suf[i]-(sum[i-1]-sum[1]),1);
		}
		//2C
//		insert(root0,L,R,suf[2]-(sum[2-1]-sum[1]));
		ns=0;
		for(int i=n;i>=2;i--)
		{
			// 
			if(i!=n)
			{
				ns=sum[n-1]-sum[i-1]-a[1]-a[n]-suf[i];//C (C)
//				cout<<i<<"sss \n";
				if(i&1)ans+=ask(root1,L,R,-ns+1,R);
				else ans+=ask(root0,L,R,-ns+1,R);
			}//  ppppcccc()
			if(i!=n)
			{
				if(i&1)insert(root1,L,R,suf[i]-(sum[i-1]-sum[1]),-1);
				else insert(root0,L,R,suf[i]-(sum[i-1]-sum[1]),-1);
			}// 
			ns=sum[n-1]-sum[i-1]-a[1]+a[n]-suf[i];//c  p
			if(i&1)ans+=ask(root1,L,R,-ns+1,R);
			else ans+=ask(root0,L,R,-ns+1,R);
			ans%=mod;
		}
		cout<<ans<<"\n";
	}
	return 0;
}