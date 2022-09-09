#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int n;

int ask(const string &s)
{
	printf("%s\n",s.c_str()); fflush(stdout);
	int res;
	scanf("%d",&res);
	if(res == n) exit(0);
	return res;
}

int main(void)
{
	scanf("%d",&n);
	
	string A(n, 'F'), B(n, 'F');
	for(int i=1; i<n; i+=2)
		B[i] = 'T';
	int resA = ask(A), resB = ask(B);
	
	string ans(n, 0);
	for(int i=0; i<n; i+=3)
	{
		if(i+3 >= n)
		{
			string s = A;
			s[i] = 'T';
			int cur = ask(s) - resA;
			ans[i] = cur == 1? 'T': 'F';
			i -= 2;
			continue;
		}
		
		string s = A;
		s[i] = s[i+1] = s[i+2] = 'T';
		int cur = ask(s) - resA;
		if(cur == 3 || cur == -3)
		{
			ans[i] = ans[i+1] = ans[i+2] = cur == 3? 'T': 'F';
			continue;
		}
		
		s = B;
		s[i] ^= 'T' ^ 'F'; s[i+1] ^= 'T' ^ 'F';
		int cur2 = ask(s) - resB;
		if(cur2 == 2 || cur2 == -2)
		{
			ans[i] = cur2 == 2? s[i]: B[i];
			ans[i+1] = cur2 == 2? s[i+1]: B[i+1];
			ans[i+2] = cur == 1? 'T': 'F';
		}
		else
		{
			ans[i] = ans[i+1] = cur == 1? 'T': 'F';
			ans[i+2] = ans[i] ^ 'T' ^ 'F';
		}
	}
	ask(ans);
	return 0;
}