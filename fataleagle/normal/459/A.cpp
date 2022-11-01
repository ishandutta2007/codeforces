#include <bits/stdc++.h>

using namespace std;

#define A make_pair(a, b)
#define B make_pair(c, d)
#define C make_pair(e, f)
#define D make_pair(g, h)

int a, b, c, d;

void check(int e, int f, int g, int h)
{
    if(!(-1000<=e && e<=1000) || !(-1000<=f && f<=1000))
        return;
    if(!(-1000<=g && g<=1000) || !(-1000<=h && h<=1000))
        return;
    if(A==B || A==C || A==D || B==C || B==D || C==D)
        return;
    printf("%d %d %d %d\n", e, f, g, h);
    exit(0);
}

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a==c)
    {
        int x=abs(b-d);
        check(a+x, b, a+x, d);
        check(a-x, b, a-x, d);
    }
    else if(b==d)
    {
        int x=abs(a-c);
        check(a, b+x, c, b+x);
        check(a, b-x, c, b-x);
    }
    else if(abs(a-c)==abs(b-d))
    {
        vector<pair<int, int>> all;
        all.push_back(make_pair(min(a, c), min(b, d)));
        all.push_back(make_pair(min(a, c), max(b, d)));
        all.push_back(make_pair(max(a, c), min(b, d)));
        all.push_back(make_pair(max(a, c), max(b, d)));
        bool flag=false;
        int e, f, g, h;
        for(auto it: all)
            if(it!=A && it!=B)
            {
                if(!flag)
                    e=it.first, f=it.second, flag=true;
                else
                    g=it.first, h=it.second;
            }
        check(e, f, g, h);
    }
    printf("-1\n");
    return 0;
}