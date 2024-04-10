#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

int n;
int ans1, ans2;
string s;

int get(int x)
{
    while(x + 1 < n && s[x + 1] != '_' && s[x + 1] != '(' && s[x + 1] != ')')
        x++;
    return x;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> s;
    int cur = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '_')
            continue;
        if(s[i] == '('){
            cur++;
            continue;
        }
        if(s[i] == ')'){
            cur--;
            continue;
        }
        int j = get(i);
        if(j - i + 1 > ans1 && cur == 0)
            ans1 = j - i + 1;
        if(cur > 0)
            ans2++;
        i = j;
    }
    cout << ans1 << " " << ans2 << endl;
}