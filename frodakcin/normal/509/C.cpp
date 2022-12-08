#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

void up(int * a, int& l, int d, int& sum) {
    if(d == 0) return;
    for(int j = 0;;j++) {
        if(d > 9 - a[j]) d -= (9-a[j]), sum += (9-a[j]), a[j] = 9;
        else {
            a[j] += d;
            sum += d;
            if(j+1 > l) l = j+1;
            break;
        }
    }
}

const int MAXN = 340;
int N, b[MAXN];
const int MAXL = 5e4;
int a[MAXL], l;
void ans() {
    for(int i = l-1;i >= 0;i--) printf("%d", a[i]);
    printf("\n");
}

int main() {
    scanf("%d", &N);
    for(int i = 0;i < N;i++) scanf("%d", b + i);
    
    for(int i = 0;i < MAXL;i++) a[i] = 0;
    for(int i = 0, sum = 0;i < N;i++) {
        if(sum < b[i])
        {
            up(a, l, b[i] - sum, sum);
        }
        else 
        {
            int d = sum - b[i];
            for(int j = 0;j <= l;j++) {
                if(j == l) l++;
                if(a[j] == 9 or d >= 0) {
                    d -= a[j];
                    sum -= a[j];
                    a[j] = 0;
                } else {
                    a[j]++, sum++, d++;
                    up(a, l, -d, sum);
                    break;
                }
            }
        }
        assert(sum == b[i]);
        ans();
    }
    
    return 0;
}