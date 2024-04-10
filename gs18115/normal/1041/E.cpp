#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=2e5+10;
int cur;
bool chk[MAXN];
int F()
{
    while(chk[cur])
        cur--;
    return cur--;
}
int N,i,X;
int A[MAXN],n[MAXN];
int sz,pp;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    cur=N;
    chk[N]=true;
    for(i=1;i<N;i++)
    {
        cin>>A[i]>>X;
        chk[A[i]]=true;
        if(X!=N)
            return cout<<"NO"<<endl,0;
    }
    sort(A+1,A+N,greater<int>());
    if(A[1]<N-1)
        return cout<<"NO"<<endl,0;
    pp=0;
    sz=1;
    n[0]=N;
    for(i=2;i<N;i++)
    {
        if(i+A[i]<N)
            return cout<<"NO"<<endl,0;
        if(A[i]==A[i-1])
            sz++;
        else
        {
            pp+=sz;
            n[pp]=A[i-1];
            sz=1;
        }
    }
    cout<<"YES"<<endl;
    n[N-1]=A[N-1];
    for(i=1;i<N;i++)
        if(n[i]==0)
            n[i]=F();
    for(i=1;i<N;i++)
        cout<<n[i-1]<<' '<<n[i]<<'\n';
    cout<<endl;
    return 0;
}