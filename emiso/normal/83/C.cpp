#include <bits/stdc++.h>

#define MN 55

using namespace std;
typedef pair<int,int> pii;

int n, m, k;
char mapa[MN][MN];
pii ini, fim;

int dX[] = {1, 0, -1, 0};
int dY[] = {0, -1, 0, 1};

set<int> set_cores[MN][MN];

struct evento {
    int x, y, cores, dist;
    string caminho;

    evento(int x, int y) : x(x), y(y), cores(0), dist(0), caminho("") {}
    evento(int x, int y, int d, int co, string c) : x(x), y(y), cores(co), dist(d), caminho(c) {}

    bool operator <(const evento& o) const {
        return tie(dist, caminho) > tie(o.dist, o.caminho);
    }
};

bool invalid(int nx, int ny) {
    return nx < 0 || nx >= n || ny < 0 || ny >= m;
}

void dijkstra() {
    priority_queue<evento> pfila;
    pfila.push(evento(ini.first, ini.second));

    while(!pfila.empty()) {
        evento u = pfila.top();
        pfila.pop();

        int x = u.x, y = u.y;
        if(mapa[x][y] == 'T') {
            cout << u.caminho << endl;
            return;
        }

        for(int i=0;i<4;i++) {
            int nx = x + dX[i];
            int ny = y + dY[i];
            string ncaminho = u.caminho;
            int ncores = u.cores;

            if(invalid(nx, ny)) continue;

            if(mapa[nx][ny] >= 'a' && mapa[nx][ny] <= 'z') {
                ncaminho += mapa[nx][ny];
                ncores |= (1 << (mapa[nx][ny] - 'a'));
            }

            int flag_visitado = 0;
            for(auto cor : set_cores[nx][ny]) {
                if((cor | ncores) == ncores) {
                    flag_visitado = 1;
                    break;
                }
            }

            if(flag_visitado) continue;
            if(__builtin_popcount(ncores) <= k) {
                set_cores[nx][ny].insert(ncores);
                pfila.push(evento(nx, ny, u.dist + 1, ncores, ncaminho));
            }
        }
    }

    cout << "-1" << endl;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < n; i++) {
        scanf("%s", mapa[i]);

        for (int j = 0; j < m; j++) {
            if (mapa[i][j] == 'S') {
                ini = {i, j};
            }
            if (mapa[i][j] == 'T') {
                fim = {i, j};
            }
        }
    }

    dijkstra();

    return 0;
}