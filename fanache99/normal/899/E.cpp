//#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <bitset>

using namespace std;

const int SIZE = 1 << 17;
int pointer = SIZE;
char buffer[SIZE];

char Advance() {
    if (pointer == SIZE) {
        fread(buffer, 1, SIZE, stdin);
        pointer = 0;
    }
    return buffer[pointer++];
}

int Read() {
    int answer = 0;
    char ch = Advance();
    while (!isdigit(ch))
        ch = Advance();
    while (isdigit(ch)) {
        answer = answer * 10 + ch - '0';
        ch = Advance();
    }
    return answer;
}

const int MAXN = 200000;

int v[1 + MAXN];
set<pair<int, int> > intervals;
set<pair<int, int> > order;

void Print(set<pair<int, int> > &Set) {
    for (auto &it : Set)
        printf("%d %d\n", it.first, it.second);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, l = 1, x;
    scanf("%d%d", &n, &x);
    v[1] = x;
    for (int i = 2; i <= n; i++) {
        int y;
        scanf("%d", &y);
        v[i] = y;
        if (y == x)
            l++;
        else {
            intervals.insert(make_pair(i - l, l));
            order.insert(make_pair(-l, i - l));
            l = 1;
        }
        x = y;
    }
    intervals.insert(make_pair(n + 1 - l, l));
    order.insert(make_pair(-l, n + 1 - l));
    int answer = 0;
    while (!order.empty()) {
        answer++;
        pair<int, int> out = *order.begin();
        order.erase(out);
        intervals.erase(make_pair(out.second, -out.first));
        auto it = intervals.lower_bound(make_pair(out.second, 0));
        if (it == intervals.end() || it == intervals.begin())
            continue;
        it--;;
        auto jt = it;
        it++;
        if (v[(*it).first] != v[(*jt).first])
            continue;
        pair<int, int> both = make_pair((*it).first, (*it).second + (*jt).second);
        order.erase(make_pair(-(*it).second, (*it).first));
        order.erase(make_pair(-(*jt).second, (*jt).first));
        intervals.erase(it);
        intervals.erase(jt);
        intervals.insert(both);
        order.insert(make_pair(-both.second, both.first));
    }
    printf("%d\n", answer);
    return 0;
}