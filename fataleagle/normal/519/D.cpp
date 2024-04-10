#include <bits/stdc++.h>

using namespace std;

int N;
int W[26];
char S[100002];
long long sum[100001];
map<long long, int> cnt[26];

int main()
{
    for(int i=0; i<26; i++)
        scanf("%d", W+i);
    scanf("%s", S+1);
    N=strlen(S+1);
    for(int i=1; i<=N; i++)
        sum[i]=sum[i-1]+W[S[i]-'a'];
    long long ans=0;
    for(int i=1; i<=N; i++)
    {
        ans+=cnt[S[i]-'a'][sum[i-1]];
        cnt[S[i]-'a'][sum[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}