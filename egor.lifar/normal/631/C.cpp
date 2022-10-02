#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>


using namespace std;


int n, m;
int a[200001];
int f[200001];
int t[200001];
int r[200001];
int b[200001];


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int st = 0;
    for (int i = 0; i < m; i++) {
        int t1, r1;
        scanf("%d %d", &t1, &r1);
        r1--;
        while (st > 0 && r1 >= r[st - 1]) {
            st--;
        }
        t[st] = t1;
        r[st] = r1;
        st++;
    } 
    int bl = 0;
    int br = r[0] + 1;
    r[st] = -1;
    st++;
    for (int i = 0; i < br; i++) {
        b[i] = a[i];
    } 
    sort(b, b + br);
    for (int i = 1; i <= st; i++) {
        for (int j = r[i - 1]; j > r[i]; j--) {
            a[j] = (t[i - 1] == 1 ? b[--br]: b[bl++]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}