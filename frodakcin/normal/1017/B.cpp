#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXN = 101000;

int N;
bool a[MAXN], b[MAXN];

ll tf, ff, ft, tt;

int main() {
    scanf("%d", &N);
    
    char ip;
    for(int i = 0;i < N;i++) {
        scanf(" %c", &ip);
        a[i] = ip == '1';
    }
    for(int i = 0;i < N;i++) {
        scanf(" %c", &ip);
        b[i] = ip == '1';
    }
    tf = ff = ft = tt = 0;
    for(int i = 0;i < N;i++) {
        if(a[i] && b[i]) tt ++;
        if(a[i] && !b[i]) tf ++;
        if(!a[i] && b[i]) ft ++;
        if(!a[i] && !b[i]) ff ++;
    }
    printf("%I64d", (tf * (ff + ft) + ff * (tt)));
    return 0;
}