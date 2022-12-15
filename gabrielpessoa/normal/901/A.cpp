#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<int, double> id;
typedef vector<id> vid;
typedef pair<double, int> di;
typedef vector<di> vdi;
typedef pair<string, string> ss;

const int SIZE  = 2E5+5;
const int MOD = 1E9 + 7;
const long double EPS = 1e-14;
const int INF = 0x3f3f3f3f;

int arr[SIZE];
int resposta[SIZE];
int resposta2[SIZE];

int main() {
    int h;
    bool possible = false;
    scanf("%d", &h);
    for(int i = 0; i <= h; i++) {
        scanf("%d", &arr[i]);
        if(i && arr[i] > 1 && arr[i-1] > 1) possible = true;
    }
    if(!possible) {
        printf("perfect\n");
        return 0;
    }
    int atual = arr[0]+1;
    possible = false;
    int ultimo = 1;
    int ultimo2 = -1;
    for(int i = 1; i < atual; i++) {
        resposta[i] = 0;
        resposta2[i] = 0;
    }
    for(int i = 1; i <= h; i++) {
        for(int j = atual; j < atual + arr[i]; j++) {
            resposta[j] = ultimo;
            resposta2[j] = ultimo;
        }
        if(!possible && ~ultimo2 && arr[i] > 1) {
            possible = true;
            resposta2[atual+1] = ultimo2;
        } else if(!possible && arr[i] > 1) {
            ultimo2 = atual + 1;
        } else if(!possible && arr[i] == 1) {
            ultimo2 = -1;
        }
        ultimo = atual;
        atual = atual + arr[i];
    }
    printf("ambiguous\n");
    for(int i = 1; i < atual; i++) {
        printf("%d ", resposta[i]);
    }
    printf("\n");
    for(int j = 1; j < atual; j++) {
        printf("%d ", resposta2[j]);
    }
    printf("\n");
    return 0;
}