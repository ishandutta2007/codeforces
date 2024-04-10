#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,k,np;
string s,a[N];
inline char nxt(){return s[np++];}
void solve(int l,int r)
{
	if(l==r||a[l].size()==m)
		return;
	for(int i=l;i<=r;i++)
		a[i]+=nxt();
	int nl=r;
	while(nl>=l&&a[nl].back()==a[r].back())
		nl--;
	solve(nl+1,r);
}
void work(int x)
{
	while(a[x].size()<m)
		a[x]+=nxt();
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>s;
	sort(&s[0],&s[n*m]);
	solve(1,k);
	work(k);
	for(int i=1;i<=n;i++)
		if(i!=k)
			work(i);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<endl;
	return 0;
}