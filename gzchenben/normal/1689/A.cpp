#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k, t;
vector<char> A, B;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        A.clear();
        B.clear();
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
        {
            char x;
            scanf(" %c", &x);
            A.push_back(x);
        }
        for (int i = 1; i <= m; i++)
        {
            char x;
            scanf(" %c", &x);
            B.push_back(x);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        int NowA = 0, NowB = 0;
        while (!A.empty() && !B.empty())
        {
            if ((A.back() < B.back() || NowB == k) && NowA != k)
            {
                printf("%c", A.back());
                A.pop_back();
                NowA++;
                NowB = 0;
            }
            else
            {
                printf("%c", B.back());
                B.pop_back();
                NowB++;
                NowA = 0;
            }
        }
        printf("\n");
    }
}