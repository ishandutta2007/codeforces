#include <bits/stdc++.h>

using namespace std;

int N;
char S[200001];
int cnt[26];

int main()
{
    scanf("%s", S);
    N=strlen(S);
    for(int i=0; i<N; i++)
        cnt[S[i]-'a']++;
    vector<int> v;
    for(int i=0; i<26; i++) if(cnt[i]%2==1)
        v.push_back(i);
    for(int i=0; i<(int)v.size()-i-1; i++)
        cnt[v[i]]++, cnt[v[(int)v.size()-i-1]]--;
    for(int i=0; i<26; i++)
        for(int j=0; j<cnt[i]/2; j++)
            putchar('a'+i);
    for(int i=0; i<26; i++) if(cnt[i]%2==1)
        putchar('a'+i);
    for(int i=25; i>=0; i--)
        for(int j=0; j<cnt[i]/2; j++)
            putchar('a'+i);
    putchar('\n');
    return 0;
}