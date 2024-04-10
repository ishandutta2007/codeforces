#include <cstdio>
#ifndef FENWICK_TREE
#define FENWICK_TREE

#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

template <typename Tp>
class Fenwick_tree
{
public:
    int Siz;
    vector<Tp> Data;
    Tp Init;
    Tp (*F)(Tp x, Tp y);
    int lowbit(int x)
    {
        return x & (-x);
    }

    Fenwick_tree(int N, Tp tmp)
    {
        Siz = N;
        Init = tmp;
        Data.resize(N + 1, Init);
        F = [](Tp x, Tp y) -> Tp
        {
            return x + y;
        };
    }
    Fenwick_tree(int N)
    {
        memset(&Init, 0, sizeof(Tp));
        Siz = N;
        Data.resize(N + 1, Init);
        F = [](Tp x, Tp y) -> Tp
        {
            return x + y;
        };
    }
    Fenwick_tree(int N, Tp tmp, Tp (*Oper)(Tp x, Tp y))
    {
        Siz = N;
        Init = tmp;
        Data.resize(N + 1, Init);
        F = Oper;
    }
    Fenwick_tree(int N, Tp (*Oper)(Tp x, Tp y))
    {
        memset(&Init, 0, sizeof(Tp));
        Siz = N;
        Data.resize(N + 1, Init);
        F = Oper;
    }

    void resize(int N)
    {
        Siz = N;
        Data.clear();
        Data.resize(N + 1, Init);
    }
    void clear()
    {
        Data.clear();
        Data.resize(Siz + 1, Init);
    }
    void update(int pos, Tp val)
    {
        int Now = pos;
        while (Now <= Siz)
        {
            Data[Now] = F(Data[Now], val);
            Now += lowbit(Now);
        }
    }
    Tp query(int pos)
    {
        int Now = pos;
        Tp answer = Init;
        while (Now > 0)
        {
            answer = F(answer, Data[Now]);
            Now -= lowbit(Now);
        }
        return answer;
    }
};

#endif

// #include <cstdio>

// struct Node
// {
//     long long x;
//     const Node operator+(const Node &tmp) const
//     {
//         return (Node){x + tmp.x};
//     }
// };
// int N, Q;
// int main()
// {
//     scanf("%d%d", &N, &Q);
//     // Fenwick_tree<Node> tr(N);
//     // Fenwick_tree<Node> tr(N, (Node){0});
//     Fenwick_tree<Node> tr(N, (Node){0}, [](Node x, Node y) -> Node
//                           { return (Node){x.x + y.x}; });
//     for (int i = 1; i <= N; i++)
//     {
//         long long tmp;
//         scanf("%lld", &tmp);
//         tr.update(i, (Node){tmp});
//     }
//     for (int i = 1; i <= Q; i++)
//     {
//         int opt, x, y;
//         scanf("%d%d%d", &opt, &x, &y);
//         if (opt == 1)
//             tr.update(x, (Node){y});
//         if (opt == 2)
//             printf("%lld\n", tr.query(y).x - tr.query(x - 1).x);
//     }
//     return 0;
// }
#include <algorithm>
using namespace std;
int n, t;
long long a[500005], sum[500005], ord[500005], rev[500005], dp[500005];

bool cmp(int x, int y)
{
    if (sum[x] == sum[y])
        return x > y;
    return sum[x] < sum[y];
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        Fenwick_tree<long long> Tr(n + 1, -1e15, [](long long x, long long y) -> long long
                                   { return max(x, y); });
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
            ord[i] = i;
        }
        ord[n + 1] = 0;
        sort(ord + 1, ord + n + 2, cmp);
        for (int i = 1; i <= n + 1; i++)
        {
            rev[ord[i]] = i;
        }
        Tr.update(rev[0], 0);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 1] - 1;
            dp[i] = max(dp[i], Tr.query(rev[i] - 1) + i);
            Tr.update(rev[i], dp[i] - i);
        }
        printf("%lld\n", dp[n]);
    }
}