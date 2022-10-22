#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int j=0;
    for(int i=0; i < n-1; ++i){
        j += i+1;
        j %= n;
        printf("%d ", j+1);
    }
    return 0;
}