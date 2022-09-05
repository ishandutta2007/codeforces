#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i <= (b); ++i)
#define REP(i,n) FOR(i,0,(n)-1)
const int nax = 1005;
typedef double T;

struct P {
    T x, y;
    void read() {
        scanf("%lf%lf", &x, &y);
    }
    void write() {
        printf("%.10lf %.10lf\n", x, y);
    }
    P operator - (P other) {
        return P{x - other.x, y - other.y};
    }
    T operator * (P other) {
        return x * other.y - y * other.x;
    }
    T norm() {
        return sqrt(x * x + y * y);
    }
};
P mean(P a, P b) {
    return P{(a.x + b.x) / 2, (a.y + b.y) / 2};
}

int n;
P t[nax];
P vec[nax]; // vec[i] = t[i+1] - t[i] (it's a vector)

T distLine(int i, P A) {
    return abs((vec[i] * (A - t[i])) / vec[i].norm());
}

P best_point[nax][nax];
T best_r[nax][nax];
vector<pair<int,int>> candidates; // there will be O(n) of them

int main() {
    scanf("%d", &n);
    REP(i, n) t[i].read();
    REP(i, 2 * n) t[n+i] = t[i];
    REP(i, 3 * n) vec[i] = t[i+1] - t[i];
    int whereMid = 0;
    int end = 0;
    REP(start, n) {
        whereMid = max(start, whereMid);
        end = max(start, end);
        while(vec[end+1] * vec[start+n-1] < 0.5) ++end;
        for(; start == end || vec[start] * vec[end] > 0.5; ++end) {
            assert(end < start + n);
            while(whereMid < end && distLine(start, t[whereMid+1]) < distLine(end, t[whereMid+1]))
                ++whereMid;
            // binary search an optimal point
            P low = t[whereMid], high = t[whereMid+1];
            REP(_, 42) {
                P mid = mean(low, high);
                if(distLine(start, mid) < distLine(end, mid))
                    low = mid;
                else
                    high = mid;
            }
            P mid = mean(low, high);
            best_point[start][end%n] = mid;
            best_r[start][end%n] = max(distLine(start,mid), distLine(end,mid));
            candidates.push_back(make_pair(start, end % n));
        }
        --end;
    }
    T r = 1e7; // infinity
    P a, b;
    for(pair<int,int> candidate : candidates) {
        int start = candidate.first;
        int end = candidate.second;
        int start2 = (end + 1) % n;
        int end2 = (start + n - 1) % n;
        T maybe = max(best_r[start][end], best_r[start2][end2]);
        if(maybe < r) {
            r = maybe;
            a = best_point[start][end];
            b = best_point[start2][end2];
        }
    }
    printf("%.10lf\n", r);
    a.write();
    b.write();
    return 0;
}