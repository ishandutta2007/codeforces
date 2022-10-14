#include <bits/stdc++.h>
using namespace std;
const int oo = 27081993;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

struct MinCostMatching
{
    int m, n;
    vector <int> leftDelta, rightDelta, leftMatch, rightMatch, minRight;
    vector <int> prev, seen;
    vector < vector <int> > a;

    MinCostMatching() {}
    MinCostMatching(int m, int n)
    {
        this -> m = m;
        this -> n = n;
        leftDelta = vector <int>(m + 1, 0);
        rightDelta = vector <int>(n + 1, 0);
        minRight = vector <int>(n + 1, 0);
        leftMatch = vector <int>(n + 1, 0);
        rightMatch = vector <int>(m + 1, 0);
        prev = vector <int>(n + 1, 0);
        seen = vector <int>(n + 1, 0);
        a = vector < vector <int> >(m + 1);
        for (int i = 0; i <= m; i++) a[i] = vector <int>(n + 1, oo - 1);
    }

    void addEdge(int x, int y, int cost)
    {
        a[x][y] = min(a[x][y], cost);
    }

    int minCost()
    {
        for (int i = 1; i <= m; i++)
        {
            leftMatch[0] = i;
            int y = 0;
            for (int j = 0; j <= n; j++) seen[j] = 0, minRight[j] = oo;

            do
            {
                seen[y] = 1;
                int x = leftMatch[y], delta = oo, yy;
                for (int j = 1; j <= n; j++)
                    if (!seen[j])
                    {
                        int cur = a[x][j] - leftDelta[x] - rightDelta[j];
                        if (cur < minRight[j]) minRight[j] = cur, prev[j] = y;
                        if (minRight[j] < delta) delta = minRight[j], yy = j;
                    }

                for (int j = 0; j <= n; j++)
                    if (seen[j]) leftDelta[leftMatch[j]] += delta, rightDelta[j] -= delta;
                    else minRight[j] -= delta;
                y = yy;
            } while (leftMatch[y]);

            do
            {
                int yy = prev[y];
                leftMatch[y] = leftMatch[yy];
                y = yy;
            } while (y);
        }

        return -rightDelta[0];
    }
};

int main()
{
    int m, n, a[88][88];
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    MinCostMatching mcm(n * m / 2, n * m / 2);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if ((i + j) % 2 == 0)
                for (int k = 0; k < 4; k++)
                {
                    int ii = i + dx[k], jj = j + dy[k];
                    if (ii < 0 || ii >= m || jj < 0 || jj >= n) continue;
                    mcm.addEdge((i * n + j) / 2 + 1, (ii * n + jj) / 2 + 1, a[i][j] != a[ii][jj]);
                }

    cout << mcm.minCost() << endl;
}