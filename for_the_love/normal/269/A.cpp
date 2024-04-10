#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct tnode{
    long long k, a;
} t[100005];
long long n, i, tmp;
int cmp(tnode a, tnode b){return a.k < b.k;}
int main(){
    cin >> n;
    for (i = 1; i <= n; i++) cin >> t[i].k >> t[i].a;
    sort(t + 1, t + n + 1, cmp);
    for (i = 2; i <= n; i++){
        tmp = 0;
        if (2 * (t[i].k - t[i - 1].k) <= 30){
            tmp = t[i - 1].a / (1 << (2 * (t[i].k - t[i - 1].k)));
            if (t[i - 1].a % (1 << (2 * (t[i].k - t[i - 1].k))) != 0) tmp++;
        }
        t[i].a = max(t[i].a, tmp);
    }
    while (t[n].a > 4){
        if (t[n].a % 4 == 0) t[n].a /= 4; else t[n].a = t[n].a / 4 + 1;
        t[n].k++;
    }
    cout << t[n].k + 1 << endl;
}