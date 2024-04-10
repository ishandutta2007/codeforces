#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

struct line
{
    unsigned long long m, b;
};

int N;
int A[100001], B[100001];
vector<line> hull;

long double intersect(line a, line b)
{
    return (long double)(b.b-a.b)/(long double)(a.m-b.m);
}

bool LE(long double a, long double b)
{
    return a<b || abs(a-b)<=1e-9;
}

void add_line(unsigned long long m, unsigned long long b)
{
    while(hull.size()>=2 && LE(intersect(hull[hull.size()-1], (line){m, b}), intersect(hull[hull.size()-2], hull[hull.size()-1])))
        hull.pop_back();
    hull.push_back((line){m, b});
}

inline unsigned long long eval(unsigned long long x, int l)
{
    return hull[l].m*x+hull[l].b;
}

unsigned long long query(unsigned long long x)
{
    static int ptr=0;
    int sz=hull.size()-1;
    ptr=min(ptr, sz);
    while(ptr<sz && eval(x, ptr+1)<=eval(x, ptr))
        ptr++;
    return eval(x, ptr);
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<N; i++)
        scanf("%d", B+i);
    add_line(A[N-1], B[N-1]);
    for(int i=N-2; i>=0; i--)
        add_line(A[i], query(B[i]));
    cout<<hull.back().b<<endl;

    return 0;
}