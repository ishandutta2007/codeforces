#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long llong;

const llong MOD = 1000000007;

int n,k;
int step;

int LEAFOFFSET;
pair<int,int> IT[4000111];

int modval[1000111];

pair<int,int> MAX(pair<int,int> a,pair<int,int> b)
{
    if (a.first > b.first)
        return a;
    else
        return b;
}

pair<int,int> getMax(int L,int R)
{
    L += LEAFOFFSET;
    R += LEAFOFFSET;

    pair<int,int> ans = MAX(IT[L], IT[R]);

    while(R - L > 1)
    {
        if (L % 2 == 0)
            ans = MAX(ans, IT[L+1]);
        if (R % 2 == 1)
            ans = MAX(ans, IT[R-1]);

        L /= 2;
        R /= 2;
    }

    return ans;
}

/// SEQ WORK

vector< pair< pair<int,int>, int> > seqA, seqB;

void clearSeq()
{
    seqA.clear();
    seqB.clear();
}

void addSeq(int l, int r)
{
    int addMore = step - modval[l];

    if (addMore == step)
        addMore = 0;

    if (l + addMore <= r) ///Can go to safe place
    {
        if (addMore != 0)
        {
            seqA.push_back(make_pair(make_pair(modval[l], step-1),1));
        }

        l += addMore;

        int dist = r - l + 1;
        int fullHits = dist / step;

        seqA.push_back(make_pair(make_pair(0, step-1), fullHits));

        if (modval[r] != step-1)
        {
            seqA.push_back(make_pair(make_pair(0, modval[r]),1));
        }
    }
    else ///Just finish
    {
        seqA.push_back(make_pair(make_pair(modval[l], modval[r]),1));
    }
}

void logSeq()
{
    int i;

    for (i=0;i<seqA.size();i++)
    {
        seqB.push_back(seqA[i]);
    }
    seqA.clear();

    return;
}

llong countSeq()
{
    int i,j;
    int l,r;
    llong ans = 0, val;

    for (i=0;i<seqA.size();i++)
    {
        for (j=0;j<seqB.size();j++)
        {
            l = seqA[i].first.first;
            if (seqB[j].first.first > l)
                l = seqB[j].first.first;

            r = seqA[i].first.second;
            if (seqB[j].first.second < r)
                r = seqB[j].first.second;

            if (r >= l)
            {
                val = (llong)(r - l + 1) * (llong)seqA[i].second;
                if (val >= MOD)
                    val %= MOD;

                val *= (llong)seqB[j].second;

                ans += val;
                if (ans >= MOD)
                    ans %= MOD;
            }
        }
    }

    return ans;
}

///

llong solve(int L,int R)
{
    if (L >= R)
        return 0LL;

    pair<int,int> res = getMax(L, R);
    int ind = res.second;
    llong ans = solve(L, ind - 1) + solve(ind + 1, R);
    int i;

    //cout<<"Solving "<<L<<"~"<<R<<endl;

    clearSeq();
    addSeq(L, ind);
    logSeq();
    addSeq(ind, R);

    //cout<<"Intervals are "<<L<<"~"<<ind<<" and then "<<ind<<"~"<<R<<endl;

    /*cout<<"A:"<<endl;
    for (i=0;i<seqA.size();i++)
    {
        cout<<seqA[i].first.first<<"-"<<seqA[i].first.second<<" x"<<seqA[i].second<<endl;
    }

    cout<<endl<<"B:"<<endl;
    for (i=0;i<seqB.size();i++)
    {
        cout<<seqB[i].first.first<<"-"<<seqB[i].first.second<<" x"<<seqB[i].second<<endl;
    }*/

    llong times = countSeq() - 1;

    // cout<<"Counted "<<times<<" times for index "<<ind<<" and hence value "<<res.first<<endl;

    if (times < 0)
        times += MOD;

    ans += times * (llong)res.first;

    return ans % MOD;
}

int main()
{
    //freopen("test.txt","r",stdin);

    int i,j;

    scanf("%d %d",&n,&k);

    step = k - 1;

    LEAFOFFSET = 1;
    while(LEAFOFFSET < n)
        LEAFOFFSET *= 2;
    LEAFOFFSET--;

    modval[0] = 0;
    for (i=1;i<=n;i++)
    {
        modval[i] = modval[i-1] + 1;
        if (modval[i] == step)
            modval[i] = 0;
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&IT[i+LEAFOFFSET].first);
        IT[i+LEAFOFFSET].second = i;
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT[i] = MAX(IT[2*i], IT[2*i+1]);
    }

    printf("%lld\n",solve(1,n));

    return 0;
}