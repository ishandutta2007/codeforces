#include <stdio.h>

int petya[100];
int masha[100];

int pecyc[100];
int size[110];
int mod[110];

int pcnt;
int n, k;

long long cnt = 1;

typedef long long ll;
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}
ll reach;

void fillcyc(int* board, int* cycles, int i) {
    if (cycles[i] != 0) return;
    
    int j = i;
    do {
        cycles[j] = pcnt;
        j = board[j];
        size[pcnt]++;
    } while (j != i);
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {scanf("%d", &petya[i]); petya[i]--;}
    for (int i = 0; i < n; i++) {scanf("%d", &masha[i]); masha[i]--;}

    for (int i = 0; i < n; i++) {
        if (pecyc[i] == 0) {
            pcnt++;
            mod[pcnt] = -1;
            size[pcnt] = 0;
            fillcyc(petya, pecyc, i);
        }
    }

    int sea = 1;

    for (int i = 0; i < n; i++) {
        int j = i;
        int flip = 0;
        while (masha[j] != i) {
            j = petya[j];
            flip++;

            if (j == i) {
                printf("NO\n");
                return 0;
            }
        }

        if (mod[pecyc[i]] != flip && mod[pecyc[i]] != -1) {
            printf("NO\n");
            return 0;
        } 
        mod[pecyc[i]] = flip;
    }

    int ms = 0;
    int mind = 0;

    for (int i = 1; i <= pcnt; i++) {
        if (size[i] > ms) {
            ms = size[i];
            mind = i;
        }

        cnt = cnt*size[i] / gcd(cnt,size[i]);

        for (int j = i+1; j <= pcnt; j++) {
            int g = gcd(size[i], size[j]);
            if (mod[i] % g != mod[j] % g) {
                printf("NO\n");
                return 0;
            }
        }
    }

    for (reach = mod[mind]; ; reach += size[mind]) {
        bool ok = true;
        for (int j = 1; j <= pcnt; j++) {
            if (reach % size[j] != mod[j]) {
                ok = false;
                break;
            }
        }
        if (ok == true) break; 
    }

    if (reach <= 0) {
        printf("NO\n");
        return 0;
    }
    else if (cnt != 2 && k >= reach && reach % 2 == k % 2) {
        printf("YES\n");
        return 0;
    }
    else if (cnt != 2 && k >= cnt-reach && (cnt-reach) % 2 == k % 2) {
        printf("YES\n");
        return 0;
    }
    else if (cnt == 2 && k == 1) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
        return 0;
    }
}