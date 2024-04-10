#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int N = 1e6 + 7;


struct PNode{
    int x, y, b;
    bool operator < (const PNode &A)const{
        if (x / 1000 == A.x / 1000){
            if (x / 1000 & 1)
                return y < A.y;
            else return A.y < y;
        }
        return x < A.x;
    }
} p[N];

int n;

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d%d", &p[i].x, &p[i].y);
        p[i].b = i + 1;
    }
    sort(p, p + n);
    for (int i = 0; i < n; i++)
        printf("%d ", p[i].b);
}