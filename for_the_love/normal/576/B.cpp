#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5 + 7;

int n, p[N], v[N];
vector <vector<int> > vec[N];
vector <pair<int, int> > ans;

void get_loop(int x){
    vector <int> tmp;
    while (!v[x]){
        tmp.push_back(x);
        v[x] = 1;
        x = p[x];
    }
    vec[tmp.size()].push_back(tmp);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &p[i]);
        if (p[i] == i){
            puts("YES");
            for (int j = 1; j <= n; j++)
            if (i != j) printf("%d %d\n", i, j);
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    if (!v[i]) get_loop(i);

    for (int i = n - 1; i >= 1; i--)
    if (vec[i].size()){
        for (int j = i + i; j <= n; j += i){
            for (int k = 0; k < vec[j].size(); k++)
                for (int x = 0; x < j; x++)
                    ans.push_back(make_pair(vec[i][0][x % i], vec[j][k][x]));
            vec[j].clear();
        }
    }
    if (vec[2].size()){
        ans.push_back(make_pair(vec[2][0][0], vec[2][0][1]));
        for (int i = 1; i < vec[2].size(); i++){
            ans.push_back(make_pair(vec[2][i][0], vec[2][i - 1][0]));
            ans.push_back(make_pair(vec[2][i][1], vec[2][i - 1][1]));
        }
    }

    if (ans.size() != n - 1){
        puts("NO");
        return 0;
    }

    puts("YES");
    printf("%d %d\n", ans[0].first, ans[0].second);
    for (int i = 1; i < ans.size(); i++){
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}