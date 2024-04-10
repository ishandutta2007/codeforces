#include <bits/stdc++.h>

using namespace std;

string a, b;
int N, M;
long long A[100001];
long long B[100001];

int main()
{
    getline(cin, a);
    getline(cin, b);
    N=0;
    for(int i=a.length()-1; i>=0; i--)
        A[N++]=a[i]-'0';
    M=0;
    for(int i=b.length()-1; i>=0; i--)
        B[M++]=b[i]-'0';
    int L=max(N, M);
    for(int i=0; i<L; i++)
        A[i]-=B[i];
    for(int i=L-1; i>=1; i--)
    {
        if(A[i]>100000)
        {
            printf(">");
            return 0;
        }
        if(A[i]<-100000)
        {
            printf("<");
            return 0;
        }
        A[i-2]+=A[i];
        A[i-1]+=A[i];
    }
    const long double phi=(sqrt(5.0L)+1.0L)/2.0L;
    if(A[0]==0 && A[1]==0)
        printf("=\n");
    else if(A[1]*phi+A[0]<0)
        printf("<\n");
    else
        printf(">\n");
    return 0;
}