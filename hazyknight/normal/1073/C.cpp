#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

const int MAXN = 200005;

int n,x,y,ans;
int U[MAXN];
int D[MAXN];
int L[MAXN];
int R[MAXN];

string s;

int sum(int *arr,int l,int r)
{
	return arr[r] - arr[l - 1];
}

bool ok(int len,int X,int Y)
{
	if (len % 2 != ((X + Y) % 2 + 2) % 2)
		return false;
	if (len < abs(X) + abs(Y))
		return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> s >> x >> y;
	if (!ok(n,x,y))
	{
		cout << -1 << endl;
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		U[i] = U[i - 1] + (s[i - 1] == 'U');
		D[i] = D[i - 1] + (s[i - 1] == 'D');
		L[i] = L[i - 1] + (s[i - 1] == 'L');
		R[i] = R[i - 1] + (s[i - 1] == 'R');
	}
	ans = n;
	for (int i = 1;i <= n;i++)
	{
		int low = i - 1,high = n;
		while (low < high)
		{
			int mid = (low + high) >> 1;
			int X = x - (sum(R,1,i - 1) + sum(R,mid + 1,n) - sum(L,1,i - 1) - sum(L,mid + 1,n));
			int Y = y - (sum(U,1,i - 1) + sum(U,mid + 1,n) - sum(D,1,i - 1) - sum(D,mid + 1,n));
			if (ok(mid - i + 1,X,Y))
				high = mid;
			else
				low = mid + 1;
		}
		int mid = low;
		int X = x - (sum(R,1,i - 1) + sum(R,mid + 1,n) - sum(L,1,i - 1) - sum(L,mid + 1,n));
		int Y = y - (sum(U,1,i - 1) + sum(U,mid + 1,n) - sum(D,1,i - 1) - sum(D,mid + 1,n));
		if (ok(mid - i + 1,X,Y))
			ans = min(ans,mid - i + 1);
	}
	cout << ans << endl;
	return 0;
}