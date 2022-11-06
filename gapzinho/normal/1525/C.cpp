#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int ms = 3e5+5;
const int inf = 0x3f3f3f3f;


int nxt[2][ms], prv[2][ms];
int pos[ms];
int curTime[ms];
int dir[ms];
int dead[ms];
int alive[2];
// set<pair<int, int>> drones[2];
vector<pair<int, int>> myDrones[2];
int pqSz[2];
queue<iii> pq[2];

int getNext(int id, int t) {
    return nxt[t][id];
}
 
int getPrev(int id, int t) {
    return prv[t][id];
}

int getCollisionTime(int i, int j) {
    int myTime = max(curTime[i], curTime[j]);
    int pj = (pos[j] + (myTime-curTime[j])*dir[j]);
    int pi = (pos[i] + (myTime-curTime[i])*dir[i]);
//     if(j == 7) {
// cout << "help "<< pi << ' ' << pj  << endl;
//     }
    int dis = pj - pi;
    int relVel = dir[i] - dir[j];
    if(relVel <= 0) return -1;
    int collisionTime = myTime + dis / relVel;
    // if(i == 6 && j == 3) {
    //     cout << pj << ' ' << pi << ' ' << myTime << ' ' << collisionTime << endl;
    //     cout << pos[j] << endl;
    //     cout << myTime - curTime[j] << endl;
    // }
    return collisionTime;
}
 

void addCollision(int id, int t, int nxt = -1) {
    if(nxt == -1) nxt = getNext(id, t);
    if(nxt != -1) {
        int ct = getCollisionTime(id, nxt);
        if(ct != -1) {
            pq[t].emplace(ct, ii(id, nxt));
            pqSz[t]++;
        }
    }
}
void kil(int id, int t) {
    // drones[t].erase({pos[id], id});
    int idPrev = getPrev(id, t);
    int idNext = getNext(id, t);
    nxt[t][idPrev] = idNext;
    prv[t][idNext] = idPrev;
    if (idPrev >= 0 && idNext >= 0) {
        addCollision(idPrev, t, idNext);
    }
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        dead[0] = -1;
        dir[n+1] = 0;
        dead[n+1] = -1;
        curTime[n+1] = 0;
        for(int i = 1; i <= n; i++) {
            dead[i] = -1;
            curTime[i] = 0;
            cin >> pos[i];
            pos[i] *= 2;
        } 
        for(int i = 1; i <= n; i++) {
            string s;
            cin >> s;
            if(s[0] == 'R') dir[i] = 1;
            else dir[i] = -1;
        }
        alive[0] = alive[1] = 0;
        pqSz[0] = pqSz[1] = 0;
        for(int t = 0; t < 2; t++) {
            while(!pq[t].empty()) pq[t].pop();
            myDrones[t].clear();
        }
        pos[n+1] = m*2;
        for(int i = 1; i <= n; i++) {
            // cout << pos[i] << ' ' << pos[i]%2 << endl;
            myDrones[(pos[i]/2) % 2].emplace_back(pos[i], i);
            alive[(pos[i]/2)%2]++;
        }
        // cout << alive[0] << ' ' << alive[1] << "help?" << endl;
        for(int t = 0; t < 2; t++) {
            sort(myDrones[t].begin(), myDrones[t].end());
            // cout << myDrones[t].size() << endl;
            for(int i = 0; i < myDrones[t].size(); i++) {
                prv[t][myDrones[t][i].second] = (i == 0) ? 0 : myDrones[t][i-1].second;
                nxt[t][myDrones[t][i].second] = (i+1 == myDrones[t].size()) ? n+1 : myDrones[t][i+1].second;
            }
            if(!myDrones[t].empty()) {
                nxt[t][0] = myDrones[t][0].second;
                prv[t][n+1] = myDrones[t][myDrones[t].size()-1].second;
            }
            addCollision(0, t);
            for(int i = 0; i < myDrones[t].size(); i++) addCollision(myDrones[t][i].second, t);
            while(alive[t] > 1 && pqSz[t] != 0) {
                int currentTime = pq[t].front().first;
                int leftId = pq[t].front().second.first;
                int rightId = pq[t].front().second.second;
                pq[t].pop();
                pqSz[t]--;
                // cout << leftId << ' ' << rightId << ' ' << currentTime << endl;
                // cout << pqSz[t] << endl;
                if(dead[leftId] != -1 || dead[rightId] != -1) continue;
                if(leftId == 0) {
                    pos[rightId] = 0;
                    dir[rightId] = 1;
                    curTime[rightId] = currentTime;
                    // cout << "new position0 = " << rightId << " -> " << currentTime << endl;
                    addCollision(rightId, t);
                } else if(rightId == n+1) {
                    pos[leftId] = m*2;
                    dir[leftId] = -1;
                    curTime[leftId] = currentTime;
                    // cout << "new position = " << leftId << " -> " << currentTime << endl;
                    addCollision(getPrev(leftId, t), t, leftId);
                } else {
                    // check pi e pj
                    if(dir[leftId] - dir[rightId] <= 0) continue;
                        kil(leftId, t);
                        kil(rightId, t);
                        dead[leftId] = dead[rightId] = currentTime/2;
                        alive[t] -= 2;
                }
            }
        }
        // cout << "ANS = ";
        for(int i = 1; i <= n; i++) {
            cout << dead[i] << ' ';
        }
        cout << endl;

    }
    return 0;
}