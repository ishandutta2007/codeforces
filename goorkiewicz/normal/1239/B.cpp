#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 300005;
int n, m, i, j, a, b, out, cnt, out1, out2;
int t [N+5];
char s [N+5];
vector <int> pool [N+N+10];
vector <int>* vec = pool+N+5;

int counttt (int a, int b, int v)
	{
	int res = 0;
	res += (int)(lower_bound(vec[v].begin(), vec[v].end(), b) - vec[v].begin());
	res -= (int)(lower_bound(vec[v].begin(), vec[v].end(), a) - vec[v].begin());
	return res;
	}

int main ()
	{
	scanf ("%d",&n);
	scanf ("%s",s+1);
	for (i=1; i<=n; i++)
		{
		t[i] = t[i-1];
		if (s[i]=='(') t[i]++;
		if (s[i]==')') t[i]--;
		m = min(m, t[i]);
		vec[t[i]].push_back(i);
		}
	
	if (t[n]!=0)
		return printf ("0\n1 1\n"), 0;

	out = vec[m].size();
	out1 = 1;
	out2 = 1;
	
	for (i=0; i+1<vec[m].size(); i++)
		{
		j = i+1;
		a = vec[m][i];
		b = vec[m][j];
		
		cnt = counttt(a, b, m+1);
		
		if (cnt>out)
			{
			out = cnt;
			out1 = a+1;
			out2 = b;
			}
		}

	a = vec[m].back(); 
	b = vec[m][0];
	cnt = counttt(a, n+5, m+1);
	cnt += counttt(-5, b, m+1);
	
	if (cnt>out)
		{
		out = cnt;
		out1 = a+1;
		out2 = b;
		}
	
	for (i=0; i+1<vec[m+1].size(); i++)
		{
		j = i+1;
		a = vec[m+1][i];
		b = vec[m+1][j];

		if (counttt(a, b, m)!=0)
			continue;

		cnt = counttt(a, b, m+2);

		if (cnt+vec[m].size()>out)
			{
			out = cnt+vec[m].size();
			out1 = a+1;
			out2 = b;
			}
		}

	a = vec[m+1].back();
	b = vec[m+1][0];
	
	cnt = counttt(a, n+5, m);
	cnt += counttt(-5, b, m);

	if (cnt==0)
		{
		cnt = counttt(a, n+5, m+2);
		cnt += counttt(-5, b, m+2);
		if (cnt+vec[m].size()>out)
			{
			out = cnt+vec[m].size();
			out1 = a+1;
			out2 = b;
			}
		}

	if (out1>n) out1 -= n;
	if (out2>n) out2 -= n;
	if (out1>out2) swap(out1, out2);
	printf ("%d\n%d %d\n", out, out1, out2);
	return 0;
	}