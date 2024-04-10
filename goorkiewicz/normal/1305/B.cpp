#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const int N = 1000005;
int n, i, j;
char s [N];
vector <int> a, b, out;

int main ()
	{
	scanf ("%s", s+1);
	n = strlen(s+1);
	for (i=1; i<=n; i++)
		{
		if (s[i] == '(') a.push_back(i);
		if (s[i] == ')') b.push_back(i);
		}
	reverse(b.begin(), b.end());
	for (i=0; i<min(a.size(), b.size()); i++)
		{
		if (a[i] > b[i])
			break;
		out.push_back(a[i]);
		out.push_back(b[i]);
		}

	sort(out.begin(), out.end());
	
	if (out.size() == 0)
		return printf ("0\n"), 0;

	printf ("%d\n%d\n", 1, (int)(out.size()));
	for (int a : out)
		printf ("%d ", a);
	printf ("\n");
	
	return 0;
	}