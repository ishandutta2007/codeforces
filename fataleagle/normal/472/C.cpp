#include <bits/stdc++.h>

using namespace std;

int N, K;
string A[100001][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=1; i<=N; i++)
    {
        cin>>A[i][0]>>A[i][1];
        if(A[i][0]>A[i][1])
            swap(A[i][0], A[i][1]);
    }
    int a;
    string last="";
    for(int i=1; i<=N; i++)
    {
        cin>>a;
        if(A[a][0]>last)
            last=A[a][0];
        else if(A[a][1]>last)
            last=A[a][1];
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}