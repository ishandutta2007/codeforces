#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

#define E1

const int N = 50;

std::vector <int> *graph[N][N], *igraph[N][N];

std::vector <int> expand(std::vector <int> *graph[N][N], std::vector <int> queue, int max)
{
    for (int t = 0; t + 1 < (int)queue.size() && (int)queue.size() <= max; ++ t) {
        int u = queue[t];
        int v = queue[t + 1];
        if (graph[u][v] == NULL) {
            return std::vector <int>();
        } else {
            for (int w : *graph[u][v]) {
                queue.push_back(w);
            }
        }
    }
    return queue;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(graph, 0, sizeof(graph));
    for (int i = 0; i < m; ++ i) {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        x --;
        y --;
        std::vector <int> seq;
        while (k --) {
            int v;
            scanf("%d", &v);
            seq.push_back(-- v);
        }
        graph[x][y] = new std::vector <int>(seq);
        std::reverse(seq.begin(), seq.end());
        igraph[y][x] = new std::vector <int>(seq);
    }
#ifdef E1
    bool found = false;
#endif
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (graph[i][j] != NULL) {
                std::vector <int> seq = *graph[i][j];
                for (int k = 1; k < (int)seq.size(); ++ k) {
                    if (seq[k - 1] == i && seq[k] == j) {
                        std::vector <int> fw = expand(graph, std::vector <int>(seq.begin() + k, seq.end()), 2 * n);
                        std::vector <int> iseq(seq.begin(), seq.begin() + k);
                        std::reverse(iseq.begin(), iseq.end());
                        std::vector <int> bw = expand(igraph, iseq, 2 * n);
                        if (!fw.empty() && !bw.empty()) {
                            std::reverse(bw.begin(), bw.end());
                            for (int t : fw) {
                                bw.push_back(t);
                            }
                            if ((int)bw.size() <= 2 * n && !found) {
#ifdef E1
                                found = true;
                                printf("%d\n", (int)bw.size());
                                for (int i = 0; i < (int)bw.size(); ++ i) {
                                    printf("%d%c", bw[i] + 1, " \n"[i == (int)bw.size() - 1]);
                                }
#endif
                            }
                        }
                    }
                }
            }
        }
    }
#ifdef E1
    if (!found) {
        puts("0");
    }
#endif
    return 0;
}