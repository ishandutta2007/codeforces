#include <bits/stdc++.h>

using namespace std;

int N;
int A[301];
bool seen[301];
char good[301][301];
vector<int> available;
vector<int> nums;

void dfs(int x)
{
    seen[x]=true;
    available.push_back(x);
    nums.push_back(A[x]);
    for(int i=1; i<=N; i++)
        if(!seen[i] && good[x][i]=='1')
            dfs(i);
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            scanf(" %c", good[i]+j);
    for(int i=1; i<=N; i++)
        if(!seen[i])
        {
            available.clear();
            nums.clear();
            dfs(i);
            sort(available.begin(), available.end());
            sort(nums.begin(), nums.end());
            for(size_t i=0; i<available.size(); i++)
                A[available[i]]=nums[i];
        }
    for(int i=1; i<=N; i++)
        printf("%d%c", A[i], " \n"[i==N]);
    return 0;
}