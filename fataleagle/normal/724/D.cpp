#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[100001];

void check(char c)
{
    set<int> pos;
    vector<int> v;
    for(int i=0; i<N; i++)
    {
        if(S[i]<c)
            pos.insert(i);
        else if(S[i]==c)
            v.push_back(i);
    }
    for(int i=0; i<N-M+1; i++)
    {
        auto it=pos.lower_bound(i);
        bool covered=false;
        if(it!=pos.end())
            covered|=(*it-i)<M;
        if(!covered)
        {
            auto it=lower_bound(v.begin(), v.end(), i+M);
            if(it==v.begin())
                return;
            --it;
            if(*it<i)
                return;
            pos.insert(*it);
        }
    }
    string s;
    for(auto& it: pos)
        s+=S[it];
    sort(s.begin(), s.end());
    printf("%s\n", s.c_str());
    exit(0);
}

int main()
{
    scanf("%d", &M);
    scanf("%s", S);
    N=strlen(S);
    for(char c='a'; c<='z'; c++)
        check(c);
    return 0;
}