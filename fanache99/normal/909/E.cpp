//#inlude <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <set>
#include <complex>
#include <cstring>

using namespace std;

const int SIZE = 1 << 10;

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

const int MAXN = 100000;

int type[1 + MAXN];
vector<int> gt[1 + MAXN];
int outDegree[1 + MAXN];
queue<int> Queue;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &type[i]);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a++;
        b++;
        gt[b].push_back(a);
        outDegree[a]++;
    }
    for (int i = 1; i <= n; i++)
        if (type[i] == 0 && !outDegree[i])
            Queue.push(i);
    while (!Queue.empty()) {
        int node = Queue.front();
        Queue.pop();
        for (auto &it : gt[node]) {
            outDegree[it]--;
            if (!outDegree[it] && !type[it])
                Queue.push(it);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!outDegree[i] && type[i])
            Queue.push(i);
    int answer = 0;
    while (!Queue.empty()) {
        answer++;
        queue<int> newQueue;
        while (!Queue.empty()) {
            int node = Queue.front();
            Queue.pop();
            for (auto &it : gt[node]) {
                outDegree[it]--;
                if (!outDegree[it])
                    if (type[it])
                        Queue.push(it);
                    else
                        newQueue.push(it);
            }
        }
        while (!newQueue.empty()) {
            int node = newQueue.front();
            newQueue.pop();
            for (auto &it : gt[node]) {
                outDegree[it]--;
                if (!outDegree[it])
                    if (type[it])
                        Queue.push(it);
                    else
                        newQueue.push(it);
            }
        }
    }
    printf("%d\n", answer);
    return 0;
}