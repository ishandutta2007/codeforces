#include <cstdio>  
#include <iostream>  
#include <cstring>  
#include <algorithm>  
#include <map>  
#include <vector>  
#define mp make_pair  
#define st first  
#define dst second  
using namespace std;  
  
int f[2010][3][9][715], n;//0~8   
map<vector<int>, int> M;  
vector<int> load[715];  
pair<int, int> p[2010];  
bool cmp(int a, int b) {  
    return a > b;  
}  
int dfs(int cur, int op, int fl, int key) {  
    if (cur == n + 1 && key == 0)  
        return 0;  
    if (fl == -1 || fl == 9)  
        return (int)1e9;  
    if (f[cur][op][fl][key])  
        return f[cur][op][fl][key];  
    int &ans = f[cur][op][fl][key];  
    vector<int> tmp = load[key];  
    int lv = 0;  
    for (int i = 0; i < (int)tmp.size(); ++i)  
        if (tmp[i] == fl + 1)  
            tmp[i]= 0, ++lv;  
    if (lv) {//   
        sort(tmp.begin(), tmp.end(), cmp);  
        return dfs(cur, 0, fl, M[tmp]) + lv;  
    }  
    if (cur <= n && p[cur].st == fl + 1 && tmp[3] == 0) {//   
        tmp[3] = p[cur].dst;  
        sort(tmp.begin(), tmp.end(), cmp);  
        return ans = dfs(cur + 1, 0, fl, M[tmp]) + 1;  
    }  
    //   
    if (op == 0)  //   
        return ans = min(dfs(cur, 1, fl + 1, key), dfs(cur, 2, fl - 1, key)) + 1;  
    else if (op == 1) //   
        return ans = dfs(cur, 1, fl + 1, key) + 1;  
    else   
        return ans = dfs(cur, 2, fl - 1, key) + 1;  
      
}  
int main() {  
    ios::sync_with_stdio(0);  
    int cnt = -1;  
    for (int i = 0; i <= 9; ++i) //    
        for (int j = 0; j <= i; ++j)  
            for (int k = 0; k <= j; ++k)  
                for (int h = 0; h <= k; ++h) {  
                    load[++cnt].push_back(i);  
                    load[cnt].push_back(j);  
                    load[cnt].push_back(k);  
                    load[cnt].push_back(h);  
                    M[load[cnt]] = cnt;  
//                  puts("%");   
                }  
//  cout << cnt;//715   
    cin >> n;  
    for (int i = 1; i <= n; ++i)  
        cin >> p[i].st >> p[i].dst;  
    cout << dfs(1, 1, 0, 0) << endl;  
    return 0;  
}