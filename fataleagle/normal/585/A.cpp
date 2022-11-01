#include <bits/stdc++.h>

using namespace std;

int N;
int V[4000], D[4000], P[4000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d%d", V+i, D+i, P+i);
    queue<int> Q;
    vector<int> ans;
    for(int i=0; i<N; i++) if(P[i]>=0)
    {
        ans.push_back(i);
        int dec=V[i];
        for(int j=i+1; j<N; j++) if(P[j]>=0)
        {
            P[j]-=dec;
            dec--;
            if(P[j]<0)
                Q.push(j);
            if(dec==0)
                break;
        }
        while(!Q.empty())
        {
            int j=Q.front();
            Q.pop();
            for(int k=j+1; k<N; k++) if(P[k]>=0)
            {
                P[k]-=D[j];
                if(P[k]<0)
                    Q.push(k);
            }
        }
    }
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%d ", it+1);
    printf("\n");
    return 0;
}