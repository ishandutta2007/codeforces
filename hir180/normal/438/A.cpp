#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 100000000
#define fi first
#define sc second

int n,m;
int x[1005];
int main()
{
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> x[i];
	int res = 0;
	for(int i=0;i<m;i++)
	{
		int xx,y;
		cin >> xx >> y;
		res += min(x[xx],x[y]);
	}
	cout << res << endl;
}