#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>
#include <stdio.h>
#include <cstdlib>


using namespace std;



int n;
vector<int> blocks[201];
int cnt[201][100001];
int l = 500;
int cntOfBlocks;


void Update(vector<int> &a) {
    cntOfBlocks = 0;
    for (int i = 0; i < n; i += l) {
        int j = min(i + l - 1, n - 1);
        for (int j = 0; j < (int)blocks[cntOfBlocks].size(); j++) {
            cnt[cntOfBlocks][blocks[cntOfBlocks][j]]--;
        }
        blocks[cntOfBlocks].clear();
        for (int k = i; k <= j; k++) {
            blocks[cntOfBlocks].push_back(a[k]);
            cnt[cntOfBlocks][a[k]]++;
        }
        cntOfBlocks++;
    }
}


int findAns(int l, int r, int k) {
    int curpos = 0;
    int ans = 0;
    for (int i = 0; i < cntOfBlocks; i++) {
        if (curpos >= l && curpos + (int)blocks[i].size() - 1 <= r) {
            ans += cnt[i][k];
        } else {
            int nl = max(curpos, l);
            int nr = min(curpos + (int)blocks[i].size() - 1, r);
            if (nl <= nr) {
                for (int j = nl; j <= nr; j++) {
                    ans += (blocks[i][j - curpos] == k);
                }
            }
        }
        curpos += (int)blocks[i].size();
    }
    return ans;
}



int Delete(int x) {
    int curpos = 0;
    for (int i = 0; i < cntOfBlocks; i++) {
        if (curpos <= x && x <= curpos + (int)blocks[i].size() - 1) {
            int t = x - curpos;
            int ans = blocks[i][t];
            cnt[i][ans]--;
            vector<int> newblock;
            for (int j = 0; j < (int)blocks[i].size(); j++) {
                if (j != t) {
                    newblock.push_back(blocks[i][j]);
                }
            }
            blocks[i] = newblock;
            return ans;
        }
        curpos += (int)blocks[i].size();
    }
    return 0;
}


void Paste(int x, int a) {
    if (x == -1) {
        cnt[0][a]++;
        vector<int> newblock;
        newblock.push_back(a);
        for (int j = 0; j < (int)blocks[0].size(); j++) {
            newblock.push_back(blocks[0][j]);
        }
        blocks[0] = newblock;
        return;
    }
    int curpos = 0;
    for (int i = 0; i < cntOfBlocks; i++) {
        if (curpos <= x && x <= curpos + (int)blocks[i].size() - 1) {
            int t = x - curpos;
           // cout << t << endl;
            cnt[i][a]++;
            vector<int> newblock;
            for (int j = 0; j < (int)blocks[i].size(); j++) {
                newblock.push_back(blocks[i][j]);
                if (j == t) {
                    newblock.push_back(a);
                }
            }
            blocks[i] = newblock;
            return;
        }
        curpos += (int)blocks[i].size();
    }
}


int main() {
    cin >> n;
    vector<int> v;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    Update(v);
    int q;
    cin >> q;
    int cnt = 0;
    int lastans = 0;
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int l, r;
            scanf("%d %d", &l, &r);
            l = (l + lastans - 1) % n + 1;
            r = (r + lastans - 1) % n + 1;
            if (l > r) {
                swap(l, r);
            }
            //cout << l << ' ' << r << endl;
            l--;
            r--;
            if (l == r) {
                continue;
            }
            int a = Delete(r);
            Paste(l - 1, a);
            cnt++;
            if (cnt >= 1000) {
                cnt = 0;
                v.clear();
                for (int j = 0; j < cntOfBlocks; j++) {
                    for (int k = 0; k < (int)blocks[j].size(); k++) {
                        v.push_back(blocks[j][k]);
                    }
                }
                Update(v);
            }
        } else {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            k = (k + lastans - 1) % n + 1;
            l = (l + lastans - 1) % n + 1;
            r = (r + lastans - 1) % n + 1;
            if (l > r) {
                swap(l, r);
            }
            l--;
            r--;
            lastans = findAns(l, r, k);
            printf("%d\n", lastans);
        }
    }
    return 0;
}