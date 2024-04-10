#include<iostream>
using namespace std;
const int MAXV=1e6+10;
char s[10];
int N,A,B;
bool C1[MAXV],C2[MAXV];
int v[MAXV],X[MAXV],Y[MAXV];
void DFS1(int H)
{
    if(v[H]==1)
    {
        DFS1(X[H]);
        C1[H]=!C1[X[H]];
    }
    else if(v[H]==2)
    {
        DFS1(X[H]);
        DFS1(Y[H]);
        C1[H]=C1[X[H]]&&C1[Y[H]];
    }
    else if(v[H]==3)
    {
        DFS1(X[H]);
        DFS1(Y[H]);
        C1[H]=C1[X[H]]||C1[Y[H]];
    }
    else if(v[H]==4)
    {
        DFS1(X[H]);
        DFS1(Y[H]);
        C1[H]=C1[X[H]]^C1[Y[H]];
    }
    return;
}
void DFS2(int H)
{
    if(v[H]==1)
        DFS2(X[H]);
    else if(v[H]==2)
    {
        if(C1[Y[H]])
            DFS2(X[H]);
        if(C1[X[H]])
            DFS2(Y[H]);
    }
    else if(v[H]==3)
    {
        if(!C1[Y[H]])
            DFS2(X[H]);
        if(!C1[X[H]])
            DFS2(Y[H]);
    }
    else if(v[H]==4)
    {
        DFS2(X[H]);
        DFS2(Y[H]);
    }
    else
        C2[H]=true;
    return;
}
int i;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(i=1;i<=N;i++)
    {
        cin>>s;
        if(s[0]=='I')
        {
            cin>>A;
            v[i]=0;
            C1[i]=A;
        }
        else if(s[0]=='N')
        {
            cin>>A;
            v[i]=1;
            X[i]=A;
        }
        else if(s[0]=='A')
        {
            cin>>A>>B;
            v[i]=2;
            X[i]=A;
            Y[i]=B;
        }
        else if(s[0]=='O')
        {
            cin>>A>>B;
            v[i]=3;
            X[i]=A;
            Y[i]=B;
        }
        else if(s[0]=='X')
        {
            cin>>A>>B;
            v[i]=4;
            X[i]=A;
            Y[i]=B;
        }
    }
    DFS1(1);
    DFS2(1);
    for(i=1;i<=N;i++)
        if(v[i]==0)
            cout<<(C1[1]^C2[i]);
    return 0;
}