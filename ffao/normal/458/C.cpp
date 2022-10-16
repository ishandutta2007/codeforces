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

int n, cand, cost;
int ct = 0;

vector<int> costs[110000];
vector<int> S[110000];
int countt[110000];
int sumt[110000];

int get(int tree[110000], int loc) {
    int s = 0;
    while (loc > 0) {
        s += tree[loc];
        loc -= loc&-loc;
    }
    return s;
}

void upd(int tree[110000], int loc, int delta) {
    while (loc <= 100500) {
        tree[loc] += delta;
        loc += loc&-loc;
    }
}

typedef pair< pii, int > piii;
vector< pair< pii, int > > all_votes;

int get_cheap(int qt) {
    if (qt <= 0) return 0;

    int st = 1, end = 100500;
    while (st < end) {
        int mid = (st+end)/2;
        if (get(countt, mid) >= qt) end=mid;
        else st=mid+1;
    } 

    return get(sumt, st);
}

bool costcompare(const piii& a, const piii& b) {
    return costs[a.first.second][a.first.first - 1] < costs[b.first.second][b.first.first - 1];
}

int main() {
    scanf("%d", &n);

    int mc = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &cand, &cost);
        mc = max(mc, cand);

        if (cand == 0) ct++;
        else costs[cand].pb(cost);
    }

    for (int i = 1; i <= mc; i++) {
        sort(costs[i].begin(), costs[i].end(), greater<int>() );
        
        for (int j = 0; j < costs[i].sz; j++) {
            all_votes.push_back( make_pair( make_pair(j+1, i), 0) );
        }
    }

    n = all_votes.size();
    sort(all_votes.begin(), all_votes.end(), costcompare);

    for (int i = 0; i < n; i++) {
        all_votes[i].second = i+1;
        upd(countt, i+1, 1);
        upd(sumt, i+1, costs[all_votes[i].first.second][all_votes[i].first.first - 1]);
    }

    sort(all_votes.begin(), all_votes.end());

    int cur = n-1;
    int spent = 0;
    int best = 1100000000;

    for (int my_votes = ct+n; my_votes >= 0; my_votes--) {
        while (cur >= 0 && all_votes[cur].first.first == my_votes ) {
            spent += costs[all_votes[cur].first.second][all_votes[cur].first.first - 1];
            upd(countt, all_votes[cur].second, -1);
            upd(sumt, all_votes[cur].second, -costs[all_votes[cur].first.second][all_votes[cur].first.first - 1]);
            
            ct++;
            cur--;
        }
    
        best = min(best, spent + get_cheap(my_votes - ct));
    }

    printf("%d\n", best);
}