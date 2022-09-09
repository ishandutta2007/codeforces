#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;

int n;
char s[MAXN];

int main(void)
{
	scanf("%s",s+1);
	n = strlen(s+1);
	
	string x,y;
	for(int i=1,j=n; i<=j;)
	{
		if(i == j){ x += s[i]; break;}
		if(s[i] == s[j]){ x += s[i++]; y += s[j--]; continue;}
		if(s[i+1] == s[j]) ++i;
		else if(s[i] == s[j-1]) --j;
		else ++i, --j;
	}
	
	reverse(y.begin(),y.end());
	cout << x << y;
	return 0;
}