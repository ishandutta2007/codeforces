#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const DB eps = 1e-6;
const int N = 1e2 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;



int main(){
    int n;
    string s;
    scanf("%d", &n);
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    if (s[i] == 'x') cnt++;
    int ans = 0;
    for (int i = 0; i < n; i++)
    if (s[i] == 'x' && cnt > n / 2){
        cnt--;
        s[i] = 'X';
        ans++;
    }else if (s[i] == 'X' && cnt < n / 2){
        cnt++;
        s[i] = 'x';
        ans++;
    }
    cout << ans << endl;
    cout << s << endl;
}