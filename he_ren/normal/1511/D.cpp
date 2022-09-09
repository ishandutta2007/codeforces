#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	
	string s;
	for(int i=1; i<=d; ++i)
	{
		s += 'a' + i - 1;
		for(int j=i+1; j<=d; ++j)
			s += 'a' + i - 1,
			s += 'a' + j - 1;
	}
	
	while((int)s.size() < n) s += s;
	s.resize(n);
	
	cout << s;
	return 0;
}