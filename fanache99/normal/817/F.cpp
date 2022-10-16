#include <fstream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>
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

const int MAXQ = 100000;
const long long MAXVAL = 1e18;

map<long long, int> code;
map<int, long long> decode;

int queryType[1 + MAXQ];
long long queryFrom[1 + MAXQ], queryTo[1 + MAXQ];
int sum[1 + 12 * MAXQ], lazy[1 + 12 * MAXQ];

int type, from, to;

void Push(int node, int type, int left, int right) {
    if (type == 1)
        sum[node] = right - left + 1;
    if (type == 2)
        sum[node] = 0;
    if (type == 3)
        sum[node] = right - left + 1 - sum[node];
    if (!lazy[node])
        lazy[node] = type;
    else
        if (type != 3)
            lazy[node] = type;
        else
            if (lazy[node] != 3)
                lazy[node] = 3 - lazy[node];
            else
                lazy[node] = 0;
}

void Propagate(int node, int left, int right) {
    if (!lazy[node])
        return;
    if (left == right)
        return;
    int middle = (left + right) / 2;
    Push(2 * node, lazy[node], left, middle);
    Push(2 * node + 1, lazy[node], middle + 1, right);
    lazy[node] = 0;
}

void Update(int node, int left, int right) {
    if (from <= left && right <= to) {
        Push(node, type, left, right);
        return;
    }
    Propagate(node, left, right);
    int middle = (left + right) / 2;
    if (from <= middle)
        Update(2 * node, left, middle);
    if (middle + 1 <= to)
        Update(2 * node + 1, middle + 1, right);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}

int Query(int node, int left, int right) {
    Propagate(node, left, right);
    if (left == right)
        return left;
    int middle = (left + right) / 2;
    Propagate(2 * node, left, middle);
    if (sum[2 * node] != middle - left + 1)
        return Query(2 * node, left, middle);
    return Query(2 * node + 1, middle + 1, right);
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int q;
    scanf("%d", &q);
    code[1] = 1;
    for (int i = 1; i <= q; i++) {
        scanf("%d%I64d%I64d\n", &queryType[i], &queryFrom[i], &queryTo[i]);
        code[queryFrom[i]] = 1;
        code[queryTo[i]] = 1;
        code[queryTo[i] + 1] = 1;
    }
    int number = 0;
    for (auto &it : code) {
        number++;
        it.second = number;
        decode[number] = it.first;
    }
    for (int i = 1; i <= q; i++) {
        type = queryType[i];
        from = code[queryFrom[i]];
        to = code[queryTo[i]];
        Update(1, 1, number);
        printf("%I64d\n", decode[Query(1, 1, number)]);
    }
    return 0;
}