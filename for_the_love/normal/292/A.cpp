#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, t, c, last, ans, i;
int main(){
    scanf("%d", &n);
    last = 0;
    for (i = 1; i <= n; i++){
        scanf("%d%d", &t, &c);
        if (t >= last){
            ans = max(ans, c);
            last = t + c;
        }
        else{
            last = last + c;
            ans = max(ans, last - t);
        }
    }
    printf("%d %d\n", last, ans);

}