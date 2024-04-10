#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>v;
int n,x,a[N],b[N];
char c[N];
set<int>s;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		s.insert(-i);
	for(int i=1;i<=2*n;i++)
	{
		cin>>c[i];
		if(c[i]=='+')
		{
			x++;
			v.push_back(x);
		}
		else
		{
			if(!v.size())
			{
				cout<<"NO"<<endl;
				return 0;
			}
			cin>>b[i];
			int y=v.back();
			v.pop_back();
			a[y]=b[i];
			s.erase(-b[i]);
		}
	}
	for(auto y:v)
	{
		a[y]=-(*s.begin());
		s.erase(s.begin());
	}
	x=0;
	for(int i=1;i<=n*2;i++)
	{
		if(c[i]=='+')
		{
			x++;
			s.insert(a[x]);
		}
		else
		{
			int y=*s.begin();
			s.erase(s.begin());
			if(y!=b[i])
			{
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<' ';
	return 0;
}