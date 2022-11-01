#include <bits/stdc++.h>

using namespace std;

int N;
int pr[1000001];
int ne[1000001];
set<int> s;

int main()
{
    scanf("%d", &N);
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        pr[b]=a;
        ne[a]=b;
        s.insert(a);
        s.insert(b);
    }
    for(int i=0; i<=1000000; i++)
        s.erase(ne[i]);
    int y=0;
    int x=*s.begin();
    while(x!=0)
    {
        printf("%d ", x);
        int z=ne[y];
        y=x;
        x=z;
    }
    printf("\n");
    return 0;
}