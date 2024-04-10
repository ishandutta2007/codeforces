#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= (n + 1) / 2; i++){
       if(i != n + 1 - i){
       	printf("%d %d ", i, n + 1 - i);
       } else {
       	printf("%d", i);
       }

    }
    printf("\n");
    


    return 0;
}