#include <bits/stdc++.h>

using namespace std;

int N;
int A[1000];
int B[1000];
bool seen[1000][2][301];

int mindig(int x)
{
    return (x+8)/9;
}

void make(int n, int a)
{
    int pos=n-1;
    for(int i=1; i<=9; i++)
        if(mindig(a-i)<n)
        {
            A[pos--]=i;
            a-=i;
            n--;
            break;
        }
    while(n)
    {
        for(int i=0; i<=9; i++)
            if(mindig(a-i)<n)
            {
                A[pos--]=i;
                a-=i;
                n--;
                break;
            }
    }
}

bool solve(int pos, bool same, int sum)
{
    if(sum<0)
        return false;
    if(pos==-1)
        return sum==0 && !same;
    if(seen[pos][same][sum])
        return false;
    seen[pos][same][sum]=true;
    for(int i=same?A[pos]:0; i<=9; i++)
    {
        B[pos]=i;
        if(solve(pos-1, same && i==A[pos], sum-i))
            return true;
    }
    return false;
}

int main()
{
    scanf("%d", &N);
    int last=0;
    int a;
    while(N--)
    {
        scanf("%d", &a);
        int n=mindig(a);
        if(n>last)
            make(n, a);
        else
        {
            n=last;
            memset(seen, 0, sizeof seen);
            if(solve(n-1, true, a))
            {
                for(int i=0; i<n; i++)
                    A[i]=B[i];
            }
            else
            {
                n++;
                make(n, a);
            }
        }
        last=n;
        for(int i=last-1; i>=0; i--)
            printf("%d", A[i]);
        printf("\n");
    }
    return 0;
}