#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5 + 7;
bool v[N];
int n;
vector <int> ans;
int main(){
    scanf("%d", &n);
    for (int i = 2; i <= n; i++){
        if (!v[i]){
            for (int j = i + i; j <= n; j += i)
                v[j] = 1;
            for (int j = i; j <= n; j *= i)
                ans.push_back(j);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
}