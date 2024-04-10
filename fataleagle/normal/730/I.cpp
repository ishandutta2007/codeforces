#include <bits/stdc++.h>

using namespace std;

int N, P, S;
pair<int, int> A[3000];
int B[3000];
int C[3000];
int I[3001];
int II[3001];

int main()
{
    scanf("%d%d%d", &N, &P, &S);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i].first), I[i]=i;
    for(int i=0; i<N; i++)
        scanf("%d", &A[i].second);
    for(int i=0; i<N; i++)
        for(int j=i; j<N; j++)
            if(A[i].first>A[j].first)
                swap(A[i], A[j]), swap(I[i], I[j]);
    for(int i=0; i<N; i++)
        II[I[i]]=i;
    vector<pair<int, int>> v, w;
    long long s=0, ans=0;
    for(int i=N-1; i>=0; i--)
    {
        for(int j=0; j<N; j++)
            B[I[j]]=j>=i;
        s+=A[i].first;
        v.push_back({-A[i].second+A[i].first, I[i]});
        if((int)v.size()>=P && (int)v.size()<=P+S)
        {
            int d=v.size()-P;
            long long delta=0;
            if(d>0)
            {
                nth_element(v.begin(), v.begin()+d-1, v.end());
                for(int j=0; j<d; j++)
                    delta-=v[j].first, B[v[j].second]++;
            }
            if(S-d>0)
            {
                w.clear();
                for(int j=0; j<i; j++)
                    w.push_back({-A[j].second, I[j]});
                nth_element(w.begin(), w.begin()+(S-d)-1, w.end());
                for(int j=0; j<S-d; j++)
                    delta-=w[j].first, B[w[j].second]=2;
            }
            if(s+delta>ans)
            {
                ans=s+delta;
                for(int j=0; j<N; j++)
                    C[j]=B[j];
            }
        }
    }
    printf("%lld\n", ans);
    for(int i=0; i<N; i++) if(C[i]==1)
        printf("%d ", i+1);
    printf("\n");
    for(int i=0; i<N; i++) if(C[i]==2)
        printf("%d ", i+1);
    printf("\n");
    return 0;
}