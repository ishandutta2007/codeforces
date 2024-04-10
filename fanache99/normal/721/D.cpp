#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 200000;
const long long INFLL = 1000000000000000000LL;

long long v[1 + MAXN];

long long Abs(long long x) {
    if (x < 0)
        return -x;
    return x;
}

class Compare {
    public:
        bool operator() (const int &x, const int &y) {
            return Abs(v[x]) > Abs(v[y]);
        }
};

priority_queue<int, vector<int>, Compare> Heap;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, k, sign = 1, zeros = 0;
    long long x;
    scanf("%d%d%I64d", &n, &k, &x);
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", &v[i]);
        if (v[i] < 0)
            sign = -sign;
        if (v[i] == 0)
            zeros++;
    }
    if (zeros) {
        if (zeros > k) {
            for (int i = 1; i <= k; i++)
                v[i] += x;
            for (int i = 1; i <= n; i++)
                printf("%I64d ", v[i]);
            return 0;
        }
        k -= zeros;
        bool first = true;
        for (int i = 1; i <= n; i++)
            if (v[i] == 0)
                if (!first)
                    v[i] += x;
                else {
                    first = false;
                    if (sign == 1)
                        v[i] -= x;
                    else
                        v[i] += x;
                }
    }
    else
        if (sign == 1) {
            long long smallest = INFLL;
            int where;
            for (int i = 1; i <= n; i++)
                if (Abs(v[i]) < smallest) {
                    smallest = Abs(v[i]);
                    where = i;
                }
            long long need = smallest / x + 1;
            if (need >= k) {
                if (v[where] > 0)
                    v[where] = v[where] - x * k;
                else
                    v[where] = v[where] + x * k;
                for (int i = 1; i <= n; i++)
                    printf("%I64d ", v[i]);
                return 0;
            }
            k -= need;
            if (v[where] > 0)
                v[where] = v[where] - x * need;
            else
                v[where] = v[where] + x * need;
        }
    for (int i = 1; i <= n; i++)
        Heap.push(i);
    for (int i = 1; i <= k; i++) {
        int where = Heap.top();
        Heap.pop();
        if (v[where] < 0)
            v[where] -= x;
        else
            v[where] += x;
        Heap.push(where);
    }
    for (int i = 1; i <= n; i++)
        printf("%I64d ", v[i]);
    return 0;
}