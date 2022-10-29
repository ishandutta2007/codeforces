#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n, s, t, i, a[100005];
int main(){
    scanf("%d%d%d", &n, &s, &t);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (s == t){
        cout << 0 << endl;
        return 0;
    }
    for (i = 1; i <= n; i++){
        s = a[s];
        if (s == t){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}