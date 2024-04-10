#include <bits/stdc++.h>
using namespace std;

#define SIZE 100005

int array1[SIZE];
int array2[SIZE];
vector<int> graph[SIZE];
set<int> proibidos;
vector<int> fontes;
vector<int> necessarias;
bool visitado[SIZE];
    
int n, m;

bool dfs(int pos) {
    visitado[pos] = true;
    necessarias.push_back(pos);
    for(int i = 0; i < graph[pos].size(); i++) {
        int v = graph[pos][i];
        if(visitado[v]) {
            continue;
        }
        if(proibidos.count(v) || !dfs(v)) {
            return false;
        }
    }
    return true;
}

bool leitura(int *a, int *b, int sizeA, int atual) {
    /*printf("Palavra %d:", atual);
    for(int i = 0; i < sizeA; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");*/
    if(atual == n) {
        return true;
    }
    int sizeB;
    scanf("%d", &sizeB);
    for(int i = 0; true; i++) {
        if(i == sizeA) {
            for(int j = i; j < sizeB; j++) {
                scanf("%d", b+j);
            }
            return leitura(b, a, sizeB, atual + 1);
        } else if(i == sizeB) {
            return false;
        }
        scanf("%d", b+i);
        if(a[i] == b[i]) {
            continue;
        }
        if(a[i] < b[i]) {
            //printf("Letra %d maior que %d na palavra %d\n", b[i], a[i], atual+1);
            graph[b[i]].push_back(a[i]);
        } else {
            //printf("Letra %d menor que %d na palavra %d\n", b[i], a[i], atual+1);
            if(proibidos.count(a[i])) {
                return false;
            }
            fontes.push_back(a[i]);
            proibidos.insert(b[i]);
        }
        for(int j = i+1; j < sizeB; j++) {
            scanf("%d", b+j);
        }
        return leitura(b, a, sizeB, atual + 1);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    int tamanho;
    scanf("%d", &tamanho);
    for(int i = 0; i < tamanho; i++) {
        scanf("%d", array1 + i);
    }
    if(!leitura(array1, array2, tamanho, 1)) {
        printf("No\n");
        return 0;
    }
    for(int i = 0; i < fontes.size(); i++) {
        if(!visitado[fontes[i]]) {
            if(!dfs(fontes[i])) {
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n%d\n", necessarias.size());
    for(int i = 0; i < necessarias.size(); i++) {
        if(i) {
            printf(" ");
        }
        printf("%d", necessarias[i]);
    }
	return 0;
}