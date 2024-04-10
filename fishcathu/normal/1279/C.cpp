#include<iostream>
#include<set>
#include<deque>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int m,n;x--;)
	{
		cin>>m>>n;
		set<int>s;
		deque<int>d;
		long long ans=n;
		for(int i;m--;)
		{
			cin>>i;
			d.push_back(i);
		}
		for(int i;n--;)
		{
			cin>>i;
			if(s.count(i))s.erase(i);
			else
			{
				while(d.front()!=i)
				{
					s.insert(d.front());
					d.pop_front();
				}
				d.pop_front();
				ans+=2*s.size();
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}