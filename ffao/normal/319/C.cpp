#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int n;
long long h[110000];
long long c[110000];

struct ponto {
    long long x, y;
};

int ccw(ponto p0, ponto p1, ponto p2) {
    return ( ((long double)(p1.y-p0.y))*(p2.x-p0.x) < ((long double)(p2.y-p0.y))*(p1.x-p0.x));
}

ponto pilha[110000];
int ini, tam;

inline long long calc(int i, int v) {
    return pilha[i].x * v + pilha[i].y;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    ponto sent = {c[0] + 1, 0};
    pilha[tam++] = sent;

    ponto prim = {c[0], 0};
    pilha[tam++] = prim;

    int prev = 1;
    long long ans = 0;

    for (int i = 1; i < n; i++) {
        while (prev+1 < tam && calc(prev+1, h[i]) <= calc(prev, h[i]) ) prev++;

        if (i == n-1) {
            ans = calc(prev, h[i]);
            break;
        }

        ponto novo = {c[i], calc(prev, h[i])};

        while (tam >= 3 && ccw(pilha[tam-2], pilha[tam-1], novo)) tam--;

        if (prev >= tam) prev = tam-1;
        pilha[tam++] = novo;
    }

    cout << ans << endl;
}