#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

//READ THE PROBLEM!
//ll or int?

//Template contributed by GitHub user bqi343

const int MAXN = 100000;

int maxH[MAXN], regen[MAXN], startH[MAXN];
bool canKill[MAXN];
int N, M, damage, numKillable; int curU = 0; ll best = 0;
ll bounty, increase;
int lastProcessed = -100;


struct update {
    int id;
    int time;
    int health;
    bool operator <(const update& rhs) const {
        return time > rhs.time;
    }
};

priority_queue<update> keyTimes;
vector<priority_queue<update> > uTimes;


void updateBest(int time) {
    ll cur = (bounty + increase * time) * numKillable;
    //cout << "Can earn " << cur << " at " << time << endl;
    best = max(cur, best);

}


void init() {
    cin >> N >> M >> bounty >> increase >> damage;
    priority_queue<update> pq;
    F0R(i, N) {
        cin >> maxH[i] >> startH[i] >> regen[i];

        uTimes.pb(pq);
    }


    F0R(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        update u = { b - 1, a, c };
        uTimes.at(b-1).push(u);
    }


    numKillable = 0;

    F0R(i, N) {
        if (maxH[i] <= damage) {
            canKill[i] = true;
            numKillable++;
        } else {
            if (startH[i] > damage) {
                canKill[i] = false;
                if (!uTimes.at(i).empty()) {
                    keyTimes.push(uTimes.at(i).top());
                    uTimes.at(i).pop();
                }
            } else {
                canKill[i] = true;
                numKillable++;
                int t = -1;
                if (regen[i] != 0) t = ceil(((double) damage + 1 - (double) startH[i]) / (double) regen[i]);
                int h = -1;

                if (!uTimes.at(i).empty()) {
                    if (uTimes.at(i).top().time < t) {
                        t = uTimes.at(i).top().time;
                        h = uTimes.at(i).top().health;
                        uTimes.at(i).pop();
                    }
                }
                update u = { i, t, h };
                if (t != -1) keyTimes.push(u);

            }
        }
    }

    updateBest(0);
}



void processHealthChange(update u) {
    if (lastProcessed + 1 < u.time) {
        updateBest(u.time - 1);
        lastProcessed = u.time - 1;
    }

    if (canKill[u.id] && u.health > damage) {
        canKill[u.id] = false;
        numKillable--;
    } else if (!canKill[u.id] && u.health <= damage) {
        canKill[u.id] = true;
        numKillable++;
    }

    int t = -1;
    int h = -1;
    if (u.health <= damage && regen[u.id] != 0) {
        t = u.time + ceil(((double) damage + 1 - (double) u.health) / (double) regen[u.id]);
        //cout << "Enemy " << u.id << " will be unkillable at time " << t << endl;
    }

    //cout << "About to check change " << u.id << " at time " << u.time << endl;
    if (!uTimes.at(u.id).empty()) {
        update u2 = uTimes.at(u.id).top();
        if (t == -1 || u2.time < t) {
            uTimes.at(u.id).pop();
            t = u2.time;
            h = u2.health;
        }
    }
    //cout << "Success" << endl;
    update u2 = {u.id, t, h};
    if (t != -1) keyTimes.push(u2);

    if (keyTimes.empty() || keyTimes.top().time > u.time) {
        updateBest(u.time);
        lastProcessed = u.time;
    }
}

void processRegenOutOfRange(update u) {
    if (lastProcessed + 1 < u.time) {
        updateBest(u.time - 1);
        lastProcessed = u.time - 1;
    }

    if (!uTimes.at(u.id).empty()) {
        update u2 = uTimes.at(u.id).top();
        uTimes.at(u.id).pop();
        keyTimes.push(u2);
    }

    //cout << u.id << " becomes unkillable at time " << u.time << endl;

    if (canKill[u.id]) {
        canKill[u.id] = false;
        numKillable--;
    }

    if (keyTimes.empty() || keyTimes.top().time > u.time) {
        updateBest(u.time);
        lastProcessed = u.time;
    }


}


int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);

    init();


    while (!keyTimes.empty()) {
        update u = keyTimes.top();
        keyTimes.pop();
        if (u.health == -1) {
            processRegenOutOfRange(u);
        } else {
            processHealthChange(u);
        }
    }


    //cout << numKillable << " killable in the end." << endl;
    if (numKillable > 0 && increase > 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << best << endl;

	return 0;
}