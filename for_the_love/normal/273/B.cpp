#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct tnode{
    int a, b;
} t[200015];

int i, j, k, n, num;
long long m, ans;
int cmp(tnode a, tnode b){
    if (a.a < b.a) return 1;
    if (a.a == b.a && a.b < b.b) return 1;
    return 0;
}
int main(){
    cin >> n;
    for (i = 1; i <= n + n; i++){
        cin >> t[i].a;
        if (i == n || i == n + n) t[i].b = n; else t[i].b = i % n;
    }
    cin >> m;
    sort(t + 1, t + n + n + 1, cmp);
    ans = 1;
    i = 1;
    while (i <= n + n){
        j = i + 1;
        num = 0;
        while(t[j].a == t[i].a){
            if (t[j].b == t[j - 1].b) num++;
            j++;
        }
        for (k = 1; k <= j - i; k++){
            if (k % 2 == 0 && num){
                num--;
                ans = (ans * k / 2) % m;
            }else ans = (ans * k) % m;
        }
        i = j;
    }
    cout << ans << endl;
}