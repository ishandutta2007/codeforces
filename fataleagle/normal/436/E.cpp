#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int N, W;
int nA, nB;
long long bestA[600001];
long long bestB[600001];
char ans[300001];

struct level
{
    int a1, a2, i;
} A[300000], B[300000];

struct cmp
{
    bool operator() (const level& a, const level& b) const
    {
        if(a.a1!=b.a1)
            return a.a1<b.a1;
        if(a.a2!=b.a2)
            return a.a2<b.a2;
        return a.i<b.i;
    }
};

struct cmp2
{
    bool operator() (const level& a, const level& b) const
    {
        if(a.a2!=b.a2)
            return a.a2<b.a2;
        if(a.a1!=b.a1)
            return a.a1<b.a1;
        return a.i<b.i;
    }
};

int n;
pair<int, int> tmp[600000];

void solveA(int stop)
{
    if(stop==0)
        return;
    if(stop==-1)
    {
        n=0;
        for(int i=0; i<nA; i++)
        {
            tmp[n++]={A[i].a1, A[i].i};
            tmp[n++]={A[i].a2-A[i].a1, A[i].i};
        }
        sort(tmp, tmp+n);
    }
    bestA[0]=0;
    for(int i=1; i<=n; i++)
    {
        bestA[i]=bestA[i-1]+tmp[i-1].first;
        if(stop!=-1)
            ans[tmp[i-1].second]++;
        if(stop==i)
            break;
    }
}

void solveB(int stop)
{
    if(stop==0)
        return;
    if(stop==-1)
        sort(B, B+nB, cmp2());
    set<level, cmp> min1;
    set<level, cmp2> min2;
    for(int i=0; i<nB; i++)
    {
        min1.insert(B[i]);
        min2.insert(B[i]);
    }
    set<pair<int, int>> mind;
    long long sum=0;
    bestB[0]=0;
    for(int i=0; i<nB; i++)
    {
        bestB[i*2+1]=sum+min1.begin()->a1;
        if(i>0)
            bestB[i*2+1]=min(bestB[i*2+1], sum+mind.begin()->first+min2.begin()->a2);
        if(stop==i*2+1)
        {
            for(int j=0; j<i; j++)
                ans[B[j].i]='2';
            if(sum+min1.begin()->a1<sum+mind.begin()->first+min2.begin()->a2)
                ans[min1.begin()->i]='1';
            else
            {
                ans[mind.begin()->second]='1';
                ans[min2.begin()->i]='2';
            }
            break;
        }
        sum+=B[i].a2;
        bestB[i*2+2]=sum;
        if(stop==i*2+2)
        {
            for(int j=0; j<=i; j++)
                ans[B[j].i]='2';
            break;
        }
        min1.erase(B[i]);
        min2.erase(B[i]);
        mind.insert(make_pair(B[i].a1-B[i].a2, B[i].i));
    }
}

int main()
{
    scanf("%d%d", &N, &W);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        if(a*2<=b)
            A[nA++]=(level){a, b, i};
        else
            B[nB++]=(level){a, b, i};
    }
    memset(bestA, 0x3f, sizeof bestA);
    memset(bestB, 0x3f, sizeof bestB);
    solveA(-1);
    solveB(-1);
    pair<long long, pair<int, int>> rans=min(make_pair(bestA[W], make_pair(W, 0)), make_pair(bestB[W], make_pair(W, 1)));
    for(int i=0; i<=W; i++)
        rans=min(rans, {bestA[i]+bestB[W-i], {i, 2}});
    memset(ans, '0', sizeof ans);
    if(rans.second.second==0 || rans.second.second==2)
        solveA(rans.second.first);
    if(rans.second.second==1)
        solveB(rans.second.first);
    if(rans.second.second==2)
        solveB(W-rans.second.first);
    printf("%lld\n", rans.first);
    printf("%.*s\n", N, ans);
    return 0;
}