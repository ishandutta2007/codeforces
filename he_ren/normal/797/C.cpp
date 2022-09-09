#include<cstdio>
#include<cstring>
#include<stack>
const int MAXN = 1e5 + 5;
using namespace std;

char s[MAXN],f[MAXN];
stack<char> t;

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	
	f[n]=s[n];
	for(int i=n-1; i>=1; --i)
		f[i] = min(s[i], f[i+1]);
	
	for(int i=1; i<=n; ++i)
	{
		while(!t.empty() && t.top()<=f[i])
		{
			putchar(t.top());
			t.pop();
		}
		if(f[i]==s[i]) putchar(s[i]);
		else t.push(s[i]);
	}
	while(!t.empty())
	{
		putchar(t.top());
		t.pop();
	}
	return 0;
}