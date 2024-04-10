#include <bits/stdc++.h>

#define MN 2002
#define V first
#define A second.first
#define B second.second

using namespace std;
typedef pair<double, pair<int, int> > state;

int n, a, b;
double p[2020], u[2020];
state dp[MN];

state maxi(state a, state b) {
    return (a.V < b.V) ? b : a;
}

state solve(int pos, double CA, double CB) {
    if(pos > n) return {0, {0, 0}};
    state &st = dp[pos];
    if(st.V != -1) return st;

    st = solve(pos + 1, CA, CB);
    {
        state tmp = solve(pos + 1, CA, CB);
        tmp.V += (p[pos] - CA);
        tmp.A++;
        st = maxi(st, tmp);
    } {
        state tmp = solve(pos + 1, CA, CB);
        tmp.V += (u[pos] - CB);
        tmp.B++;
        st = maxi(st, tmp);
    } {
        state tmp = solve(pos + 1, CA, CB);
        tmp.V += ((p[pos] + u[pos] - p[pos]*u[pos]) - CB - CA);
        tmp.A++;
        tmp.B++;
        st = maxi(st, tmp);
    }
    return st;
}

void clean() {
    for(int i = 0; i < MN; i++)
        dp[i] = {-1, {0, 0}};
}

bool oktime() {
    return (clock() * 1.0 / CLOCKS_PER_SEC <= 4.8);
}

int main() {
    scanf("%d %d %d", &n, &a, &b);

    for(int i = 1; i <= n; i++) {
        scanf("%lf", &p[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lf", &u[i]);
    }

    state ans;
    double lb = -1, rb = 1, mb, la, ra, ma;
    for(int it = 40; it > 0 && oktime(); it--) {
        mb = (lb + rb) / 2;

        la = -1, ra = 1, ma;
        for(int it1 = 40; it1 > 0; it1--) {
            clean();
            ma = (la + ra) / 2;
            ans = solve(1, ma, mb);
            if(ans.A > a) la = ma;
            else {
                ra = ma;
                if(ans.A == a) break;
            }
        }
        ans = solve(1, ra, mb);

        if(ans.B > b) lb = mb;
        else {
            rb = mb;
            if(ans.B == b) break;
        }
    }
    ans = solve(1, ra, rb);

    printf("%.9f\n", ans.V + rb*b + ra*a);
    return 0;
}