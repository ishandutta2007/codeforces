#import<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long LL;
LL k,m,n,p,s,a[200004],w[200004];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i)a[i]+=a[i-1];
	}
	w[0]=-1<<30;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		w[i]*=2;
	}
	sort(w+1,w+m+1);
	w[m+1]=1LL<<32;
	for(int i=0;i<n;i++)
	{
		if(lower_bound(w,w+m+1,200*i)==upper_bound(w,w+m+1,200*i))
		{
			k=lower_bound(w,w+m+1,200*i)-w-1;
			p=min(400*i-w[k],w[k+1]);
			p=min(n-1,((p+w[k+1])/2-1)/200);
			s=max(s,a[p]-(i?a[i-1]:0));
		}
	}
	cout<<s;
}