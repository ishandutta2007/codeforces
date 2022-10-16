#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 300000;
const int INF = 2000000000;
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

vector<int> g[1 + MAXN];
int Queue[1 + MAXN], which[1 + MAXN];
pair<int, int> edge[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), k = Read(), d = Read(), left = 1, right = 0, stations = 0;
    for (int i = 1; i <= k; i++) {
        int x = Read();
        if (!which[x]) {
            stations++;
            right++;
            Queue[right] = x;
            which[x] = x;
        }
    }
    for (int i = 1; i < n; i++) {
        edge[i].first = Read();
        edge[i].second = Read();
        g[edge[i].first].push_back(edge[i].second);
        g[edge[i].second].push_back(edge[i].first);
    }
    while (left <= right) {
        int node = Queue[left];
        left++;
        for (auto &it : g[node])
            if (!which[it]) {
                which[it] = which[node];
                right++;
                Queue[right] = it;
            }
    }
    printf("%d\n", stations - 1);
    for (int i = 1; i < n; i++)
        if (which[edge[i].first] != which[edge[i].second])
            printf("%d ", i);
    return 0;
}