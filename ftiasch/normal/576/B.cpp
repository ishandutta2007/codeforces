#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100000;

int p[N];
bool visited[N];

void print_edge(int u, int v) {
    printf("%d %d\n", u + 1, v + 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", p + i);
        p[i] --;
    }
    std::vector<std::vector<int>> cycles;
    memset(visited, 0, sizeof(*visited) * n);
    for (int i = 0; i < n; ++ i) {
        if (!visited[i]) {
            std::vector<int> cycle;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                cycle.push_back(j);
                j = p[j];
            }
            cycles.push_back(cycle);
        }
    }
    int p = 0;
    while (p < (int)cycles.size() && (int)cycles[p].size() > 1) {
        p ++;
    }
    if (p < (int)cycles.size()) {
        puts("YES");
        p = cycles[p][0];
        for (int i = 0; i < n; ++ i) {
            if (i != p) {
                print_edge(i, p);
            }
        }
        return 0;
    }
    p = 0;
    while (p < (int)cycles.size() && (int)cycles[p].size() > 2) {
        p ++;
    }
    if (p < (int)cycles.size()) {
        int a = cycles[p][0];
        int b = cycles[p][1];
        for (int i = 0; i < (int)cycles.size(); ++ i) {
            if ((int)cycles[i].size() % 2 != 0) {
                puts("NO");
                return 0;
            }
        }
        puts("YES");
        print_edge(a, b);
        for (int i = 0; i < (int)cycles.size(); ++ i) {
            if (i != p) {
                const auto &cycle = cycles[i];
                for (int j = 0; j < (int)cycle.size(); ++ j) {
                    if (j & 1) {
                        print_edge(a, cycle[j]);
                    } else {
                        print_edge(b, cycle[j]);
                    }
                }
            }
        }
        return 0;
    }
    puts("NO");
    return 0;
}