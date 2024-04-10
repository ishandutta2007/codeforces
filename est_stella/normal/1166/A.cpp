#include<bits/stdc++.h>
using namespace std;

int n, ans;
int cnt[30];

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;

        cnt[s[0]-'a']++;
    }

    for(int i=0; i <= 'z'-'a'; i++)
    {
        ans += cnt[i]/2 * (cnt[i]/2 - 1) / 2 + (cnt[i]-cnt[i]/2) * (cnt[i] - cnt[i]/2 - 1) / 2;
    }

    printf("%d", ans);
}