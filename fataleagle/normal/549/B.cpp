#include <bits/stdc++.h>

using namespace std;

int N;
char adj[101][101];
int A[101];
int B[101];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%s", adj[i]);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    vector<int> ans;
    while(1)
    {
        int idx=-1;
        for(int i=0; i<N; i++) if(A[i]==B[i])
        {
            idx=i;
            break;
        }
        if(idx==-1)
            break;
        ans.push_back(idx);
        for(int i=0; i<N; i++) if(adj[idx][i]=='1')
            B[i]++;
    }
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%d ", it+1);
    printf("\n");
    return 0;
}