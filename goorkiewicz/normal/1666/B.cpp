#include <bits/stdc++.h>

using namespace std;

typedef double T;

const T eps = 1e-5;
const int N = 300'007;

int n, q;
int sp[N];
vector <int> c[N], p[N];

T sum_all_c = 0;
T len_unactive = 0;
T result_unactive = 0;
T sum_sub_vals = 0;
T sum_sqrt_c = 0;

T len[N];
T sub_val[N];
T start_val[N];
T result_val[N];

T ans[N];
vector <pair <T, int> > queries;
vector <tuple <T, int, int> > events;

int main()
{
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) {
        int k;
        scanf("%d", &k);

        c[i].resize(k);
        p[i].resize(k);

        for (auto &cc: c[i]) {
            scanf("%d", &cc);
            len[i] += cc;
        }

        for (auto &pp: p[i]) {
            scanf("%d", &pp);
            sp[i] += pp;
        }

        vector <int> order;
        order.reserve(k);

        for (int j = 0; j < k; ++j) {
            if (c[i][j] * sp[i] <= len[i] * p[i][j]) {
                continue;
            }

            order.push_back(j);
            sub_val[i] += (T)p[i][j] / sp[i];
            start_val[i] += c[i][j];
            result_val[i] += (T)c[i][j] / len[i] - (T)p[i][j] / sp[i];
        }

        sum_all_c += len[i];
        len_unactive += len[i];
        result_unactive += result_val[i];

        sort(order.begin(), order.end(), [&](int a, int b) {
            return c[i][a] * p[i][b] < c[i][b] * p[i][a];
        });

        T tmp_val = start_val[i];
        events.push_back({tmp_val / len[i] / len[i], i, 1});

        for (int j: order) {
            T cur_x = (T)c[i][j] * sp[i] / p[i][j];
            T cur_der = tmp_val / cur_x / cur_x;
            events.push_back({cur_der, i, -j});
            
            tmp_val -= c[i][j];
            if (tmp_val > 0.5) {
                cur_der = tmp_val / cur_x / cur_x;
                events.push_back({cur_der, i, 1});
            }
        }

//        printf("%d -> %.10lf %.10lf %.10lf\n", i, start_val[i], len[i], sub_val[i]);
    }

    for (int i = 1; i <= q; ++i) {
        T v;
        scanf("%lf", &v);
        queries.push_back({v, i});
    }

    sort(queries.begin(), queries.end());
    reverse(queries.begin(), queries.end());

    sort(events.begin(), events.end());
    reverse(events.begin(), events.end());

    for (auto [d, id, t]: events) {
//        printf("event %.10lf %d %d\n", d, id, t);
        T cur_len = len_unactive + sqrt(1 / d) * sum_sqrt_c;

        while (!queries.empty()) {
            auto [y, id2] = queries.back();
            if (y + sum_all_c > cur_len) {
                break;
            }

//            printf("answers %d :: %lf\n", id2, result_unactive);
            queries.pop_back();
            
            ans[id2] = result_unactive;
            y -= len_unactive;
            y += sum_all_c;

            if (y > eps) {
                T der_sqrt = sum_sqrt_c / y;
                ans[id2] += der_sqrt * sum_sqrt_c;
                ans[id2] -= sum_sub_vals;
            }
        }

        if (t == 1) {
            len_unactive -= len[id];
            result_unactive -= result_val[id];
            sum_sub_vals += sub_val[id];
            sum_sqrt_c += sqrt(start_val[id]);
        } else {
            t *= -1;
            
            sum_sub_vals -= sub_val[id];
            sum_sqrt_c -= sqrt(start_val[id]);

            len[id] = (T)c[id][t] * sp[id] / p[id][t];
            len_unactive += len[id];

            result_val[id] = sqrt(d) * sqrt(start_val[id]) - sub_val[id];
            result_unactive += result_val[id];

            sub_val[id] -= (T)p[id][t] / sp[id];
            start_val[id] -= c[id][t];
        }
    }

    for (auto [_, id]: queries) {
        ans[id] = 0;
    }

    for (int i = 1; i <= q; ++i) {
        printf("%.10lf\n", 2 * ans[i]);
    }

    return 0;
}