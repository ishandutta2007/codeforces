#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
const long long INF=0x3f3f3f3f3f3f3f3fLL;
int N, H, W;
char S[500001];
long long LR[500001];
long long UD[500001];

bool computeArray(long long A[], char L, char R, int M)
{
    map<int, int> firstReach;
    int net=0, mini=0, maxi=0;
    bool ret=false;
    for(int i=0; i<N; i++)
    {
        net+=S[i]==R;
        net-=S[i]==L;
        if(!firstReach.count(net))
            firstReach[net]=i+1;
        mini=min(mini, net);
        maxi=max(maxi, net);
    }
    for(int i=0; i<M; i++)
    {
        int toLeft=-(i+1);
        int toRight=M-i;
        long long timeLeft, timeRight;
        if(toLeft<mini)
            timeLeft=INF;
        else
            timeLeft=firstReach[toLeft];
        if(net<0 && timeLeft==INF)
        {
            int x=(abs(toLeft-mini)+abs(net)-1)/abs(net);
            assert(toLeft-1LL*x*net>=mini);
            timeLeft=1LL*x*N+firstReach[toLeft-1LL*x*net];
        }
        if(toRight>maxi)
            timeRight=INF;
        else
            timeRight=firstReach[toRight];
        if(net>0 && timeRight==INF)
        {
            int x=(abs(toRight-maxi)+abs(net)-1)/abs(net);
            assert(toRight-1LL*x*net<=maxi);
            timeRight=1LL*x*N+firstReach[toRight-1LL*x*net];
        }
        A[i]=min(timeLeft, timeRight);
        if(A[i]==INF)
            ret=true;
    }
    return ret;
}

int main()
{
    scanf("%d%d%d", &N, &H, &W);
    scanf("%s", S);
    bool a=computeArray(LR, 'L', 'R', W);
    bool b=computeArray(UD, 'U', 'D', H);
    if(a && b)
        printf("-1\n");
    else
    {
        int cnt[2]={0, 0};
        vector<pair<long long, int>> all;
        for(int i=0; i<W; i++)
            all.push_back({LR[i], 0});
        for(int i=0; i<H; i++)
            all.push_back({UD[i], 1});
        sort(all.rbegin(), all.rend());
        int ans=0;
        for(auto& it: all)
        {
            cnt[it.second]++;
            ans=(ans+1LL*it.first%MOD*cnt[it.second^1])%MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}