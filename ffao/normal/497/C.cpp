#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

#define mp make_pair

using namespace std;

int num_parts, num_actors;
pair< pair<int, int>, int > parts[110000];

struct actor {
    int st;
    int ed;
    int idx;
    int av;

    bool operator< (const actor& ot) const {
        return st < ot.st;
    }
};

actor actors[110000];
set< pair<int, pair<int, int> > > actor_queue;

int main() {
    scanf("%d", &num_parts);

    for (int i = 0; i < num_parts; i++) {
        scanf("%d %d", &parts[i].first.first, &parts[i].first.second);
        parts[i].second = i;
    }
    sort(parts, parts+num_parts);

    scanf("%d", &num_actors);
    for (int i = 0; i < num_actors; i++) {
        actors[i].idx = i+1;
        scanf("%d %d %d", &actors[i].st, &actors[i].ed, &actors[i].av);
    }
    sort(actors, actors+num_actors);

    vector< pair<int, int> > ans;

    int curr_actor = 0;
    for (int i = 0; i < num_parts; i++) {
        int this_st = parts[i].first.first;

        while (curr_actor < num_actors && actors[curr_actor].st <= this_st) {
            actor_queue.insert( mp(actors[curr_actor].ed, mp(actors[curr_actor].idx, actors[curr_actor].av)) );
            curr_actor++;
        }

        set< pair<int, pair<int, int> > > :: iterator best = actor_queue.lower_bound(mp(parts[i].first.second, mp(0,0)));;
        
        if (best != actor_queue.end()) {
            ans.push_back( mp(parts[i].second, best->second.first) );
            pair<int, pair<int, int> > val = *best;
            actor_queue.erase(best);
            val.second.second--;
            if (val.second.second > 0) {
                actor_queue.insert(val);
            }
        }
    }

    sort(ans.begin(), ans.end());
    if (ans.size() != num_parts) printf("NO\n");
    else {
        printf("YES\n");
        for (int i = 0; i < num_parts; i++) {
            printf("%d ", ans[i].second);
        }
    }
}