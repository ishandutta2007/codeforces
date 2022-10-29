#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
const int MOD = 1e9 + 7;
int p, k, cnt, v[N], num[N];

void dfs(int x, int st){
    int cnt = 1;
    while (1ll * k * x % p != st){
        x = 1ll * k * x % p;
        v[x] = 1;
        cnt++;
    }
    num[cnt]++;
}

bool check(int x){
    for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
    return 1;
}
vector <int> vec;

int main(){
    scanf("%d%d", &p, &k);
    if (k == 0){
        long long ans = 1;
        for (int i = 1; i < p; i++){
            ans *= p;
            ans %= MOD;
        }
        printf("%d\n", (int)ans);
        return 0;
    }
    for (int i = 0; i < p; i++)
    if (!v[i]) dfs(i, i);

    for (int i = 1; i <= p; i++)
    if (num[i]) vec.push_back(i);

    //cout << vec.size() << endl;
    long long ans = 1;
    for (int i = 0; i < vec.size(); i++){
        long long t = 0;
        for (int j = 0; j < vec.size() && 1ll * vec[j] * vec[j] <= vec[i]; j++) if (vec[i] % vec[j] == 0){
            int a = vec[i] / vec[j];
            int b = vec[j];
            t += 1ll * a * num[a];
            if (a != b) t += 1ll * b * num[b];
            t %= MOD;
        }
        for (int j = 0; j < num[vec[i]]; j++){
            ans *= t;
            ans %= MOD;
        }
    }
    printf("%d\n", (int)ans);
}