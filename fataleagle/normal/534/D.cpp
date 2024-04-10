#include <bits/stdc++.h>

using namespace std;

int N;
int A[200000];
vector<int> B[200000];

int main()
{
    scanf("%d", &N);
    int maxi=0;
    for(int i=0; i<N; i++)
        scanf("%d", A+i), B[A[i]].push_back(i+1), maxi=max(maxi, A[i]);
    vector<int> ans;
    for(int i=0; i<=maxi; i++)
    {
        if(B[i].empty())
        {
            printf("Impossible\n");
            return 0;
        }
        ans.push_back(B[i].back());
        B[i].pop_back();
    }
    int cur=maxi+1;
    while(cur>=0 && (int)ans.size()<N)
    {
        if(B[cur].empty())
        {
           cur-=3;
           continue;
        }
        ans.push_back(B[cur].back());
        B[cur].pop_back();
        cur++;
    }
    if((int)ans.size()==N)
    {
        printf("Possible\n");
        for(int i=0; i<N; i++)
            printf("%d%c", ans[i], " \n"[i==N-1]);
    }
    else
        printf("Impossible\n");
    return 0;
}