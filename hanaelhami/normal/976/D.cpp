#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e3 + 20;

bool A[maxn][maxn];

int d[maxn];

vector<pair<int , int> > ans;

void solve(set<int> &a)
{
	if((int)a.size() == 1)
	{
		int k = *a.begin();	

		for(int i = 0; i < k + 1; i++)
			for(int j = i + 1; j < k + 1; j++)
				A[i][j] = A[j][i] = 1;
		return;
	}

	set<int> tmp;

	int k = *a.rbegin() , mn = *a.begin();

	for(auto x : a)
		if(x != k)
			tmp.insert(k - x);
	solve(tmp);

	for(int i = 0; i <= k - mn; i++)
		for(int j = i + 1; j <= k - mn; j++)
			A[i][j] = !A[i][j] , A[j][i] = !A[j][i];

	for(int i = 0; i <= k - mn; i++)
		for(int j = k - mn + 1; j <= k; j++)
			A[i][j] = A[j][i] = 1;

	for(int i = k - mn + 1; i <= k; i++)
		for(int j = i + 1; j <= k; j++)
			A[i][j] = A[j][i] = 1;
}

int main()
{
	int m;
	cin >> m;

	set<int> tmp;
	for(int i = 0; i < m; i++)
		cin >> d[i] , tmp.insert(d[i]);

	solve(tmp);

	for(int i = 0; i <= d[m - 1]; i++)
		for(int j = i + 1; j <= d[m - 1]; j++)
			if(A[i][j])
				ans.pb({i , j});

	printf("%d\n", (int)ans.size());
	for(auto x : ans)
		printf("%d %d\n", x.first + 1 , x.second + 1);

}