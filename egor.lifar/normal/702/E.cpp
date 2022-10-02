#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
 
 
using namespace std;
 

 
int n;
long long k;
int jump[100001];
int w[100001];
long long jumpSum[100001][18];
int jumpMin[100001][18];
int jumps[100001][18];
int used[100001];
vector<int> cycles[100001];
bool inCycle[100001];
long long ansSum[100001];
int ansMin[100001];
int dist[100001];
int inwhichcycle[100001];
int who[100001];


int getmin(int h, int k) {
    int ans = 2000000000;
    for (int i = 17; i >= 0; i--) {
        if ((1 << i) <= k) {
            ans = min(ans, jumpMin[h][i]);
            h = jumps[h][i];
            k -= (1 << i);
        }
    }
    return ans;
}


long long getsum(int h, int k) {
    long long ans = 0;
    for (int i = 17; i >= 0; i--) {
        if ((1 << i) <= k) {
            ans += jumpSum[h][i];
            h = jumps[h][i];
            k -= (1 << i);
        }
    }
    return ans;
}


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        scanf("%d", &jump[i]);
        jumps[i][0] = jump[i];
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
        jumpSum[i][0] = w[i];
        jumpMin[i][0] = w[i];
    }
    int cntCycles = 0;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            int i1 = i;
            used[i] = i + 1;
            while (!used[jump[i1]]) {
                i1 = jump[i1];
                used[i1] = i + 1;
            }
            if (used[jump[i1]] == used[i]) {
                int ni = jump[i1];
                do {
                    inCycle[ni] = 1;
                    cycles[cntCycles].push_back(ni);
                    who[ni] = ni;
                    ni = jump[ni];
                    inwhichcycle[ni] = cntCycles;
                    dist[ni] = 0;
                } while (ni != jump[i1]);
                cntCycles++;
            }
        }
    }
   // cout << "opa" << endl;
    memset(used, 0, sizeof(used));
    for (int i = 0; i < n; i++) {
        if (!used[i] && !inCycle[i]) {
            int ni = i;
            vector<int> v;
            used[i] = 1;
            v.push_back(ni);
            while (!used[jump[ni]] && !inCycle[jump[ni]]) {
                used[ni] = 1;
                ni = jump[ni];
                v.push_back(ni);
            }
            for (int j = (int)v.size() - 1; j >= 0; j--) {
                int h = v[j];
                dist[h] = dist[jump[h]] + 1;
                who[h] = who[jump[h]];
                inwhichcycle[h] = inwhichcycle[jump[h]];
            }
        }
    }
    for (int k = 1; k <= 17; k++) {
        for (int j = 0; j < n; j++) {
            int h = j;
            jumps[h][k] = jumps[jumps[h][k - 1]][k - 1];
            jumpSum[h][k] = jumpSum[jumps[h][k - 1]][k - 1] + jumpSum[h][k - 1];
            jumpMin[h][k] = min(jumpMin[jumps[h][k - 1]][k - 1], jumpMin[h][k - 1]);
        }
    }
  //  cout << cntCycles << endl;
    for (int i = 0; i < cntCycles; i++) {
        for (int j = 0; j < (int)cycles[i].size(); j++) {
            int h = cycles[i][j];
            long long k1 = k % (int)cycles[i].size();
            long long k2 = k / (int)cycles[i].size();
            ansMin[h] = 2000000000;
            if (k2) {
                ansMin[h] = getmin(h, (int)cycles[i].size());
            }
            ansMin[h] = min(ansMin[h], getmin(h, k1));
            ansSum[h] = getsum(h, k1) + getsum(h, (int)cycles[i].size()) * k2;
        }
    }
    for (int i = 0; i < n; i++) {
        //cout << inCycle[i] << endl;
        if (!inCycle[i]) {
            ansMin[i] = 2000000000;
            long long kk = k;
            //cout << dist[i] << endl;
            if (dist[i] < kk) {
               // cout << inwhichcycle[i] << endl;
                ansSum[i] += getsum(i, dist[i]);
                ansMin[i] = min(ansMin[i], getmin(i, dist[i]));
                kk -= dist[i];
               // cout << inwhichcycle[i] << endl;
             //  cout << (int)cycles[inwhichcycle[i]].size() << endl;
                long long k1 = kk % (int)cycles[inwhichcycle[i]].size();
                long long k2 = kk / (int)cycles[inwhichcycle[i]].size();
                int ni = who[i];
                if (k2) {
                    ansMin[i] = min(ansMin[i], getmin(ni, (int)cycles[inwhichcycle[i]].size()));
                }
                ansMin[i] = min(ansMin[i], (k1 ? getmin(ni, k1): ansMin[i]));
                ansSum[i] += (k1 ? getsum(ni, k1): 0LL) + getsum(ni, (int)cycles[inwhichcycle[i]].size()) * k2;
            } else {
                ansSum[i] += getsum(i, kk);
                ansMin[i] = min(ansMin[i], getmin(i, kk));
            }
        }
        printf("%I64d %d\n", ansSum[i], ansMin[i]);
    }
    return 0;
}