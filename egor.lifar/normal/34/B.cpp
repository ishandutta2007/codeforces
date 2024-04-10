#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <string.h>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;



int main() {
    int n, m;
    int a[100000];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    int k = 0;
    int s = 0;
    for(int i = 0; i < n; i++){
        if(a[i] < 0 && k < m){
            k++;
            s += abs(a[i]);
        }
        else {
            break;
        }
    }
    printf("%d\n", s);
    return 0;
}