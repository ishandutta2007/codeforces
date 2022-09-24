#include<iostream>
using namespace std;
int gcd(int x,int y)
{
    return y>0?gcd(y,x%y):x;
}
int N,i,j,G,maxi;
int A[345678];
int chk[15678901];
int pcnt;
int p[15678];
bool pchk[15678];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(i=2;i<4000;i++)
    {
        if(!pchk[i])
        {
            p[pcnt++]=i;
            for(j=i;j*i<4000;j++)
                pchk[j*i]=true;
        }
    }
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        G=gcd(G,A[i]);
    }
    for(i=0;i<N;i++)
    {
        A[i]/=G;
        for(j=0;p[j]*p[j]<=A[i];j++)
        {
            if(A[i]%p[j]==0)
            {
                chk[p[j]]++;
                while(A[i]%p[j]==0)
                    A[i]/=p[j];
            }
        }
        chk[A[i]]++;
    }
    for(i=2;i<=15000000;i++)
        maxi=max(maxi,chk[i]);
    cout<<(maxi>0?N-maxi:-1)<<endl;
    return 0;
}