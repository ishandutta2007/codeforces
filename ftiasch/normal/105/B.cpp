#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 8;

int n, k, a, b[N], l[N];
double result;

void dfs(int i, int k){
    if(i < n){
        for(int c = 0; c <= k; ++ c){
            int tmp = l[i];
            l[i] = min(l[i] + 10 * c, 100);
            dfs(i + 1, k - c);
            l[i] = tmp;
        }
    }else{
        double newResult = 0.0;
        for(int mask = 0; mask < (1 << n); ++ mask){
            int vote = 0, sumB = 0;
            double p = 1.0;
            for(int j = 0; j < n; ++ j){
                if(mask & (1 << j)){
                    vote += 1;
                    p *= l[j] / 100.0;
                }else{
                    sumB += b[j];
                    p *= 1 - l[j] / 100.0;
                }
            }
            if(vote * 2 > n){
                newResult += p;
            }else{
                newResult += p * (double)a / (a + sumB);
            }
        }
        result = max(result, newResult);
    }
}

int main(){
    scanf("%d%d%d", &n, &k, &a);
    for(int i = 0; i < n; ++ i){
        scanf("%d%d", b + i, l + i);
    }
    result = 0;
    dfs(0, k);
    printf("%.8f\n", result);
    return 0;
}