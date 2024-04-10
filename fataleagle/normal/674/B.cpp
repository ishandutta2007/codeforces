#include <bits/stdc++.h>

using namespace std;

int N, K;
int a, b, c, d;
vector<int> ans1;
vector<int> ans2;
int P[1001];
bool used[1001];

int main()
{
    scanf("%d%d", &N, &K);
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(N==4)
        return printf("-1\n"), 0;
    ans1.push_back(1);
    for(int i=6; i<=N; i++)
        ans1.push_back(i);
    ans1.push_back(3);
    ans1.push_back(5);
    ans1.push_back(4);
    ans1.push_back(2);

    ans2.push_back(3);
    for(int i=N; i>=6; i--)
        ans2.push_back(i);
    ans2.push_back(1);
    ans2.push_back(5);
    ans2.push_back(2);
    ans2.push_back(4);
    set<pair<int, int>> edges;
    for(int i=1; i<N; i++)
    {
        int u=ans1[i-1];
        int v=ans1[i];
        if(u>v)
            swap(u, v);
        edges.insert({u, v});
    }
    for(int i=1; i<N; i++)
    {
        int u=ans2[i-1];
        int v=ans2[i];
        if(u>v)
            swap(u, v);
        edges.insert({u, v});
    }
    if((int)edges.size()>K)
        return printf("-1\n"), 0;
    P[1]=a;
    P[2]=b;
    P[3]=c;
    P[4]=d;
    used[a]=true;
    used[b]=true;
    used[c]=true;
    used[d]=true;
    int ptr=5;
    for(int i=1; i<=N; i++) if(!used[i])
        P[ptr++]=i;
    for(int i=0; i<N; i++)
        printf("%d%c", P[ans1[i]], " \n"[i==N-1]);
    for(int i=0; i<N; i++)
        printf("%d%c", P[ans2[i]], " \n"[i==N-1]);
    return 0;
}