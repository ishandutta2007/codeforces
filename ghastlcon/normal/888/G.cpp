#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#define N 200020
#define M 30
using namespace std;

class Node
{
public:
    Node *s[2];

    Node(void)
    {
        s[0] = s[1] = NULL;

        return;
    }
};

Node *r;
int a[N];

void InsertTrie(Node *&x, int v, int l)
{
    if(!x)
        x = new Node();
    if(l == -1)
        return;

    InsertTrie(x -> s[!!(v & (1 << l))], v, l - 1);

    return;
}

int MinTrie(Node *x, int v, int l)
{
    if(l == -1)
        return 0;

    if(v & (1 << l))
        return x -> s[1] ? MinTrie(x -> s[1], v, l - 1) : MinTrie(x -> s[0], v, l - 1) | (1 << l);

    return x -> s[0] ? MinTrie(x -> s[0], v, l - 1) : MinTrie(x -> s[1], v, l - 1) | (1 << l);    
}

long long DFS(vector<int> v, Node *x, int l)
{
    vector<int> p, q;
    int i, o;

    if(!x || l == -1)
        return 0;
    if(!x -> s[0])
        return DFS(v, x -> s[1], l - 1);
    if(!x -> s[1])
        return DFS(v, x -> s[0], l - 1);

    for(i = 0; i < (signed)v.size(); i ++)
        if(v.at(i) & (1 << l))
            q.push_back(v.at(i));
        else
            p.push_back(v.at(i));
    for(i = 0, o = 2147483647; i < (signed)p.size(); i ++)
        o = min(o, MinTrie(x -> s[1], p.at(i), l - 1));

    return DFS(p, x -> s[0], l - 1) + DFS(q, x -> s[1], l - 1) + (o | (1 << l));
}

int main(void)
{
    int n;
    int i;

    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    n = unique(a, a + n) - a;

    for(i = 0; i < n; i ++)
        InsertTrie(r, a[i], M - 1);
    printf("%lld\n", DFS(vector<int>(a, a + n), r, M - 1));

    return 0;
}