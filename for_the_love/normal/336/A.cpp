#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int x, y;
int main(){
    scanf("%d%d", &x, &y);
    if (x > 0){
        if (y > 0) printf("%d %d ", 0, abs(x) + y);
        else printf("%d %d ", 0, -(abs(x) + abs(y)));
        printf("%d %d ", abs(y) + x, 0);
    }else{
        printf("%d %d ", x - abs(y), 0);
        if (y > 0) printf("%d %d ", 0, abs(x) + y);
        else printf("%d %d ", 0, -(abs(x) + abs(y)));
    }


}