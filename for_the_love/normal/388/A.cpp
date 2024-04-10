#pragma  comment(linker, "/STACK:36777216")
#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;

int a[N], c[N];
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++){
        int flag = 0;
        for (int j = 0; j < cnt; j++)
        if (c[j] <= a[i]){
            c[j]++;
            flag = 1;
            break;
        }
        if (!flag) c[cnt++] = 1;
    }
    cout << cnt << endl;
}