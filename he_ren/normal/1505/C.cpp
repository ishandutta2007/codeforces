#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(void)
{
	string s;
	cin >> s;
	
	for(int i=2; i<(int)s.size(); ++i)
		if(s[i] - 'A' != (s[i-1] - 'A' + s[i-2] - 'A') % 26)
			return printf("NO"), 0;
	printf("YES");
	return 0;
}