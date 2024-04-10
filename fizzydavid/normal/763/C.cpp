//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const int magic=66;
int mod,n,nn;
int a[100111],na[100111];
set<int>st,nst;
pair<int,int> solve()
{
/*	cout<<"n="<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}cout<<endl;*/
	if(n==1)return MP(0,1);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)continue;
		int lcnt=0,rcnt=1;
		ll t=a[i];
		for(int j=1;j<n;j++)
		{
			if(st.find(1ll*j*t%mod)==st.end())break;
			rcnt++;
		}
		for(int j=1;j<n&&lcnt+rcnt<n;j++)
		{
			if(st.find(1ll*(mod-j)*t%mod)==st.end())break;
			lcnt++;
		}
//		cout<<i<<":"<<lcnt<<" "<<rcnt<<endl;
		if(lcnt+rcnt==n)return MP(1ll*(mod-lcnt)*a[i]%mod,a[i]);
	}
	puts("-1");
	exit(0);
}
int main()
{
	scanf("%d%d",&mod,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		st.insert(a[i]);
	}
	if(n==mod)
	{
		cout<<0<<" "<<1<<endl;
		return 0;
	}
	bool flag=0;
	if(mod-n<n)
	{
		flag=1;
		for(int i=0;i<mod;i++)
		{
			if(st.find(i)==st.end())
			{
				na[++nn]=i;
				nst.insert(i);
			}
		}
		swap(st,nst);
		swap(a,na);
		swap(n,nn);
	}
//	cout<<"n="<<n<<endl;
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";cout<<endl;
	for(int i=2;i<=n;i++)a[i]=(a[i]-a[1]+mod)%mod;
	int tmp=a[1];
	a[1]=0;
	st.clear();
	for(int i=1;i<=n;i++)st.insert(a[i]);
	pair<int,int> ans;
/*	if(mod-n<n)
	{
		for(int i=2;i<=n;i++)a[i]-=a[1];
		int ttmp=a[1];
		a[1]=0;
		ans=solve();
		ans.FF=(ans.FF+ttmp-1ll*nn*ans.SS%mod+mod)%mod;
	}
	else ans=solve();*/
	ans=solve();
	ans.FF=(ans.FF+tmp)%mod;
	if(flag)ans.FF=(ans.FF-1ll*nn*ans.SS%mod+mod)%mod;
	cout<<ans.FF<<" "<<ans.SS<<endl;
	return 0;
}