#include <bits/stdc++.h>

using namespace std;

int N, M;
string S[101];
int group[101];
int ogroup[101];

int main()
{
    cin>>N>>M;
    char c;
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin>>c, S[j]+=c;
    for(int i=0; i<N; i++)
        group[i]=1;
    int ans=0;
    for(int i=0; i<M; i++)
    {
        bool bad=false;
        for(int j=1; j<N; j++)
            if(S[i][j]<S[i][j-1] && group[j]==group[j-1])
            {
                bad=true;
                break;
            }
        if(bad)
            ans++;
        else
        {
            memcpy(ogroup, group, sizeof ogroup);
            int cur=1;
            for(int j=1; j<N; j++)
            {
                if(S[i][j]>S[i][j-1] || ogroup[j]!=ogroup[j-1])
                    cur++;
                group[j]=cur;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}