#include <bits/stdc++.h>

using namespace std;

int N;
int A[2001];
int B[2001];
int I[2001];
vector<pair<int, int>> ans;

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=N; i++)
        scanf("%d", B+i), I[B[i]]=i;
    for(int i=1; i<=N; i++)
        A[i]=I[A[i]];
    for(int i=1; i<=N; i++)
    {
        int pos=-1;
        for(int j=1; j<=N; j++) if(A[j]==i)
            pos=j;
        int last=pos;
        for(int j=pos; j>=i; j--) if(A[j]>=last)
        {
            ans.push_back(make_pair(last, j));
            swap(A[last], A[j]);
            last=j;
        }
        ans.push_back(make_pair(last, i));
        swap(A[last], A[i]);
    }
    int rans=0;
    for(auto& it: ans)
        rans+=abs(it.first-it.second);
    printf("%d\n", rans);
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%d %d\n", it.first, it.second);
    return 0;
}