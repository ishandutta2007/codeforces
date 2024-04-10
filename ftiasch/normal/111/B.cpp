#include <cstdio>
#include <cstring>

using namespace std;

const int N = 111111;

int n, last[N];

int main(){
    memset(last, 0, sizeof(last));
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        int x, y;
        scanf("%d%d", &x, &y);
        int res = 0;
        for(int d = 1; d * d <= x; ++ d){
            if(x % d == 0){
                if(i - last[d] > y){
                    res += 1;
                }
                last[d] = i;
                if(d * d != x){
                    int dd = x / d;
                    if(i - last[dd] > y){
                        res += 1;
                    }
                    last[dd] = i;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}