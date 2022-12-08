#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 101000;
const int MAXV = 101000;

int N, X;

bool app1[MAXV];
bool appa[MAXV];

int main() {
    scanf("%d%d", &N, &X);
    
    int ans = -1;
    for(int i = 0;i < MAXV;i++) {
        app1[i] = appa[i] = false;
    }
    for(int i = 0;i < N;i++) {
        int v;
        scanf("%d", &v);
        if(app1[v]) {
            ans = 0;
            break;
        }
        
        if(app1[v & X] || appa[v]) ans = 1;
        if(ans == -1 && appa[v & X]) ans = 2;
        
        app1[v] = true;
        appa[v & X] = true;
    }
    printf("%d\n", ans);
    return 0;
}