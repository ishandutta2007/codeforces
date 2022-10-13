#include <iostream>
#include <string>
#include <set>
#include <utility>
using namespace std;

set < pair<string,string> > ans;

int main()
{
	int n,d,t[1010];
	string a[1010],b[1010];
	
	cin >> n >> d;
	for (int i=0;i<n;i++) cin >> a[i] >> b[i] >> t[i];
	
	for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (a[i]==b[j] && b[i]==a[j] && t[j]>t[i] && t[j]-t[i]<=d)
			{
				ans.insert(make_pair(min(a[i],b[i]),max(a[i],b[i])));
			}
			
	cout << ans.size() << endl;
	for (set < pair<string,string> >::iterator it=ans.begin();it!=ans.end();it++)
		cout << it->first << ' ' << it->second << endl;
}