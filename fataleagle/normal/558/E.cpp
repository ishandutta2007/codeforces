#include <iostream>
#include <cstdio>

using namespace std;

int N, Q;
char S[100002];
int cnt[26];
int tmp[26];

struct node
{
    int lazy;
    int cnt[26];
} seg[262144];

void init(int idx, int begin, int end)
{
    seg[idx].lazy=-1;
    if(begin==end)
        seg[idx].cnt[S[begin]-'a']++;
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        for(int i=0; i<26; i++)
            seg[idx].cnt[i]=seg[idx*2].cnt[i]+seg[idx*2+1].cnt[i];
    }
}

void down(int idx, int begin, int end)
{
    int mid=(begin+end)/2;
    int numL=mid-begin+1, numR=end-mid;
    if(seg[idx].lazy==0)
    {
        for(int i=0; i<26; i++)
            tmp[i]=seg[idx].cnt[i];
        for(int i=0; i<26; i++)
        {
            int v=min(numL, tmp[i]);
            seg[idx*2].cnt[i]=v;
            numL-=v;
            tmp[i]-=v;
        }
        for(int i=0; i<26; i++)
        {
            int v=min(numR, tmp[i]);
            seg[idx*2+1].cnt[i]=v;
            numR-=v;
            tmp[i]-=v;
        }
        seg[idx*2].lazy=seg[idx*2+1].lazy=seg[idx].lazy;
    }
    else if(seg[idx].lazy==1)
    {
        for(int i=0; i<26; i++)
            tmp[i]=seg[idx].cnt[i];
        for(int i=25; i>=0; i--)
        {
            int v=min(numL, tmp[i]);
            seg[idx*2].cnt[i]=v;
            numL-=v;
            tmp[i]-=v;
        }
        for(int i=25; i>=0; i--)
        {
            int v=min(numR, tmp[i]);
            seg[idx*2+1].cnt[i]=v;
            numR-=v;
            tmp[i]-=v;
        }
        seg[idx*2].lazy=seg[idx*2+1].lazy=seg[idx].lazy;
    }
    seg[idx].lazy=-1;
}

void query(int idx, int begin, int end, int l, int r)
{
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
    {
        for(int i=0; i<26; i++)
            cnt[i]+=seg[idx].cnt[i];
    }
    else
    {
        down(idx, begin, end);
        int mid=(begin+end)/2;
        query(idx*2, begin, mid, l, r);
        query(idx*2+1, mid+1, end, l, r);
    }
}

void update(int idx, int begin, int end, int l, int r, int d)
{
    if(r<begin || end<l)
        return;
    if(l<=begin && end<=r)
    {
        int num=end-begin+1;
        if(d==0)
        {
            for(int i=0; i<26; i++)
            {
                int v=min(num, cnt[i]);
                seg[idx].cnt[i]=v;
                num-=v;
                cnt[i]-=v;
            }
        }
        else
        {
            for(int i=25; i>=0; i--)
            {
                int v=min(num, cnt[i]);
                seg[idx].cnt[i]=v;
                num-=v;
                cnt[i]-=v;
            }
        }
        seg[idx].lazy=d;
    }
    else
    {
        down(idx, begin, end);
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, l, r, d);
        update(idx*2+1, mid+1, end, l, r, d);
        for(int i=0; i<26; i++)
            seg[idx].cnt[i]=seg[idx*2].cnt[i]+seg[idx*2+1].cnt[i];
    }
}

void output(int idx, int begin, int end)
{
    if(begin==end)
    {
        for(int i=0; i<26; i++) if(seg[idx].cnt[i])
            printf("%c", 'a'+i);
        return;
    }
    down(idx, begin, end);
    int mid=(begin+end)/2;
    output(idx*2, begin, mid);
    output(idx*2+1, mid+1, end);
}

int main()
{
    scanf("%d%d", &N, &Q);
    scanf("%s", S+1);
    init(1, 1, N);
    int a, b, c;
    while(Q--)
    {
        scanf("%d%d%d", &a, &b, &c);
        query(1, 1, N, a, b);
        update(1, 1, N, a, b, c^1);
    }
    output(1, 1, N);
    printf("\n");
    return 0;
}