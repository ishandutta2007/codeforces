#include <bits/stdc++.h>

using namespace std;

int N;
int A[2000];
int delta[5000];
long long sdelta[5000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    sort(A, A+N);
    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            delta[A[j]-A[i]]++;
        }
    }
    for(int i=1; i<5000; i++)
        sdelta[i]=sdelta[i-1]+delta[i];
    long long ans=0;
    for(int i=1; i<5000; i++)
    {
        for(int j=0, k=i-1; j<i; j++)
        {
            while(k>=0 && j+k>=i)
                k--;
            ans+=1LL*delta[i]*delta[j]*sdelta[k];
        }
    }
    long long c2=N*(N-1)/2;
    long double rans=(long double)ans/(c2*c2*c2);
    cout<<fixed<<setprecision(9)<<rans<<endl;
    return 0;
}