#include <bits/stdc++.h>

using namespace std;

int N, K;
queue<vector<int>> Q;

int main()
{
    scanf("%d%d", &N, &K);
    vector<int> A;
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d", &a);
        A.push_back(a);
    }
    Q.push(A);
    while(K--)
    {
        int tmp=Q.size();
        while(tmp--)
        {
            vector<int> cur=Q.front();
            Q.pop();
            for(int i=0; i<N; i++)
                for(int j=i; j<N; j++)
                {
                    reverse(cur.begin()+i, cur.begin()+j+1);
                    Q.push(cur);
                    reverse(cur.begin()+i, cur.begin()+j+1);
                }
        }
    }
    long long inv=0;
    long long sz=Q.size();
    while(!Q.empty())
    {
        auto it=Q.front();
        for(int i=0; i<N; i++)
            for(int j=i+1; j<N; j++)
                if(it[i]>it[j])
                    inv++;
        Q.pop();
    }
    printf("%.15f\n", (double)inv/sz);
    return 0;
}