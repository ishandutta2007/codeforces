#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define mp make_pair

using namespace std;

int n,m,k,p;

struct bamboo {
    int h, a, id;
} b[100005];

int hit_by[100005];
long long day_removal[100005];
long long total_removal[100005];
pair<int, long long> safe_limit[100005];

struct compara {
    bool operator() (int a, int b) {
        return hit_by[a] < hit_by[b];
    }
};

long long simulate(int i, int mid, int last_day) {
    long long bh = b[i].h;
    long long ba = b[i].a;
    long long delta = ba - p * 1ll * k;

    if (mid == 0) return bh + ba * last_day;
    
    bh = max(0LL, bh - p * 1ll * k);
    return max(0LL, bh + delta * max(0, mid-1)) + ba * (last_day - mid + 1);
}

int calc(int i, long long max_height) {
    int last_day = safe_limit[i].first;
    long long target = safe_limit[i].second;

    if (simulate(i, last_day, last_day) > target) return last_day;

    int st = 0, ed = last_day;
    while (st < ed) {
        int mid = (st+ed)/2;
        if (simulate(i, mid, last_day) <= target) ed = mid;
        else st = mid+1; 
    }

    return st-1;
}

bool get_new_limit(int hit_bamboo, int curr_day) {
    int last_day = safe_limit[hit_bamboo].first;
    long long target = safe_limit[hit_bamboo].second;

    target -= (last_day - curr_day) * 1ll * b[hit_bamboo].a;
    if (target < 0) return false;
    
    safe_limit[hit_bamboo] = make_pair(curr_day, target + p);
    return true;
}

bool check(long long max_height) {
    
    priority_queue<int, vector<int>, compara> q;

    for (int i = 0; i < n; i++) {
        safe_limit[i] = make_pair(m, max_height);
        hit_by[i] = calc(i, max_height);
        q.push(i);
    }

    for (int i = m-1; i >= 0; i--) {

        for (int j = 0; j < k; j++) {
            int will_hit = q.top();
            q.pop();

            if (!get_new_limit(will_hit, i)) return false;      
            hit_by[will_hit] = calc(will_hit, max_height);
            q.push(will_hit); 
        }

    }

    for (int i = 0; i < n; i++) {
        if (calc(i, max_height) != -1) {
            return false;
        }
    }

    return true;
}


int main() {
    scanf("%d %d %d %d", &n, &m, &k, &p);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &b[i].h, &b[i].a);
        b[i].id = i;
    }

    long long st = 0, ed = 5100000000000LL;
    while (st < ed) {
        long long mid = (st+ed)/2;
        if (check(mid)) ed = mid;
        else st = mid+1;
    }

    printf("%I64d\n", st);
}