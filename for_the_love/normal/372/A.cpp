#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 555555;


int a[N];


int main(){
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int j = n / 2, ans = n;
    for (int i = n; i >= 1; i--){
        while (j >= 1 && a[j] * 2 > a[i]) j--;
        if (j){
            ans--;
            j--;
        }
    }
    printf("%d\n", ans);
}