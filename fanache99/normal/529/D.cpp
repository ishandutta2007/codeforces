#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <set>
#include <map>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int SIZE = 1 << 17;

char buffer[SIZE];
int pointer = SIZE;

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

const int MAXN = 20000;

char s[9];
pair<int, int> v[1 + MAXN];
int answer[1 + MAXN];
set<pair<int, int> > Set;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m, t;
    scanf("%d%d%d\n", &n, &m, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        v[i].first = ((s[1] - '0') * 10 + s[2] - '0') * 3600 + ((s[4] - '0') * 10 + s[5] - '0') * 60 + (s[7] - '0') * 10 + s[8] - '0';
        v[i].second = i;
    }
    sort(v + 1, v + n + 1);
    bool found = false;
    int number = 0;
    for (int i = 1; i <= n; i++) {
        while (!Set.empty() && (*Set.begin()).first <= v[i].first)
            Set.erase(*Set.begin());
        if (Set.size() < m) {
            number++;
            answer[v[i].second] = number;
            Set.insert(make_pair(v[i].first + t, number));
        }
        else {
            answer[v[i].second] = (*Set.rbegin()).second;
            Set.erase(*Set.rbegin());
            Set.insert(make_pair(v[i].first + t, answer[v[i].second]));
        }
        if (Set.size() == m)
            found = true;
    }
    if (!found) {
        printf("No solution\n");
        return 0;
    }
    printf("%d\n", number);
    for (int i = 1; i <= n; i++)
        printf("%d\n", answer[i]);
    return 0;
}