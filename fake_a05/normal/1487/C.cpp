#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define eb emplace_back
#define all(x) begin(x), end(x)
#define fi first
#define se second

#define rand rng
#define endl '\n'
#define sp ' '


#define int long long

const int maxN = 5e5 + 5;

int m[105][105];
int p[105];
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	while(tc--)
	{
		int N;
		cin >> N;
		loop(i, 0, N - 1)
		{
			loop(j, 0, N - 1) m[i][j] = 0;
		}
		loop(i, 0, N - 1)
		{
			loop(j, - ((N - 1) / 2), -1)
			{
				int k = (i + j) % N;
				k = (k + N) % N;
				assert(0 <= k and k < N);
				m[i][k] = 1;
				m[k][i] = -1;
			}
			loop(j, 1, (N - 1) / 2)
			{
				int k = (i + j) % N;
				assert(0 <= k and k < N);
				m[i][k] = -1;
				m[k][i] = 1;
			}
		}
		int sum = 0, dr = 0;
		loop(i, 0, N - 1) p[i] = 0;
		loop(i, 0, N - 1)
		{
			loop(j, i + 1, N - 1)
			{
				if(m[i][j] == 1) p[i] += 3, sum += 3;
				else if(!m[i][j]) p[i]++, p[j]++, sum += 2, dr++;
				else p[j] += 3, sum += 3;
			}
		}
		loop(i, 0, N - 1)
		{
			assert(p[i] * N == sum);
		}
		assert(dr <= N / 2);
		loop(i, 0, N - 1)
		{
			loop(j, i + 1, N - 1)
			{
				cout << m[i][j] << sp;
			}
		}
		cout << endl;
	}
}