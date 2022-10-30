#include <bits/stdc++.h>

using namespace std;

struct BIT
{
    int seg[524288];
    void update(int idx, int begin, int end, int x, int v)
    {
        if(x<begin || end<x)
            return;
        if(begin==end)
            seg[idx]=max(seg[idx], v);
        else
        {
            int mid=(begin+end)/2;
            update(idx*2, begin, mid, x, v);
            update(idx*2+1, mid+1, end, x, v);
            seg[idx]=max(seg[idx*2], seg[idx*2+1]);
        }
    }
    int query(int idx, int begin, int end, int l, int r)
    {
        if(r<begin || end<l)
            return 0;
        if(l<=begin && end<=r)
            return seg[idx];
        int mid=(begin+end)/2;
        return max(query(idx*2, begin, mid, l, r),
                   query(idx*2+1, mid+1, end, l, r));
    }
    void add(int x, int v)
    {
        update(1, 1, 262144, x+1, v);
    }
    int ask(int x, int y)
    {
        return query(1, 1, 262144, x+1, y+1);
    }
} U, L;

int N, Q;
int A[200000];
int B[200000];
char C[200000];
int X[200000];
int Y[200000];
set<pair<int, int>> seen;

int getX(int x)
{
    return lower_bound(X, X+Q, x)-X;
}

int getY(int y)
{
    return lower_bound(Y, Y+Q, y)-Y;
}

int main()
{
    scanf("%d%d", &N, &Q);
    for(int i=0; i<Q; i++)
    {
        scanf("%d%d %c", B+i, A+i, C+i);
        X[i]=A[i];
        Y[i]=B[i];
    }
    sort(X, X+Q);
    sort(Y, Y+Q);
    for(int i=0; i<Q; i++)
    {
        A[i]=getX(A[i]);
        B[i]=getY(B[i]);
        if(seen.count({A[i], B[i]}))
        {
            printf("0\n");
            continue;
        }
        seen.insert({A[i], B[i]});
        if(C[i]=='L')
        {
            int lo=-1, mid, hi=B[i];
            while(lo<hi)
            {
                mid=(lo+hi+1)/2;
                if(U.ask(mid, B[i])>=N-X[A[i]]+1)
                    lo=mid;
                else
                    hi=mid-1;
            }
            int l=1;
            if(lo>=0)
                l=Y[lo]+1;
            printf("%d\n", Y[B[i]]-l+1);
            L.add(A[i], N-l+1);
        }
        else
        {
            int lo=-1, mid, hi=A[i];
            while(lo<hi)
            {
                mid=(lo+hi+1)/2;
                if(L.ask(mid, A[i])>=N-Y[B[i]]+1)
                    lo=mid;
                else
                    hi=mid-1;
            }
            int l=1;
            if(lo>=0)
                l=X[lo]+1;
            printf("%d\n", X[A[i]]-l+1);
            U.add(B[i], N-l+1);
        }
    }
    return 0;
}