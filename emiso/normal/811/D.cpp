#include <bits/stdc++.h>

#define MN 110
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

#define X first
#define Y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n, m, dist[MN][MN], sX = -1, sY = -1, flag = 0;
bool visit[MN][MN];
char line[MN], grid[MN][MN];
string q;

pii ini, fim, cpos, par[MN][MN];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool valid_cell(int x, int y) {
    ///return grid[x][y] == '.';
    return grid[x][y] != '*';
}

pii query(char input, int discard = 0) {
    printf("%c\n", input);
    fflush(stdout);

    pii cini = cpos;

    int x, y;
    scanf("%d %d", &x, &y);
    cpos = {--x, --y};
    if(cpos == fim) {
        flag = 1;
    }

    if(!discard && cini != cpos) q += input;

    return {x, y};
}

void discover() {
    if(cpos == fim) {
        flag = 1;
        return;
    }

    pii in = cpos;
    //printf("disc %d %d %d %d\n", in.X, in.Y, sX, sY);
    if(sX != -1 && sY != -1) return;

    if(sX == -1) {
        if(grid[in.X + 1][in.Y] == '.' || grid[in.X + 1][in.Y] == 'F' ) {
            pii pos = query('D');
            if(pos.X == in.X + 1) sX = 0;
            else sX = 1;

            discover();
            return;
        }
    }

    if(sY == -1) {
        if(grid[in.X][in.Y + 1] == '.' || grid[in.X][in.Y + 1] == 'F') {
            //printf("%c %c---\n", grid[in.X][in.Y], grid[in.X][in.Y + 1]);
            pii pos = query('R');
            if(pos.Y == in.Y + 1) sY = 0;
            else sY = 1;

            discover();
            return;
        }
    }

    if(sX != -1 && sY != -1) return;

    if(sX != -1) {
        if(grid[in.X + 1][in.Y] == '.' || grid[in.X + 1][in.Y] == 'F') {
            if(sX == 0) pii pos = query('D');
            else pii pos = query('U');

            discover();
            return;
        }
    }

    else if(sY != -1) {
        if(grid[in.X][in.Y + 1] == '.' || grid[in.X][in.Y + 1] == 'F') {
            if(sY == 0) pii pos = query('R');
            else pii pos = query('L');

            discover();
            return;
        }
    }
}

void goback() {
    for(int i=q.size()-1; i>=0; i--) {
        if(cpos == fim) {
            flag = 1;
            return;
        }

        char in = q[i];

        if(in == 'L')
            query('R', 1);

        else if(in == 'R')
            query('L');

        else if(in == 'U')
            query('D');

        else if(in == 'D')
            query('U');
    }

    q = "";
    assert(cpos == ini);
}

void bfs(pii ini) {
    if(cpos == fim) {
        flag = 1;
        return;
    }

    queue<pii> fila;
    fila.push(ini);
    visit[ini.X][ini.Y] = true;
    dist[ini.X][ini.Y] = 0;

    while(!fila.empty()) {
        pii u = fila.front();
        fila.pop();

        for(int i=0; i<4; i++) {
            int nx = u.X + dx[i];
            int ny = u.Y + dy[i];

            if(!valid(nx, ny)) continue;
            if(!valid_cell(nx, ny)) continue;
            if(visit[nx][ny]) continue;

            fila.push({nx, ny});
            par[nx][ny] = {u.X, u.Y};
            visit[nx][ny] = true;
        }
    }
}


int main() {
    scanf("%d %d", &n, &m);
    ini = {0, 0};

    for(int i=0; i<n; i++) {
        scanf("%s", line);
        for(int j=0; j<m; j++) {
            grid[i][j] = line[j];
            if(grid[i][j] == 'F') fim = {i, j};
        }
    }

    discover();
    while(sX == -1 || sY == -1) {
        if(flag) return 0;
        goback();
        discover();
    }
    //cout << "trace " << q << endl;
    goback();

    bfs(ini);

    if(flag) return 0;

    stack <pii> pilha;
    pii atual = fim;
    while(atual != ini) {
        pilha.push(atual);
        atual = par[atual.X][atual.Y];
    }

    atual = ini;
    while(atual != fim) {
        pii nxt = pilha.top();
        pilha.pop();

        if(atual.X < nxt.X) {
            if(sX == 0) query('D');
            else query('U');
        }

        else if(atual.X > nxt.X) {
            if(sX == 0) query('U');
            else query('D');
        }

        else if(atual.Y < nxt.Y) {
            if(sY == 0) query('R');
            else query('L');
        }

        else if(atual.Y > nxt.Y) {
            if(sY == 0) query('L');
            else query('R');
        }

        assert(cpos == nxt);
        atual = nxt;
    }

    return 0;
}