#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, i, j, a, b;
ll out, cnt, res;
char s [N];
vector <int> v [30];
vector <int> v1, v2;

int main ()
	{
	scanf ("%s", s+1);
	
	n = strlen(s+1);

	for (i=1; i<=n; i++)
		{
		s[i] -= 'a';
		v[s[i]].push_back(i);
		}

	for (i=0; i<26; i++)
		out = max(out, (ll)(v[i].size()));
	
	for (a=0; a<26; a++)
		for (b=0; b<26; b++)
			{
			if (a == b)
				{
				res = (1ll * v[a].size() * (v[a].size() - 1)) / 2ll;
				out = max(out, res);
				continue;
				}
			
			v1 = v[a];
			v2 = v[b];
			
			cnt = 0;
			res = 0;
			
			reverse(v1.begin(), v1.end());
			reverse(v2.begin(), v2.end());
			
			while (!v2.empty())
				{
				if (!v1.empty() && v1.back() < v2.back())
					{
					cnt++;
					v1.pop_back();
					}
				else
					{
					res += cnt;
					v2.pop_back();
					}
				}
			
			out = max(out, res);
			}

	printf ("%lld\n", out);
	return 0;
	}