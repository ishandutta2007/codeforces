#include <bits/stdc++.h>

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
pair<int, int> last[1 + MAXN];
vector<pair<int, int> > all;
vector<int> biggest;

int Search(int x) {
    int left = 0, right = all.size() - 1, answer = all.size();
    while (left <= right) {
        int middle = (left + right) / 2;
        if (all[middle].first >= x) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    return answer;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read();
    for (int i = 1; i <= n; i++) {
        v[i] = Read();
        last[i] = make_pair(0, v[i]);
    }
    int q = Read();
    for (int i = 1; i <= q; i++) {
        int type = Read();
        if (type == 1) {
            int x = Read(), y = Read();
            last[x] = make_pair(i, y);
        }
        else {
            int x = Read();
            all.push_back(make_pair(i, x));
        }
    }
    biggest.resize(all.size() + 1);
    biggest[all.size()] = 0;
    for (int i = all.size() - 1; i >= 0; i--)
        biggest[i] = max(biggest[i + 1], all[i].second);
    for (int i = 1; i <= n; i++)
        printf("%d ", max(last[i].second, biggest[Search(last[i].first)]));
    return 0;
}