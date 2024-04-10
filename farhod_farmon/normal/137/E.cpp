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

int t[4 * N];
int a[N];
string s;

int f(char c)
{
    if('A' <= c && c <= 'Z')
        c = c - 'A' + 'a';
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return -1;
    return 2;
}

void build(int x, int l, int r)
{
    if(l == r){
        t[x] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(x * 2, l, m);
    build(x * 2 + 1, m + 1, r);
    t[x] = max(t[x * 2], t[x * 2 + 1]);
}

int get(int x, int l, int r, int tl, int tr, int g)
{
    if(tl > tr || t[x] < g)
        return -1;
    if(l == r)
        return l;
    int m = (l + r) / 2,
        j = -1;
    if(t[x * 2 + 1] >= g)
        j = get(x * 2 + 1, m + 1, r, max(m + 1, tl), tr, g);
    else if(t[x * 2] >= g)
        j = get(x * 2, l, m, tl, min(m, tr), g);
    return j;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> s;
    s = "#" + s;
    int n = s.size() - 1;
    for(int i = 1; i <= n; i++)
        a[i] = a[i - 1] + f(s[i]);
    build(1, 1, n);
    int len = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        int j = get(1, 1, n, i, n, a[i - 1]);
        if(j == -1)
            continue;
        if(j - i + 1 > len){
            len = j - i + 1;
            cnt = 1;
        }
        else if(j - i + 1 == len)
            cnt++;
    }
    if(cnt == 0)
        cout << "No solution" << endl;
    else
        cout << len << " " << cnt << endl;
}