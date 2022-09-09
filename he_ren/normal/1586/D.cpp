#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

inline int ask(const vector<int> &vec)
{
	printf("? ");
	for(int x: vec) printf("%d ",x);
	printf("\n");
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

int p[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	
	for(int i=1; i<=n; ++i)
	{
		vector<int> vec(n-1, n);
		vec.push_back(i);
		int res = ask(vec);
		if(res != 0)
		{
			p[n] = n + 1 - i;
			break;
		}
	}
	if(p[n] == 0) p[n] = 1;
	
	for(int i=1; i<=n; ++i) if(i != p[n])
	{
		vector<int> vec;
		if(i < p[n])
			vec = vector<int>(n-1, n), vec.push_back(i + n - p[n]);
		else
			vec = vector<int>(n-1, 1), vec.push_back(i + 1 - p[n]);
		p[ask(vec)] = i;
	}
	
	printf("! ");
	for(int i=1; i<=n; ++i) printf("%d ",p[i]);
	fflush(stdout);
	return 0;
}