#include<cstdio>
#include<iostream>
#include<stack>
typedef long long ll;
const int MAXN = 1e6 + 5;
const int inf = 1e6 + 5;
using namespace std;

int n,a[MAXN],f[MAXN];
stack<int> s;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll ans=0;
	
	a[0]=a[n+1]=inf;
	
	while(!s.empty()) s.pop();
	s.push(0);
	for(int i=1; i<=n; ++i)
	{
		while(a[s.top()]<a[i]) s.pop();
		f[i]=i-s.top();
		s.push(i);
	}
	
	while(!s.empty()) s.pop();
	s.push(n+1);
	for(int i=n; i>=1; --i)
	{
		while(a[s.top()]<=a[i]) s.pop();
		ans+=(ll)f[i]*(s.top()-i)*a[i];
		s.push(i);
	}
	
	a[0]=a[n+1]=0;
	
	while(!s.empty()) s.pop();
	s.push(0);
	for(int i=1; i<=n; ++i)
	{
		while(a[s.top()]>a[i]) s.pop();
		f[i]=i-s.top();
		s.push(i);
	}
	
	while(!s.empty()) s.pop();
	s.push(n+1);
	for(int i=n; i>=1; --i)
	{
		while(a[s.top()]>=a[i]) s.pop();
		ans-=(ll)f[i]*(s.top()-i)*a[i];
		s.push(i);
	}
	
	cout<<ans;
	return 0;
}