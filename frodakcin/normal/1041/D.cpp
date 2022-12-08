#include <iostream>
#include <cstdio>

#include <utility>

using namespace std;

typedef pair<int, int> pii;

const int MAXN = 200000 + 10;
const int MAXH = 1000000000 + 100;

int N, H;
pii s[MAXN];
int psm[MAXN];

int main() {
    scanf("%d%d", &N, &H);
    
    for(int i = 0;i < N;i++) scanf("%d%d", &s[i].first, &s[i].second);
    
    psm[0] = 0;
    for(int i = 1;i < N;i++) psm[i] = psm[i - 1] + s[i].first - s[i - 1].second;
    
    int ans = 0, t;
    
    for(int i = 0, j = 0;i < N;i++) {
        while(j + 1 < N and psm[j + 1] - psm[i] < H) j++;
        if((t = s[j].second - s[i].first + H - (psm[j] - psm[i])) > ans) ans = t;
    }
    
    printf("%d\n", ans);
    
    return 0;
}