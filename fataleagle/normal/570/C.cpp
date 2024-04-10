#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[300001];

int main()
{
    scanf("%d%d", &N, &M);
    scanf("%s", S);
    int dots=0;
    set<pair<int, int>> s;
    int last=-1;
    for(int i=0; i<N; i++)
    {
        if(S[i]=='.')
        {
            dots++;
            if(last==-1)
                last=i;
        }
        else if(last!=-1)
            s.insert(make_pair(last, i-1)), last=-1;
    }
    if(last!=-1)
        s.insert(make_pair(last, N-1));
    int a;
    char c;
    while(M--)
    {
        scanf("%d %c", &a, &c);
        a--;
        if(c=='.' && S[a]!='.')
        {
            auto it=s.lower_bound(make_pair(a, -1));
            auto pit=(it==s.begin())?s.end():prev(it);
            auto nit=it;
            int l=a, r=a;
            if(a>0 && S[a-1]=='.' && pit!=s.end())
                l=pit->first, s.erase(pit);
            if(a+1<N && S[a+1]=='.' && nit!=s.end())
                r=nit->second, s.erase(nit);
            s.insert(make_pair(l, r));
        }
        else if(c!='.' && S[a]=='.')
        {
            auto it=s.lower_bound(make_pair(a+1, -1));
            assert(it!=s.begin());
            --it;
            int l=it->first, r=it->second;
            s.erase(it);
            if(l<=a-1)
                s.insert(make_pair(l, a-1));
            if(a+1<=r)
                s.insert(make_pair(a+1, r));
        }
        dots+=(c=='.')-(S[a]=='.');
        S[a]=c;
        printf("%d\n", dots-s.size());
    }
    return 0;
}