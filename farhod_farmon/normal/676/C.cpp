#include <bits/stdc++.h>

#define lli long long int
#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

int n, k, cnt, ans;
int used[200];
string s;

void add(char x)
{
    cnt = 0;
    used[x - 'a']++;
    for(int i = 0; i < 26; i++)
        cnt = max(cnt, used[i]);
}

void sub(char x)
{
    cnt = 0;
    used[x - 'a']--;
    for(int i = 0; i < 26; i++)
        cnt = max(cnt, used[i]);
}

int main()
{
    cin >> n >> k >> s;
    for(int i = 0, j = 0; i < s.size(); i++){
        add(s[i]);
        while(i - j - cnt + 1 > k)
            sub(s[j++]);
        ans = max(ans, i - j + 1);
    }
    cout << ans << endl;
}