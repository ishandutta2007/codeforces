#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005];
int main(){
	int T;
	cin>>T;
	cout.precision(20);
	while(T-->0)
	{
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		int sa=0,sb=0;
		cin>>n;
		for(int i=1;i<=2*n;++i)
		{
			int x,y;
			cin>>x>>y;
			x=(x<0)?-x:x,y=(y<0)?-y:y;
			if(!x)	a[++sa]=y;
			else	b[++sb]=x;
		}
		sort(a+1,a+1+n),sort(b+1,b+1+n);
		long double ans=0,ans2=0;
		for(int i=1;i<=n;++i)
		{
			long long p=(long long)a[i]*(long long)a[i]+(long long)b[i]*(long long)b[i];
			ans+=(long double)sqrt(p);
		}
		for(int i=1;i<=n;++i)
		{
			long long p=(long long)a[i]*(long long)a[i]+(long long)b[n-i+1]*(long long)b[n-i+1];
			ans2+=(long double)sqrt(p);
		}
		cout<<min(ans,ans2)<<endl;
	}
	return 0;
}