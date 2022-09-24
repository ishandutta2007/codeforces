#include<iostream>
using namespace std;
int S,E,M,N,i,A;
bool chk[123];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>M>>N;
    S=1;
    E=M;
    for(i=0;i<N;i++)
    {
        cout<<1<<endl;
        fflush(stdout);
        cin>>A;
        if(A==0||A==-2)
            exit(0);
        else if(A==1)
            chk[i]=true;
        else if(A==-1)
            chk[i]=false;
    }
    for(i=0;i<60-N;i++)
    {
        M=S+E>>1;
        cout<<M<<endl;
        cin>>A;
        if(A==0||A==-2)
            exit(0);
        if(!chk[i%N])
            A=-A;
        if(A==1)
            S=M+1;
        else
            E=M-1;
    }
    return 0;
}