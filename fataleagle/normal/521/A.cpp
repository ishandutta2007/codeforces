#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N;
char S[100001];
map<char, int> freq;

int main()
{
    scanf("%d%s", &N, S);
    for(int i=0; i<N; i++)
        freq[S[i]]++;
    int maxi=0, nmaxi=0;
    for(auto& it: freq)
    {
        if(it.second>maxi)
            maxi=it.second, nmaxi=1;
        else if(it.second==maxi)
            nmaxi++;
    }
    int ret=1;
    for(int i=0; i<N; i++)
        ret=1LL*ret*nmaxi%MOD;
    printf("%d\n", ret);
    return 0;
}