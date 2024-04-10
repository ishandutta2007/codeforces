#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400005;

int T,n,m;
int a[MAXN];
int b[MAXN];

bool vis[MAXN];

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 1;i <= n;i++)
			b[i] = vis[i] = 0;
		for (int i = 1;i <= n;i++)
			scanf("%d",&a[i]);
		for (int i = 1;i <= n;i++)
			if (!vis[a[i]])
			{
				vis[a[i]] = 1;
				b[i] = a[i];
			}
		vector<int> A,B;
		for (int i = 1;i <= n;i++)
		{
			if (!vis[i])
				B.push_back(i);
			if (!b[i])
				A.push_back(i);
		}
		if (A.size() == 1)
		{
			b[A[0]] = B[0];
			if (A[0] == B[0])
			{
				for (int i = 1;i <= n;i++)
					if (i != A[0] && a[i] == a[A[0]])
					{
						swap(b[i],b[A[0]]);
						break;
					}
			}
		}
		if (A.size() > 1)
		{
			for (int i = 0;i + 1 < A.size();i++)
				if (A[i] == B[i])
					swap(B[i],B[i + 1]);
			if (B.back() == A.back())
				swap(B[B.size() - 1],B[0]);
			for (int i = 0;i < A.size();i++)
				b[A[i]] = B[i];
		}
		printf("%d\n",n - (int)A.size());
		for (int i = 1;i <= n;i++)
			printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}