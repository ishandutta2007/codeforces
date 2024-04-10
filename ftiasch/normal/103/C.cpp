#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1111;

long long n, k, x[N];
int p;

int main(){
    cin >> n >> k >> p;
    for(int i = 1; i <= p; ++ i){
        cin >> x[i];
    }
    if(k == 0){
        for(int i = 1; i <= p; ++ i){
            printf(".");
        }
        printf("\n");
        return 0;
    }
    long long last = n + 1;
    if(n & 1){
        k -= 1;
        n -= 1;
        last = n + 1;
    }
    if(k == 0){
        for(int i = 1; i <= p; ++ i){
            if(x[i] < last){
                printf(".");
            }else{
                printf("X");
            }
        }
        printf("\n");
        return 0;
    }
    if(2 * k > n){
        long long temp = 2 * k - n;
        n -= temp;
        last = n + 1; 
    }
    long long first = n - 2 * (k - 1);
    for(int i = 1; i <= p; ++ i){
        if(x[i] < first){
            printf(".");
        }else if(x[i] == first){
            printf("X");
        }else if(x[i] >= last){
            printf("X");
        }else{
            printf("%c", (x[i] - first) & 1? '.': 'X');
        }
    }
    printf("\n");
    return 0;
}