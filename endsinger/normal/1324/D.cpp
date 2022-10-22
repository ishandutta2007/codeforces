#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,a[N],b[N],bit[N],x[N],y[N];
vector<int>v;
long long ans;
void add(int x)
{
	for(int i=x;i<=2*n;i+=i&(-i))
		bit[i]++;
}
int sum(int x)
{
	int s=0;
	for(int i=x;i;i-=i&(-i))
		s+=bit[i];
	return s;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
	{
		x[i]=a[i]-b[i];
		y[i]=b[i]-a[i];
		v.push_back(x[i]);
		v.push_back(y[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
	{
		x[i]=lower_bound(v.begin(),v.end(),x[i])-v.begin()+1;
		y[i]=lower_bound(v.begin(),v.end(),y[i])-v.begin()+1;
		ans+=sum(2*n)-sum(y[i]);
		add(x[i]);
	}
	cout<<ans<<endl;
	return 0;
}