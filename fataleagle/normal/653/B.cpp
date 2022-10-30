#include <bits/stdc++.h>

using namespace std;

int N, M;
set<string> seen[7];
vector<string> rules[6];

void dfs(string s)
{
    if(seen[s.length()].count(s))
        return;
    seen[s.length()].insert(s);
    if((int)s.length()==N)
        return;
    int x=s.back()-'a';
    s.pop_back();
    for(auto& it: rules[x])
        dfs(s+it);
}

int main()
{
    cin>>N>>M;
    string a, b;
    for(int i=0; i<M; i++)
    {
        cin>>a>>b;
        reverse(a.begin(), a.end());
        rules[b[0]-'a'].push_back(a);
    }
    dfs("a");
    printf("%d\n", seen[N].size());
    return 0;
}