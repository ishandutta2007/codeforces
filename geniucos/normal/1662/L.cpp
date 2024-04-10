#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int nr, N, v, a[maxN], t[maxN];
long long stk[maxN];
vector<pair<long long, long long>> h;

void append(long long val) {
    if (stk[nr] <= val)
        stk[++nr] = val;
    else {
        int p = 1, u = nr - 1, ras = nr;
        ///stk[i] <= val < stk[i + 1]
        while (p <= u) {
            int mid = (p + u) >> 1;
            if (stk[mid] > val) ras = mid, u = mid - 1;
            else p = mid + 1;
        }
        ///ras is minimum s.t. val<stk[i], so val>=stk[i - 1]
        stk[ras] = val;
    }
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &v);
for (int i=1; i<=N; i++)
    scanf ("%d", &t[i]);
for (int i=1; i<=N; i++) {
    scanf ("%d", &a[i]);
    pair<long long, long long> curr = make_pair(a[i] - 1LL * v * t[i], -(a[i] + 1LL * v * t[i]));
    if (curr.first <= 0LL && curr.second <= 0LL)
        h.push_back(curr);
}
sort(h.begin(), h.end());
for (auto &it : h)
    it.second = -it.second;
/*for (auto it : h)
    printf("%I64d %I64d\n", it.first, it.second);*/
reverse(h.begin(), h.end());
for (auto it : h)
    append(it.second);
printf("%d\n", nr);
return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/