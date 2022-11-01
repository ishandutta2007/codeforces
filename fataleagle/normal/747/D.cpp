#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[200000];

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d", &a);
        if(a<0)
            A[i]=0;
        else
            A[i]=1;
    }
    int change=-1;
    if(A[0]==0)
        change++;
    vector<int> v, w;
    for(int i=0, j; i<N; i=j)
    {
        for(j=i; j<N && A[i]==A[j]; j++);
        if(A[i]==0)
            K-=j-i;
        else
        {
            if(i!=0 && j!=N)
                v.push_back(j-i);
            else if(i!=0)
                w.push_back(j-i);
        }
        change++;
    }
    if(K<0)
        return 0*printf("-1\n");
    sort(v.begin(), v.end());
    sort(w.begin(), w.end());
    int ans=change;
    for(int j=0; j<=(int)w.size(); j++)
    {
        int c=change, k=K;
        for(int i=0; i<(int)v.size(); i++) if(k>=v[i])
            k-=v[i], c-=2;
        ans=min(ans, c);
        if(j==(int)w.size() || K<w[j])
            break;
        K-=w[j];
        change--;
    }
    printf("%d\n", ans);
    return 0;
}