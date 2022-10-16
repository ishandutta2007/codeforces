#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int k, m, n;
double a[110000];

struct op {
    int factor;
    int id;
    int target;
    int type;

    bool operator< (op ot) {
        return factor < ot.factor;
    }
};

vector<int> used[110000];
op ops[110000];
vector<op> ass_per_skill[110000];
vector<op> adds_per_skill[110000];
vector<op> mults_per_skill[110000];
double multyvec[110000];
set< pair<double, int> > free_ops;

void refresh(int i) {

    if (!adds_per_skill[i].empty()) {
        int pp = adds_per_skill[i].size() - 1;
        double& multy = multyvec[adds_per_skill[i][pp].id];
        free_ops.erase( make_pair(multy, adds_per_skill[i][pp].id) );

        if (a[i] == 0) multy = 10000001;
        else multy = (a[i]+adds_per_skill[i][pp].factor) / (double)a[i];

        free_ops.insert( make_pair(multy, adds_per_skill[i][pp].id) );
    }
    if (!mults_per_skill[i].empty()) {
        int pp = mults_per_skill[i].size() - 1;
        double& multy = multyvec[mults_per_skill[i][pp].id];
        free_ops.erase( make_pair(multy, mults_per_skill[i][pp].id) );

        if (a[i] == 0) multy = 0;
        else multy = mults_per_skill[i][pp].factor;

        free_ops.insert( make_pair(multy, mults_per_skill[i][pp].id) );
    }
}

int main() {
    scanf("%d %d %d", &k, &n, &m);

    for (int i = 0; i < k; i++) {
        scanf("%lf", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int t, skill, value;
        scanf("%d %d %d", &t, &skill, &value ); skill--;
        
        ops[i].id = i;
        ops[i].factor = value;
        ops[i].target = skill;
        ops[i].type = t;

        if (t == 1) {
            ops[i].factor -= a[skill];
            if (ops[i].factor > 0) {
                ass_per_skill[skill].push_back(ops[i]);
            }
        }
        else if (t == 2) {
            adds_per_skill[skill].push_back(ops[i]);
        }
        else {
            mults_per_skill[skill].push_back(ops[i]);
        }
    }

    for (int i = 0; i < k; i++) {
        sort(ass_per_skill[i].begin(), ass_per_skill[i].end());
        if (!ass_per_skill[i].empty()) {
            adds_per_skill[i].push_back(*ass_per_skill[i].rbegin());
        }
    }

    for (int i = 0; i < k; i++) {
        sort(adds_per_skill[i].begin(), adds_per_skill[i].end());
        sort(mults_per_skill[i].begin(), mults_per_skill[i].end());
        refresh(i);
    }

    int total_used = 0;
    for (int i = 0; i < m; i++) {
        //printf("size %d\n", free_ops.size());
        if (free_ops.empty()) break;
        auto best = *free_ops.rbegin();
        free_ops.erase(best);

        //printf("chose %d because factor of %f\n", best.second, best.first);

        int this_op = best.second;
        used[ops[this_op].target].push_back(this_op);
        
        if (ops[this_op].type == 3) {
            mults_per_skill[ops[this_op].target].pop_back();
        }
        else {
            a[ops[this_op].target] += ops[this_op].factor;
            adds_per_skill[ops[this_op].target].pop_back();
        }

        refresh(ops[this_op].target);
        total_used++;
    }

    printf("%d\n", total_used);
    for (int i = 0; i < k; i++) {
        for (auto idx : used[i]) {
            if (ops[idx].type == 1) printf("%d ", idx+1);
        }
        for (auto idx : used[i]) {
            if (ops[idx].type == 2) printf("%d ", idx+1);
        }
        for (auto idx : used[i]) {
            if (ops[idx].type == 3) printf("%d ", idx+1);
        }
    }
}