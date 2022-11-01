#include <bits/stdc++.h>

using namespace std;

int N;
int A[200000];
map<int, int> cnt;

int main()
{
    int mini=0x3f3f3f3f, maxi=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i), mini=min(mini, A[i]), maxi=max(maxi, A[i]);
    int diff=maxi-mini;
    long long ans=0;
    for(int i=0; i<N; i++)
        ans+=cnt[A[i]+diff], ans+=(A[i]+diff==A[i]-diff)?0:cnt[A[i]-diff], cnt[A[i]]++;
    printf("%d %lld\n", diff, ans);
    return 0;
}