#include <bits/stdc++.h>

using namespace std;

const int UNKNOWN=0x7FFFFFFF;
int N, K;
int A[100000];
bool seen[100000];
int nbad, last;

void fail()
{
    printf("Incorrect sequence\n");
    exit(0);
}

void fix_bad(int pos, int cur)
{
    if(cur-last-1<nbad)
        fail();
    if(nbad==0)
        return;
    if(last<=0 && cur<=0)
    {
        for(int i=0; i<=nbad; i++)
            if(0<=pos-i*K && pos-i*K<N)
                A[pos-i*K]=cur-i;
    }
    else if(last>=0 && cur>=0)
    {
        for(int i=1; i<=nbad+1; i++)
            if(0<=pos-i*K && pos-i*K<N)
                A[pos-i*K]=last-i+nbad+1;
    }
    else
    {
        vector<int> toadd;
        toadd.push_back(0);
        int n=1;
        while((int)toadd.size()<nbad)
        {
            if(last<n && n<cur)
                toadd.push_back(n);
            if((int)toadd.size()>=nbad)
                break;
            if(last<-n && -n<cur)
                toadd.push_back(-n);
            n++;
        }
        sort(toadd.rbegin(), toadd.rend());
        for(int i=1; i<=nbad; i++)
            if(0<=pos-i*K && pos-i*K<N)
                A[pos-i*K]=toadd[i-1];
    }
}

void dfs(int u)
{
    if(u>=N)
    {
        if(nbad)
            fix_bad(u, 1050000000);
        return;
    }
    seen[u]=true;
    if(A[u]==UNKNOWN)
        nbad++;
    else
    {
        fix_bad(u, A[u]);
        nbad=0;
        last=A[u];
    }
    dfs(u+K);
}

int main()
{
    scanf("%d%d", &N, &K);
    char c;
    for(int i=0; i<N; i++)
    {
        scanf(" %c", &c);
        if(c=='?')
            A[i]=UNKNOWN;
        else
        {
            ungetc(c, stdin);
            scanf("%d", A+i);
        }
    }
    for(int i=0; i<N; i++)
        if(!seen[i])
        {
            last=-1050000000;
            nbad=0;
            dfs(i);
        }
    for(int i=0; i<N; i++)
        printf("%d%c", A[i], " \n"[i==N-1]);
    return 0;
}