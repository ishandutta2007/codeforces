#include <bits/stdc++.h>

int ask(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int r; scanf("%d", &r);
    if(r==-1) exit(0);
    return r;
}

void solve()
{
    int N; scanf("%d", &N);
    auto fix=[&](int q, int w, int e, int r)
    {
        int u,v;
        switch(ask(q, e))
        {
            case 1:
                u=q,v=r;
                break;
            case 2:
                u=w,v=e;
                break;
            default:
                u=w,v=r;
                break;
        }
        switch(ask(u,v))
        {
            case 1: return u;
            case 2: return v;
            default: assert(0);
        }
        assert(0);
    };
    auto reduce=[&](std::vector<int> const& a)
    {
        std::vector<int> b;
        for(int i=0;i<a.size();i+=4)
            b.push_back(fix(a[i], a[i+1], a[i+2], a[i+3]));
        return b;
    };
    std::vector<int> a(1<<N);
    std::iota(a.begin(), a.end(), 1);
    while(a.size()>2) a=reduce(a);
    if(a.size()==2)
       if(ask(a[0], a[1])==2)
           a[0]=a[1];
    printf("! %d\n", a[0]);
    fflush(stdout);
}
int main()
{
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}