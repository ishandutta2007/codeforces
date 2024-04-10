#include <iostream>
#include <cstdio>

#include <string>
#include <stack>

using namespace std;

const int MAXN = 202000;

int N, K;

bool seq[MAXN];
int cor[MAXN];
bool rem[MAXN];
int pos[MAXN], posc;

int main() {
    
    scanf("%d%d", &N, &K);
    
    char c;
    for(int i = 0;i < N;i++) {
        scanf(" %c", &c);
        seq[i] = c == '(';
        rem[i] = false;
    }
    
    posc = 0;
    for(int i = 0;i < N;i++) {
        if(seq[i]) pos[posc++] = i;
        if(!seq[i])
        {
            cor[i] = pos[--posc];
            cor[cor[i]] = i;
        }
    }
    
    int k = 0;
    for(int i = 0;i < N and k < (N - K);i++) {
        if(!rem[i]) {
            rem[i] = true;
            rem[cor[i]] = true;
            k += 2;
        }
    }
    
    for(int i = 0;i < N;i++) {
        if(!rem[i]) printf("%c", (seq[i] ? '(' : ')'));
    }
    printf("\n");
    
    return 0;
}