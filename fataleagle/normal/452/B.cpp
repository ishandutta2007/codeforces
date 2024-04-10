#include <bits/stdc++.h>

using namespace std;

int N, M;

inline long long dist(pair<int, int>& a, pair<int, int>& b)
{
    long long dx=a.first-b.first;
    long long dy=a.second-b.second;
    return dx*dx+dy*dy;
}

int main()
{
    cin>>N>>M;
    set<pair<int, int>> s;
    s.insert(make_pair(0, 0));
    s.insert(make_pair(1, 0));
    s.insert(make_pair(0, 1));
    s.insert(make_pair(1, 1));
    s.insert(make_pair(0, M));
    s.insert(make_pair(1, M));
    s.insert(make_pair(0, M-1));
    s.insert(make_pair(1, M-1));
    s.insert(make_pair(N, 0));
    s.insert(make_pair(N, 1));
    s.insert(make_pair(N-1, 0));
    s.insert(make_pair(N-1, 1));
    s.insert(make_pair(N, M));
    s.insert(make_pair(N, M-1));
    s.insert(make_pair(N-1, M));
    s.insert(make_pair(N-1, M-1));
    set<pair<int, int>> t;
    for(auto it: s)
        if(0<=it.first && it.first<=N && 0<=it.second && it.second<=M)
            t.insert(it);
    pair<int, int> p, q, r, u;
    long long best=0;
    for(auto a: t)
        for(auto b: t)
            for(auto c: t)
                for(auto d: t)
                {
                    if(a==b || a==c || a==d || b==c || b==d || c==d)
                        continue;
                    long long len=dist(a, b)+dist(b, c)+dist(c, d);
                    if(len>best)
                        best=len, p=a, q=b, r=c, u=d;
                }
    cout<<p.first<<" "<<p.second<<endl;
    cout<<q.first<<" "<<q.second<<endl;
    cout<<r.first<<" "<<r.second<<endl;
    cout<<u.first<<" "<<u.second<<endl;
    return 0;
}