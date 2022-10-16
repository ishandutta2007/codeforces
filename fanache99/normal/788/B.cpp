#include <fstream>
//#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXN = 1000000;
const int SIZE = 1 << 17;

int degree[1 + MAXN];
int dad[1 + MAXN], nodes[1 + MAXN];
bool selfLoop[1 + MAXN];

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

void Initialize(int n) {
    for (int i = 1; i <= n; i++) {
        dad[i] = i;
        nodes[i] = 1;
    }
}

int FindDad(int node) {
    int parent = node;
    while (dad[parent] != parent)
        parent = dad[parent];
    while (node != parent) {
        int temp = dad[node];
        dad[node] = parent;
        node = temp;
    }
    return parent;
}

void Join(int a, int b) {
    if (a == b)
        return;
    if (nodes[a] < nodes[b]) {
        dad[a] = b;
        nodes[b] += nodes[a];
    }
    else {
        dad[b] = a;
        nodes[a] += nodes[b];
    }
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n = Read(), m = Read(), roads = 0, loops = 0;
    long long answer = 0;
    Initialize(n);
    for (int i = 1; i <= m; i++) {
        int a = Read(), b = Read();
        if (a != b) {
            degree[a]++;
            degree[b]++;
            roads++;
            Join(FindDad(a), FindDad(b));
        }
        else {
            loops++;
            selfLoop[a] = true;
        }
    }
    int big = 0;
    for (int i = 1; i <= n; i++)
        if (dad[i] == i && (nodes[i] > 1 || selfLoop[i]))
            big++;
    if (big > 1) {
        printf("0\n");
        return 0;
    }
    for (int i = 1; i <= n; i++)
        answer += 1LL * degree[i] * (degree[i] - 1) / 2;
    answer += 1LL * loops * roads + 1LL * loops * (loops - 1) / 2;
    printf("%I64d\n", answer);
    return 0;
}