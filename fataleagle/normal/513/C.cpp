#include <bits/stdc++.h>

using namespace std;

int N;
int L[5];
int R[5];
int len[5];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", L+i, R+i), len[i]=R[i]-L[i]+1;
    long double ans=0.0;
    for(int i=0; i<N; i++)
    {
        for(int j=1; j<R[i]; j++)
        {
            long double prob=(long double)(R[i]-max(j+1, L[i])+1)/len[i];
            long double sum=0.0;
            for(int k=1; k<(1<<N); k++)
            {
                if((k>>i)&1)
                    continue;
                long double base=1.0;
                for(int l=0; l<N; l++) if(i!=l)
                {
                    if((k>>l)&1)
                        base*=(L[l]<=j && j<=R[l])?1.0/len[l]:0.0;
                    else
                        base*=(long double)max(0, min(j-1, R[l])-L[l]+1)/len[l];
                }
                sum+=base;
            }
            prob*=sum;
            ans+=j*prob;
        }
    }
    for(int j=1; j<=10000; j++)
    {
        for(int k=1; k<(1<<N); k++)
        {
            if(__builtin_popcount(k)==1)
                continue;
            long double base=1.0;
            for(int l=0; l<N; l++)
            {
                if((k>>l)&1)
                    base*=(L[l]<=j && j<=R[l])?1.0/len[l]:0.0;
                else
                    base*=(long double)max(0, min(j-1, R[l])-L[l]+1)/len[l];
            }
            ans+=j*base;
        }
    }
    cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}