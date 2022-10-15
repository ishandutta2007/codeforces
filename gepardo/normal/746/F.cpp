#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>

using namespace std;

int n, w, k;
vector<int> p, v;
int leftPtr = 0;
int rightPtr = -1;
multiset<int, greater<int> > bestSong;
multiset<int, greater<int> > restSong;
int ans = 0;
int pleasure = 0;

inline void balance() {
    while (!restSong.empty() && bestSong.size() < w) {
        int add = *restSong.begin();
        bestSong.insert(add);
        restSong.erase(restSong.begin());
        ans -= add;
    }
}

inline void add(int song) {
    ans += song;
    song = song / 2;
    restSong.insert(song);
    if (!bestSong.empty() && song > *bestSong.rbegin()) {
        int add = *bestSong.rbegin();
        restSong.insert(add);
        bestSong.erase(bestSong.find(add));
        ans += add;
    }
    balance();
}

inline void del(int song) {
    ans -= song;
    song = song / 2;
    if (bestSong.find(song) != bestSong.end()) {
        bestSong.erase(bestSong.find(song));
        ans += song;
        balance();
    } else {
        restSong.erase(restSong.find(song));
    }
}

inline void incLeft() {
    pleasure -= p[leftPtr];
    del(v[leftPtr]);
    leftPtr++;
}

inline void incRight() {
    rightPtr++;
    pleasure += p[rightPtr];
    add(v[rightPtr]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> w >> k;
    p.resize(n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0) incLeft();
        while (rightPtr + 1 < n && ans <= k)
            incRight();
        int cur = pleasure;
        if (ans > k)
            cur -= p[rightPtr];
        res = max(res, cur);
    }
    cout << res << endl;
    return 0;
}