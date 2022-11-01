#include <bits/stdc++.h>

using namespace std;

int N, M;

struct state
{
    int comps[5], pre;
    inline bool operator== (const state& other) const
    {
        if(pre!=other.pre)
            return false;
        for(int i=0; i<N; i++) if(comps[i]!=other.comps[i])
            return false;
        return true;
    }
};

namespace std
{
    template<>
    struct hash<state>
    {
        size_t operator() (const state& st) const
        {
            int ret=0;
            for(int i=0; i<N; i++)
            {
                ret*=10;
                ret+=st.comps[i];
            }
            return ret*32+st.pre;
        }
    };
}

inline state transition(state st, int mask)
{
    for(int i=0; i<N; i++) if(!((st.pre>>i)&1) && ((mask>>i)&1))
        st.comps[i]++;
    st.pre=mask;
    return st;
}

unordered_map<state, int> dp[20];
int A[5];
int B[20];
int cache[1<<5];
char ans[5][20];

int get(int mask)
{
    int last=0;
    int ret=0;
    for(int i=0; i<N; i++)
    {
        if(((mask>>i)&1) && last==0)
            ret++;
        last=(mask>>i)&1;
    }
    return ret;
}

int solve(int col, state cur)
{
    if(col==M)
    {
        for(int i=0; i<N; i++) if(cur.comps[i]!=A[i])
            return -1;
        return 0;
    }
    if(dp[col].count(cur))
        return dp[col][cur];
    int& ret=dp[col][cur];
    ret=-1;
    for(int i=0; i<(1<<N); i++) if(cache[i]==B[col])
    {
        if(solve(col+1, transition(cur, i))!=-1)
        {
            ret=i;
            break;
        }
    }
    return ret;
}

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<M; i++)
        scanf("%d", B+i);
    state initial;
    for(int i=0; i<N; i++)
        initial.comps[i]=0;
    initial.pre=0;
    for(int i=0; i<(1<<N); i++)
        cache[i]=get(i);
    assert(solve(0, initial)!=-1);
    for(int i=0; i<M; i++)
    {
        int cur=dp[i][initial];
        initial=transition(initial, dp[i][initial]);
        for(int j=0; j<N; j++)
        {
            if((cur>>j)&1)
                ans[j][i]='*';
            else
                ans[j][i]='.';
        }
    }
    for(int i=0; i<N; i++, putchar('\n'))
        for(int j=0; j<M; j++)
            putchar(ans[i][j]);
    return 0;
}