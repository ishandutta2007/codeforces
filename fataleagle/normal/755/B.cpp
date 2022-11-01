#include <bits/stdc++.h>

using namespace std;

int N, M;
set<string> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=0; i<N; i++)
    {
        string s;
        cin>>s;
        S.insert(s);
    }
    int a=0, b=0, c=0;
    for(int i=0; i<M; i++)
    {
        string s;
        cin>>s;
        if(S.count(s))
            S.erase(s), b++;
        else
            c++;
    }
    a=S.size();
    int t=b%2;
    while(a!=-1 && c!=-1)
    {
        if(t==1)
            c--;
        else
            a--;
        t^=1;
    }
    if(c==-1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}