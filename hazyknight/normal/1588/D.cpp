#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 105;

int T,n,N;
int m[15];
int a[15][MAXN];
int b[MAXN];
int pos[15][MAXN][2];
int f[MAXN][1 << 9];

char s[MAXN];

pair<int,int> pre[MAXN][1 << 9];
pair<int,pair<int,int> > ans,MAX[1 << 9];

void FWT(pair<int,pair<int,int> > *v,int N)
{
	for (int i = 1;i < N;i <<= 1)
		for (int j = 0;j < N;j += i << 1)
			for (int k = 0;k < i;k++)
				v[j + k + i] = max(v[j + k + i],v[j + k]);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		for (int i = 0;i < n;i++)
		{
			scanf("%s",s + 1);
			m[i] = strlen(s + 1);
			for (int j = 1;j <= m[i];j++)
				a[i][j] = (s[j] < 'a' ? s[j] - 'A' + 1 : 27 + s[j] - 'a');
			for (int j = 1;j <= 52;j++)
				pos[i][j][0] = pos[i][j][1] = 0;
			for (int j = 1;j <= m[i];j++)
				if (pos[i][a[i][j]][0])
					pos[i][a[i][j]][1] = j;
				else
					pos[i][a[i][j]][0] = j;
		}
		N = m[n - 1];
		for (int i = 1;i <= N;i++)
			b[i] = a[n - 1][i];
		n--;
		/*
		for (int i = 0;i < n;i++)
		{
			for (int j = 1;j <= m[i];j++)
				cerr << a[i][j] << ' ';
			cerr << endl;
		}
		for (int j = 1;j <= N;j++)
			cerr << b[j] << ' ';
		cerr << endl;
		*/
		memset(f,0,sizeof(f));
		memset(pre,0,sizeof(pre));
		ans = make_pair(0,make_pair(0,0));
		for (int i = 1;i <= N;i++)
		{
			bool pass = 0;
			for (int j = 0;j < n;j++)
				if (!pos[j][b[i]][0])
					pass = 1;
			if (pass)
				continue;
			for (int j = 0;j < (1 << n);j++)
				MAX[j] = make_pair(0,make_pair(0,0));
			for (int j = 1;j < i;j++)
			{
				int c = b[j];
				for (int k = 0;k < (1 << n);k++)
				{
					bool ok = 1;
					for (int l = 0;l < n;l++)
						if (!pos[l][c][k >> l & 1])
							ok = 0;
					if (ok)
					{
						int mask = 0;
						for (int l = 0;l < n;l++)
						{
							if (pos[l][b[i]][1] && pos[l][c][k >> l & 1] >= pos[l][b[i]][1])
								ok = 0;
							mask |= (pos[l][c][k >> l & 1] >= pos[l][b[i]][0]) << l;
						}
						if (ok)
						{
						//	cerr << "f[" << j << "][" << k << "]->" << f[j][k] << ' ' << mask << endl;
							MAX[mask] = max(MAX[mask],make_pair(f[j][k],make_pair(j,k)));
						}
					}
				}
			}
			FWT(MAX,1 << n);
			for (int j = 0;j < (1 << n);j++)
			{
				bool ok = 1;
				for (int k = 0;k < n;k++)
					if (!pos[k][b[i]][j >> k & 1])
						ok = 0;
				if (!ok)
					continue;
				f[i][j] = MAX[j].first + 1;
				/*
				cerr << "f[" << i << "][";
				for (int k = 0;k < n;k++)
					cerr << (j >> k & 1);
				cerr << "]=" << MAX[j].first + 1 << endl;
				*/
				pre[i][j] = MAX[j].second;
				ans = max(ans,make_pair(f[i][j],make_pair(i,j)));
			}
		}
		printf("%d\n",ans.first);
		pair<int,int> lst = ans.second;
	//	cerr << lst.first << ',' << lst.second << endl;
		string ANS;
		while (lst.first)
		{
			ANS += (b[lst.first] <= 26 ? b[lst.first] - 1 + 'A' : b[lst.first] - 27 + 'a');
			lst = pre[lst.first][lst.second];
		}
		reverse(ANS.begin(),ANS.end());
		for (int i = 0;i < ANS.size();i++)
			putchar(ANS[i]);
		putchar('\n');
	}
	return 0;
}