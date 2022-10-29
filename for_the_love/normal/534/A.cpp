#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef long double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 2e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


vector <int> ans;


int main(){
    int n;
    cin >> n;
    if (n & 1){
        for (int i = 1; i <= n; i += 2)
        if (!ans.size() || abs(ans[ans.size() - 1] - i) > 1)
            ans.push_back(i);
        for (int i = 2; i <= n; i += 2)
        if (!ans.size() || abs(ans[ans.size() - 1] - i) > 1)
            ans.push_back(i);
    }else{
        for (int i = 2; i <= n; i += 2)
        if (!ans.size() || abs(ans[ans.size() - 1] - i) > 1)
            ans.push_back(i);
        for (int i = 1; i <= n; i += 2)
        if (!ans.size() || abs(ans[ans.size() - 1] - i) > 1)
            ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}