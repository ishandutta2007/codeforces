#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

int d[1000010],p[1000000],P;

int emirp(int x)
{
	if (d[x]) return 0;
	stringstream ss;
	string s;
	ss << x;
	ss >> s;
	reverse(s.begin(),s.end());
	int y;
	ss.clear();
	ss << s;
	ss >> y;
	return !d[y] && x!=y;
}

int main()
{
	for (int i=2;i<1000;i++)
		if (!d[i]) 
			for (int j=i*i;j<=1000000;j+=i)
				d[j]=1;
	for (int i=2;i<1000000;i++)
		if (!d[i]) p[++P]=i;
		
	int n,x=12;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		x++;
		while (!emirp(x)) x++;
	}
	cout << x << endl;
}