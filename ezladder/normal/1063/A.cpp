#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m;
int sx, sy;
int k1, k2;
char a[2002][2002];
pair<int, int> dp[2002][2002];
bool was[2002][2002];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool check(string s){
    for (int i = 0; i < s.size() / 2; i++) if (s[i] != s[(int)s.size() - i - 1]) return 0;
        return 1;
}

int main(){
    srand(time(NULL));
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s >> s;
    sort(all(s));
    cout << s;
    exit(0);

}