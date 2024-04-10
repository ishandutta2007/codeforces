#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[300];

int main()
{
    scanf("%d%d", &N, &K);
    bool neg=true;
    for(int i=0; i<N; i++)
        scanf("%d", A+i), neg=neg && A[i]<=0;
    if(neg)
    {
        printf("%d\n", *max_element(A, A+N));
        return 0;
    }
    int maxi=0;
    vector<int> in, out;
    for(int i=0; i<N; i++)
        for(int j=i; j<N; j++)
        {
            in.clear();
            out.clear();
            for(int k=0; k<N; k++)
                if(i<=k && k<=j)
                    in.push_back(A[k]);
                else
                    out.push_back(A[k]);
            sort(in.begin(), in.end());
            int nneg=0;
            while(nneg<K && nneg<(int)in.size() && in[nneg]<0)
                nneg++;
            sort(out.rbegin(), out.rend());
            int nposi=0;
            while(nposi<K && nposi<(int)out.size() && out[nposi]>0)
                nposi++;
            int n=min(nneg, nposi);
            int s=0;
            for(int i=0; i<n; i++)
                s+=out[i];
            for(int i=n; i<(int)in.size(); i++)
                s+=in[i];
            maxi=max(maxi, s);
        }
    printf("%d\n", maxi);
    return 0;
}