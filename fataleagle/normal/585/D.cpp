#include <bits/stdc++.h>

using namespace std;

int N;
int A[25][3];
unsigned char S1[1594323][13];
int V1[1594323][3];
unsigned char S2[1594323][13];
int V2[1594323][3];
unsigned char S0[13];
int V0[3];

void rec(int offs, int pos, int lim, unsigned char S[1594323][13], int V[1594323][3], int& cnt)
{
    if(pos==lim)
    {
        for(int i=0; i<13; i++)
            S[cnt][i]=S0[i];
        for(int i=0; i<3; i++)
            V[cnt][i]=V0[i];
        cnt++;
        return;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++) if(i!=j)
            V0[j]+=A[pos][j];
        S0[pos-offs]=i;
        rec(offs, pos+1, lim, S, V, cnt);
        for(int j=0; j<3; j++) if(i!=j)
            V0[j]-=A[pos][j];
    }
}

map<pair<int, int>, pair<int, int>> m;

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        for(int j=0; j<3; j++)
            scanf("%d", A[i]+j);
    int M=N/2;
    int cnt1=0, cnt2=0;
    rec(0, 0, M, S1, V1, cnt1);
    rec(M, M, N, S2, V2, cnt2);
    for(int i=0; i<cnt1; i++)
    {
        int d1=V1[i][0]-V1[i][1];
        int d2=V1[i][1]-V1[i][2];
        pair<int, int> q=make_pair(d1, d2);
        auto it=m.find(q);
        if(it!=m.end())
            it->second=max(it->second, make_pair(V1[i][0], i));
        else
            m[q]=make_pair(V1[i][0], i);
    }
    pair<int, pair<int, int>> ans=make_pair(-0x3f3f3f3f, make_pair(-1, -1));
    for(int i=0; i<cnt2; i++)
    {
        int d1=V2[i][0]-V2[i][1];
        int d2=V2[i][1]-V2[i][2];
        pair<int, int> q=make_pair(-d1, -d2);
        auto it=m.find(q);
        if(it!=m.end())
            ans=max(ans, make_pair(it->second.first+V2[i][0], make_pair(it->second.second, i)));
    }
    if(ans.second.first!=-1)
    {
        for(int i=0; i<M; i++)
        {
            if(S1[ans.second.first][i]!=0)
                printf("L");
            if(S1[ans.second.first][i]!=1)
                printf("M");
            if(S1[ans.second.first][i]!=2)
                printf("W");
            printf("\n");
        }
        for(int i=M; i<N; i++)
        {
            if(S2[ans.second.second][i-M]!=0)
                printf("L");
            if(S2[ans.second.second][i-M]!=1)
                printf("M");
            if(S2[ans.second.second][i-M]!=2)
                printf("W");
            printf("\n");
        }
    }
    else
        printf("Impossible\n");
    return 0;
}