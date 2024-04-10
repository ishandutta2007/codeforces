    #include <bits/stdc++.h>
     
    using namespace std;
    const int maxn = 1005;
    struct TPoint{
        int x, y;
    };
    struct TLine{
        TPoint A, B;
    } L[maxn];
    bool del[maxn];
    long long d[maxn];
    int n, a, b;
    long long SQRDist(const TPoint &A, const TPoint &B) {
        return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
    }
    long long PointToLine(const TPoint &P, const TLine &L) {
        if (L.A.x <= P.x && P.x <= L.B.x) return abs(P.y - L.A.y)*abs(P.y - L.A.y);
        if (L.A.y <= P.y && P.y <= L.B.y) return abs(P.x - L.A.x)*abs(P.x - L.A.x);
        return min(SQRDist(P, L.A), SQRDist(P, L.B));
    }
    long long SQRCost(const TLine &L1, const TLine &L2) {
        return min({PointToLine(L1.A, L2), PointToLine(L1.B, L2), 
            PointToLine(L2.A, L1), PointToLine(L2.B, L1)});
    }
    int main() {
    #ifdef LDT
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cin >> a >> b;
        for (int i = 1; i <= 2; ++i) {
            cin >> L[i].A.x >> L[i].A.y;
            L[i].B = L[i].A;
        }
        cin >> n;
        n += 2;
        for (int i = 3; i <= n; ++i) {
            cin >> L[i].A.x >> L[i].A.y >> L[i].B.x >> L[i].B.y;
            if (L[i].A.x > L[i].B.x)  
                swap(L[i].A.x, L[i].B.x);
            if (L[i].A.y > L[i].B.y)
                swap(L[i].A.y, L[i].B.y);
        }
        memset(d, 127, sizeof(d));
        d[1] = 0;
        del[2] = 1;
        long double res = 1e18;
        while (true) {
            int best = -1;
            for (int i = 1; i <= n; ++i) if (!del[i]) {
                if (best == -1 || d[best] > d[i]) best = i;
            }
            if (best == -1) break;
            del[best] = 1;
            int u = best;
            for (int v = 1; v <= n; ++v) {
                long long cost = SQRCost(L[u], L[v]);
                if (cost <= a * a && d[v] > d[u] + a + b) {
                    d[v] = d[u] + a + b;
                }
                if (v == 2 && cost <= a * a) {
                    res = min(res, (long double) d[u] + sqrt(cost));
                }
            }
        }
        if (res > 1e17) return !(cout << -1);
        cout.precision(9);
        cout << fixed << res;
        return 0;
    }