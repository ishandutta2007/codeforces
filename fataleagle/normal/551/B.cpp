#include <bits/stdc++.h>

using namespace std;

int N, NB, NC;
char A[100001];
char B[100001];
char C[100001];
int cnt[26], cnt1[26], cnt2[26];

int main()
{
    scanf("%s%s%s", A, B, C);
    N=strlen(A);
    NB=strlen(B);
    NC=strlen(C);
    for(int i=0; i<N; i++)
        cnt[A[i]-'a']++;
    for(int i=0; i<NB; i++)
        cnt1[B[i]-'a']++;
    for(int i=0; i<NC; i++)
        cnt2[C[i]-'a']++;
    pair<int, pair<int, int>> ans=make_pair(0, make_pair(0, 0));
    for(int i=0; i<N; i++)
    {
        int maxC=0x3f3f3f3f;
        for(int j=0; j<26; j++)
        {
            if(cnt[j]<1LL*i*cnt1[j])
                goto fail;
            if(cnt2[j])
                maxC=min(maxC, (cnt[j]-i*cnt1[j])/cnt2[j]);
        }
        ans=max(ans, make_pair(i+maxC, make_pair(i, maxC)));
        fail:;
    }
    for(int i=0; i<ans.second.first; i++)
        for(int j=0; j<NB; j++)
            putchar(B[j]), cnt[B[j]-'a']--;
    for(int i=0; i<ans.second.second; i++)
        for(int j=0; j<NC; j++)
            putchar(C[j]), cnt[C[j]-'a']--;
    for(int i=0; i<26; i++)
        for(int j=0; j<cnt[i]; j++)
            putchar('a'+i);
    putchar('\n');
    return 0;
}