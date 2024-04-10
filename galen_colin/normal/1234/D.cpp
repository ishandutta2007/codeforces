/* testing code for pranaykanjolia */

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	string s;
	cin>>s;
	long long int q,i;
	cin>>q;
	vector<set<long long int>> v(26);
	for(i=0;i<(long long int)s.size();i++)
		v[s[i]-'a'].insert(i);
	while(q--)
	{
		int x;
		cin>>x;
		if(x==1)
		{
			char k;
			long long int pos;
			cin>>pos;
			pos--;
			k=s[pos];
			v[k-'a'].erase(pos);
			cin>>k;
			v[k-'a'].insert(pos);
			s[pos] = k; /* added this line */
		}
		else
		{
			long long int l,r,ans=0;
			cin>>l>>r;
			l--,r--;
			for(auto itr=(v).begin();itr!=(v).end();itr++)
			{
				auto it=(*itr).lower_bound(l);
				if(it!=(*itr).end()  && *it<=r)
					ans++;
			}
			cout<<ans<<endl;
		}
	}
}