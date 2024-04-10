#include <bits/stdc++.h>

#ifdef getchar
#undef getchar
#endif
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
char _inp[4097], *_pinp=_inp;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int N;
int A[1000001];
int B[1000001];
int C[1000001];
int D[1000001];

void compose_odd(int x)
{
    int len=0;
    int o=x;
    do
    {
        x=A[x];
        len++;
    }
    while(x!=o);
    vector<int> a, b;
    for(int i=0; i<len/2+1; i++)
    {
        a.push_back(x);
        x=A[x];
    }
    for(int i=0; i<len/2; i++)
    {
        b.push_back(x);
        x=A[x];
    }
    vector<int> c;
    for(int i=0; i<len/2; i++)
        c.push_back(a[i]), c.push_back(b[i]);
    c.push_back(a.back());
    for(int i=0; i<(int)c.size(); i++)
        C[c[i]]=c[(i+1)%c.size()];
}

void compose_even(int x, int y)
{
    vector<int> a;
    int o=x;
    do
    {
        a.push_back(x);
        a.push_back(y);
        x=A[x], y=A[y];
    }
    while(x!=o);
    for(int i=0; i<(int)a.size(); i++)
        C[a[i]]=a[(i+1)%a.size()];
}

int main()
{
    scan(N);
    for(int i=1; i<=N; i++)
        scan(A[i]);
    for(int i=1; i<=N; i++) if(B[i]==0)
    {
        int x=i;
        int len=0;
        do
        {
            x=A[x];
            B[x]=1;
            len++;
        }
        while(x!=i);
        if(len%2==0)
        {
            if(D[len])
                compose_even(D[len], i), D[len]=0;
            else
                D[len]=i;
        }
        else
            compose_odd(i);
    }
    for(int i=1; i<=N; i++) if(C[i]==0 || C[C[i]]!=A[i])
        return printf("-1\n"), 0;
    for(int i=1; i<=N; i++)
        printf("%d%c", C[i], " \n"[i==N]);
    return 0;
}