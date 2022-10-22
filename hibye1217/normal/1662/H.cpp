#import<bits/stdc++.h>
#define endl '\n'
using namespace std;
int a,b,t,w;
set<int>S;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(cin>>t;t--;)
	{
		cin>>a>>b;
		w=__gcd(a-2,b);
		for(int i=1;i*i<=w;i++)
		{
			if(w%i==0)
			{
				S.insert(i);
				S.insert(w/i);
			}
		}
		w=__gcd(a-1,b-1);
		for(int i=1;i*i<=w;i++)
		{
			if(w%i==0)
			{
				S.insert(i);
				S.insert(w/i);
			}
		}
		w=__gcd(a,b-2);
		for(int i=1;i*i<=w;i++)
		{
			if(w%i==0)
			{
				S.insert(i);
				S.insert(w/i);
			}
		}
		S.insert(2);
		cout<<S.size()<<' ';
		for(auto &p:S)cout<<p<<' ';
		cout<<endl;
		S.clear();
	}
}