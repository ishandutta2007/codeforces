#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>

#include <random>
std::default_random_engine random_engine(0xdeadbeef);
template<class T>
inline T randint(T L, T R) { return std::uniform_int_distribution<T>(L, R)(random_engine); }

using namespace std;

long long gcd(long long a, long long b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}

int sgn(long long x)
{
    return x<0?-1:1;
}

struct pt
{
    long long x, y;
    void normalize()
    {
        if(y<0)
            x*=-1, y*=-1;
        long long g=gcd(abs(x), abs(y));
        x/=g;
        y/=g;
    }
    pt operator+ (const pt& o) const
    {
        pt ret;
        ret.x=x*o.y+o.x*y;
        ret.y=y*o.y;
        ret.normalize();
        return ret;
    }
    pt operator- (const pt& o) const
    {
        pt ret;
        ret.x=x*o.y-o.x*y;
        ret.y=y*o.y;
        ret.normalize();
        return ret;
    }
    pt operator* (const pt& o) const
    {
        pt ret;
        ret.x=x*o.x;
        ret.y=y*o.y;
        ret.normalize();
        return ret;
    }
    bool operator== (const pt& o) const
    {
        return x==o.x && y==o.y;
    }
    bool operator!= (const pt& o) const
    {
        return !(*this==o);
    }
    bool operator< (const pt& o) const
    {
        if(*this==o)
            return false;
        if(x==0)
            return true;
        if(o.x==0)
            return false;
        long long a=x/y;
        long long b=o.x/o.y;
        if(a!=b)
            return a<b;
        pt p;
        p.x=x-a*y, p.y=y;
        pt q;
        q.x=o.x-b*o.y, q.y=o.y;
        int sign=sgn(p.x)*sgn(q.x);
        swap(p.x, p.y);
        swap(q.x, q.y);
        p.normalize();
        q.normalize();
        if(sign==1)
            return q<p;
        return p<q;
    }
    bool operator<= (const pt& o) const
    {
        return *this==o || *this<o;
    }
};

int N;
pair<pt, pt> A[200001];
pair<int, int> B[200000];
pair<int, int> C[200000];

bool negative(pair<pt, pt> a, pair<pt, pt> b)
{
    if(sgn((b.second-a.second).x)*sgn((a.first-b.first).x)==-1)
        return true;
    if((a.first-b.first).x>0)
        return ((b.second-a.second)*a.first+(a.first-b.first)*a.second).x<=0;
    return ((b.second-a.second)*a.first+(a.first-b.first)*a.second).x>=0;
}

bool good(pair<pt, pt> a, pair<pt, pt> b, pair<pt, pt> c)
{
    //x==(b.b - a.b)/(a.m - b.m)
    //(b.b - c.b)/(c.m - b.m)<(b.b - a.b)/(a.m - b.m)
    if(b.first==c.first)
        return c.second<b.second;
    pt p=b.second-c.second;
    pt q=c.first-b.first;
    pt r=b.second-a.second;
    pt s=a.first-b.first;
    if(q.x<0)
        p.x*=-1, q.x*=-1;
    if(s.x<0)
        r.x*=-1, s.x*=-1;
    return p*s<r*q;
}

bool cmp(const pair<pt, pt>& a, const pair<pt, pt>& b)
{
    if(a.first!=b.first)
        return b.first<a.first;
    return b.second<a.second;
}

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        B[i].first=a, B[i].second=b;
        C[i]=B[i];
    }
    sort(C, C+N);
    set<pair<int, int>> bad;
    pair<int, int> maxi={0, 0};
    for(int i=N-1; i>=0; i--)
    {
        if(maxi>make_pair(C[i].second, C[i].first))
            bad.insert({C[i].first, C[i].second});
        maxi=max(maxi, {C[i].second, C[i].first});
    }
    int M=0;
    A[M].first.x=1000000000, A[M].first.y=1;
    A[M].second.x=0, A[M].second.y=1;
    M++;
    for(int i=0; i<N; i++) if(!bad.count({B[i].first, B[i].second}))
    {
        A[M].first.x=1, A[M].first.y=B[i].first;
        A[M].second.x=1, A[M].second.y=B[i].second;
        M++;
    }
    sort(A, A+M, cmp);
    vector<pair<pt, pt>> envelope;
    for(int i=0; i<M; i++)
    {
        while(envelope.size()>=1 && envelope.back().first==A[i].first && A[i].second<=envelope.back().second)
            envelope.pop_back();
        while(envelope.size()>=2 && good(envelope[envelope.size()-2], envelope.back(), A[i]))
            envelope.pop_back();
        envelope.push_back(A[i]);
    }
    set<pair<int, int>> good;
    for(size_t i=1; i<envelope.size(); i++)
        good.insert({(int)envelope[i].first.y, (int)envelope[i].second.y});
    for(int i=0; i<N; i++) if(good.count({B[i].first, B[i].second}))
        printf("%d ", i+1);
    printf("\n");
    return 0;
}