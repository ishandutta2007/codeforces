#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define mp make_pair

using namespace std;

int interval_at[110000];
int starts_at[110000];
deque<double> probabilities[110000];
pair< pair<int, int>, double > intervals[110000];
int n, q;

void process_interval(int i) {
    if (intervals[i].second < 0) return;

    int st = intervals[i].first.second;
    int ed = st + intervals[i].first.first - 1;
    double pr = intervals[i].second;

    starts_at[i] = 0;
    probabilities[i].push_back(1);

    int curr_pos = st;
    while (curr_pos <= ed) {
        int other_interval = interval_at[curr_pos];
        
        double prob_meu = 0;
        double prob_dele = 0;

        while (!probabilities[i].empty() && starts_at[i] < starts_at[other_interval]) {
            prob_meu += probabilities[i][0];
            starts_at[i]++;
            probabilities[i].pop_front();
        }

        while (!probabilities[other_interval].empty() && starts_at[other_interval] < starts_at[i]) {
            prob_dele += probabilities[other_interval][0];
            starts_at[other_interval]++;
            probabilities[other_interval].pop_front();
        }

        int final_size = max(probabilities[other_interval].size(), probabilities[i].size());
        starts_at[i] = max(starts_at[i], starts_at[other_interval]);        
        probabilities[i].resize(final_size);

        if (probabilities[other_interval].size() == 1) {
            probabilities[i][0] += prob_meu;
        }

        else if (!probabilities[other_interval].empty()) {
            for (int idx = 0; idx < final_size; idx++) {
                double prob_atual_eu = ( (idx >= probabilities[i].size()) ? 0 : probabilities[i][idx] ); 
                double prob_atual_ele = ( (idx >= probabilities[other_interval].size()) ? 0 : probabilities[other_interval][idx] ); 
                
                probabilities[i][idx] = (prob_atual_eu * prob_dele + prob_atual_ele * prob_meu + prob_atual_eu * prob_atual_ele);
                //printf("%f %f %f %f = %f\n", prob_atual_eu, prob_atual_ele, prob_meu, prob_dele, probabilities[i][idx]);

                prob_meu += prob_atual_eu;
                prob_dele += prob_atual_ele;
            }
        }

        interval_at[curr_pos] = i;
        curr_pos += intervals[other_interval].first.first;
    }

    

    probabilities[i].push_back(0);
    double old_prev = 0;

    for (int idx = 0; idx < probabilities[i].size(); idx++) {
        double tmp = probabilities[i][idx];
        //printf("probabilities[%d][%d] = %f\n", i, idx, (1-pr)*probabilities[i][idx] + pr*old_prev);
        probabilities[i][idx] = (1-pr)*probabilities[i][idx] + pr*old_prev;
        old_prev = tmp;
    }
}

int main() {
    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        interval_at[i] = i;
        scanf("%d", &starts_at[i]);
        probabilities[i].push_back(1);
        intervals[i] = mp( mp(1, i), -1);
    }

    for (int i = 0; i < q; i++) {
        int st, ed;
        double prob;
        scanf("%d %d %lf", &st, &ed, &prob);
        intervals[n+i] = mp( mp(ed-st+1, st - 1), prob );
    }

    intervals[n+q] = mp( mp(n, 0), 1 );

    sort(intervals + n, intervals + n + q);

    for (int i = 0; i <= n+q; i++) {
        //printf("processing interval %d (%d %d %f)\n", i, intervals[i].first.first, intervals[i].first.second, intervals[i].second);
        process_interval(i);

        /*printf("interval %d ended with: start %d, probs ", i, starts_at[i]);
        for (int j = 0; j < probabilities[i].size(); j++) printf("%f ", probabilities[i][j]);
        printf("\n");*/
    }

    double ans = starts_at[n+q];
    for (int i = 0; i < probabilities[n+q].size(); i++) {
        ans += probabilities[n+q][i] * i; 
    }
    printf("%.15f\n", ans-1);
}