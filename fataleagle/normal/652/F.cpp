#include <bits/stdc++.h>

using namespace std;

struct ball
{
    long long x, d, i;
    bool operator< (const ball& other) const
    {
        return x<other.x;
    }
} A[300000];

long long N, M;
long long T;
pair<long long, long long> pos[300000];
int order[300000];

int main()
{
    scanf("%lld%lld%lld", &N, &M, &T);
    M*=2;
    T=T*2-1;
    int a;
    char c;
    for(int i=0; i<N; i++)
    {
        scanf("%d %c", &a, &c);
        if(c=='L')
            A[i]=(ball){2LL*(a-1), -1LL, i};
        else
            A[i]=(ball){2LL*(a-1), 1LL, i};
    }
    sort(A, A+N);
    int cross=0;
    for(int i=1; i<N; i++) if(A[0].d!=A[i].d)
    {
        long long m=A[0].d-A[i].d;
        long long b=A[0].x-A[i].x;
        if(m<0)
            m*=-1, b*=-1;
        long long mm=M/m;
        long long xd=max(0LL, (T-((-b/m)%mm+mm)%mm))/mm;
        if((T-((-b/m)%mm+mm)%mm)>=0 && (-b/m)%mm!=0)
            xd++;
        cross=(cross+xd)%N;
    }
    if(A[0].d<0)
        cross=(N-cross)%N;
    for(int i=0; i<N; i++)
        pos[i]=make_pair(((A[i].d*T+A[i].x)%M+M)%M, A[i].d);
    auto match=pos[0];
    sort(pos, pos+N);
    int first=-1;
    for(int i=0; i<N; i++) if(pos[i]==match)
        first=(i-cross+N)%N;
    assert(first!=-1);
    rotate(pos, pos+first, pos+N);
    for(int i=0; i<N; i++)
        order[A[i].i]=i;
    for(int i=0; i<N; i++)
    {
        int x=order[i];
        printf("%lld%c", (pos[x].first+pos[x].second+M)%M/2+1, " \n"[i==N-1]);
    }
    return 0;
}