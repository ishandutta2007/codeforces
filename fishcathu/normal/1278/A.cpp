#include<iostream>
#include<algorithm>
using namespace std;
bool f(string a,string b)
{
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	return a==b;
}
int main()
{
	int x;
	cin>>x;
	for(string a,b;x--;)
	{
		cin>>a>>b;
		int as=a.size(),bs=b.size();
		if(as>bs)
		{
			cout<<"NO\n";
			continue;
		}
		else 
		{
			int i;
			for(i=0;i<=bs-as&&!f(b.substr(i,as),a);i++);
			if(i>bs-as)cout<<"NO\n";
			else cout<<"YES\n";
		}
	}
	return 0;	
}