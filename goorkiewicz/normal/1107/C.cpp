#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, i, j, k;
int a [200003];
char s [200003];
vector <int> vec;
ll out;

int main ()
	{
	scanf ("%d%d",&n,&k);
	for (i=1; i<=n; i++)
		scanf ("%d",&a[i]);
	scanf ("%s",s+1);
	for (i=1; i<=n+1; i++)
		{
		if (s[i]!=s[i-1])
			{
			sort(vec.begin(), vec.end(), greater<int>());
			for (j=0; j<k && j<vec.size(); j++)
				out+=(ll)(vec[j]);
			vec.clear();
			}
		vec.push_back(a[i]);
		}
	printf ("%lld\n",out);
	return 0;
	}