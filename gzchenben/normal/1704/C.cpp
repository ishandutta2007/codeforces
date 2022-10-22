#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int t, n, m;
vector<int> A, Seg;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        A.clear();
        Seg.clear();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            A.push_back(tmp);
        }
        sort(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++)
        {
            if (i == 0)
                Seg.push_back(A[0] + n - A[A.size() - 1] - 1);
            else
                Seg.push_back(A[i] - A[i - 1] - 1);
        }
        sort(Seg.begin(), Seg.end());
        reverse(Seg.begin(), Seg.end());
        int ans = 0;
        for (int i = 0; i < Seg.size(); i++)
        {
            // printf("seg = %d\n", Seg[i]);
            if (Seg[i] - (4 * i + 1) == 0)
            {
                ans++;
                break;
            }
            ans += max(0, Seg[i] - (4 * i + 1));
        }
        printf("%d\n", n - ans);
    }
}