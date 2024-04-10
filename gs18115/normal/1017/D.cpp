#include<iostream>
using namespace std;
const int n=128;
char s[16789];
char S[16789];
int A,B;
int N,M,Q,i,j;
int W[16789];
int sum[16789];
int a;
int chk[16789];
int FT[16789][138];
void FI(int p,int I,int dif)
{
    for(;I<n;I+=I&-I)
        FT[p][I]+=dif;
    return;
}
int FS(int p,int I)
{
    int s=0;
    for(;I>0;I-=I&-I)
        s+=FT[p][I];
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M>>Q;
    for(i=0;i<N;i++)
        cin>>W[i];
    for(i=0;i<M;i++)
    {
        cin>>S;
        A=0;
        for(j=0;j<N;j++)
            A=(A<<1)+S[j]-48;
        chk[A]++;
    }
    for(i=0;i<(1<<N);i++)
    {
        sum[i]=0;
        for(j=0;j<N;j++)
            sum[i]+=W[j]*((i>>(N-1-j))&1);
    }
    for(i=0;i<(1<<N);i++)
        for(j=0;j<(1<<N);j++)
            if(chk[j]>0&&sum[((1<<N)-1)&~(i^j)]+1<n)
                FI(i,sum[((1<<N)-1)&~(i^j)]+1,chk[j]);
    for(i=0;i<Q;i++)
    {
        cin>>S>>B;
        A=0;
        for(j=0;j<N;j++)
            A=(A<<1)+S[j]-48;
        cout<<FS(A,B+1)<<'\n';
    }
    return 0;
}