#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int x[3], y[3];


bool check(int i, int j, int k){
    if ((x[i] == x[j]) && (x[j] == x[k]) && (y[i] + y[j] + y[k] == x[j])){
        printf("%d\n", x[i]);
        for (int X = 0; X < y[i]; X++){
            for (int Y = 0; Y < x[i]; Y++)
                printf("%c", 'A' + i);
            puts("");
        }
        for (int X = 0; X < y[j]; X++){
            for (int Y = 0; Y < x[j]; Y++)
                printf("%c", 'A' + j);
            puts("");
        }
        for (int X = 0; X < y[k]; X++){
            for (int Y = 0; Y < x[k]; Y++)
                printf("%c", 'A' + k);
            puts("");
        }
        return 1;
    }
    if (x[i] == x[j] + x[k] && y[j] == y[k] && y[j] + y[i] == x[i]){
        printf("%d\n", x[i]);
        for (int X = 0; X < y[i]; X++){
            for (int Y = 0; Y < x[i]; Y++)
                printf("%c", 'A' + i);
            puts("");
        }
        for (int X = 0; X < y[j]; X++){
            for (int Y = 0; Y < x[j] + x[k]; Y++){
                printf("%c", 'A' + (Y >= x[j] ? k : j));
            }
            puts("");
        }
        return 1;
    }
    return 0;
}

int main(){
    for (int i = 0; i < 3; i++)
        scanf("%d%d", &x[i], &y[i]);
    for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
    for (int k = 0; k < 3; k++)
    if (i != j && i != k && j != k){
        for (int p = 0; p < 8; p++){
            for (int q = 0; q < 3; q++)
            if (p >> q & 1) swap(x[q], y[q]);
            if (check(i, j, k)) return 0;
            for (int q = 0; q < 3; q++)
            if (p >> q & 1) swap(x[q], y[q]);
        }
    }
    puts("-1");
}