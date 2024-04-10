#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 100100;

using namespace std;

int n, ans, all;
char c[N];
int used[200];
bool us[200];

void add(int x)
{
    if(used[c[x]] == 0){
        all--;
    }
    used[c[x]]++;
}

void sub(int x)
{
    used[c[x]]--;
    if(used[c[x]] == 0)
        all++;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i];
        if(!us[c[i]]){
            us[c[i]] = true;
            all++;
        }
    }
    ans = n;
    add(1);
    for(int i = 1, j = 1; i <= n; i++){
        while(all && j + 1 <= n)
            add(++j);
        if(!all)
            ans = min(ans, j - i + 1);
        sub(i);
    }
    cout << ans << endl;
}