#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cstdlib>

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

const int MAXN = 200000;

struct Tshirt {
    int p, a, b;

    bool operator < (const Tshirt &other) const {
        return p < other.p;
    }
};

Tshirt v[1 + MAXN];
bool out[1 + MAXN];
vector<int> w[3];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++)
        v[i].p = Read();
    for (int i = 1; i <= n; i++)
        v[i].a = Read();
    for (int i = 1; i <= n; i++)
        v[i].b = Read();
    sort(v + 1, v + n + 1);
    for (int i = n; i >= 1; i--) {
        w[v[i].a].push_back(i);
        if (v[i].a != v[i].b)
            w[v[i].b].push_back(i);
    }
    int m = Read();
    for (int i = 1; i <= m; i++) {
        int c = Read();
        while (!w[c].empty() && out[w[c].back()])
            w[c].pop_back();
        if (w[c].empty())
            printf("-1 ");
        else {
            printf("%d ", v[w[c].back()].p);
            out[w[c].back()] = true;
            w[c].pop_back();
        }
    }
    return 0;
}