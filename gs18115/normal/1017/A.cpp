#include<iostream>
using namespace std;
int N,A,B,C,D,i,cnt;
int S[12345];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>A>>B>>C>>D;
        S[i]=A+B+C+D;
    }
    for(i=0;i<N;i++)
    {
        if(S[i]>S[0])
            cnt++;
    }
    cout<<cnt+1;
    return 0;
}