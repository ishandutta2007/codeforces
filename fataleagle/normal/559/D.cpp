#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> A[100000];
double p2[100001];

int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

long long cross(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    c.first-=b.first;
    c.second-=b.second;
    b.first-=a.first;
    b.second-=a.second;
    return 1LL*b.first*c.second-1LL*b.second*c.first;
}

int main()
{
    p2[0]=1.0;
    for(int i=1; i<=100000; i++)
        p2[i]=p2[i-1]*2.0;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    for(int i=N-1; i>=0; i--)
        A[i].first-=A[0].first, A[i].second-=A[0].second;
    double area=0.0;
    for(int i=2; i<N; i++)
        area+=cross(A[0], A[i-1], A[i]);
    area/=2.0;
    double boundary=0.0;
    for(int i=0; i<N; i++)
    {
        double tarea=0.0;
        double np2=0.5;
        pair<int, int> a=A[i];
        for(int j=1; j<N-1; j++)
        {
            np2/=2.0;
            double cf=np2;
            if(N<100)
                cf=(p2[N-j-1]-1.0)/(p2[N]-1-N-0.5*N*(N-1));
            if(cf<1e-20)
                break;
            pair<int, int> b=A[(i+j)%N];
            tarea-=abs(cross(a, A[(i+j-1)%N], b))/2.0;
            area+=tarea*cf;
            boundary+=gcd(abs(b.first-a.first), abs(b.second-a.second))*cf;
        }
    }
    printf("%.9f\n", area-boundary/2.0+1);
    return 0;
}