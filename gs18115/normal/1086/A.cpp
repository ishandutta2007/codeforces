#include<iostream>
#include<vector>
#include<algorithm>
#define EB emplace_back
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
vector<PL>V;
int X1,X2,X3;
int Y1,Y2,Y3;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>X1>>Y1;
    cin>>X2>>Y2;
    cin>>X3>>Y3;
    if(X1>X3)
    {
        swap(X1,X3);
        swap(Y1,Y3);
    }
    if(X2>X3)
    {
        swap(X2,X3);
        swap(Y2,Y3);
    }
    if(X1>X2)
    {
        swap(X1,X2);
        swap(Y1,Y2);
    }
    int i;
    if(Y1<=Y2)
    {
        if(Y2<=Y3)
        {
            for(i=X1;i<=X2;i++)
                V.EB(i,Y1);
            for(i=Y1;i<=Y2;i++)
                V.EB(X2,i);
            for(i=X2;i<=X3;i++)
                V.EB(i,Y2);
            for(i=Y2;i<=Y3;i++)
                V.EB(X3,i);
        }
        else if(Y1<=Y3)
        {
            for(i=Y1;i<=Y3;i++)
                V.EB(X1,i);
            for(i=X1;i<=X3;i++)
                V.EB(i,Y3);
            for(i=Y3;i<=Y2;i++)
                V.EB(X2,i);
        }
        else
        {
            for(i=X1;i<=X2;i++)
                V.EB(i,Y1);
            for(i=Y1;i<=Y2;i++)
                V.EB(X2,i);
            for(i=X2;i<=X3;i++)
                V.EB(i,Y1);
            for(i=Y1;i>=Y3;i--)
                V.EB(X3,i);
        }
    }
    else
    {
        if(Y2>=Y3)
        {
            for(i=X1;i<=X2;i++)
                V.EB(i,Y1);
            for(i=Y1;i>=Y2;i--)
                V.EB(X2,i);
            for(i=X2;i<=X3;i++)
                V.EB(i,Y2);
            for(i=Y2;i>=Y3;i--)
                V.EB(X3,i);
        }
        else if(Y1>=Y3)
        {
            for(i=Y1;i>=Y3;i--)
                V.EB(X1,i);
            for(i=X1;i<=X3;i++)
                V.EB(i,Y3);
            for(i=Y3;i>=Y2;i--)
                V.EB(X2,i);
        }
        else
        {
            for(i=X1;i<=X2;i++)
                V.EB(i,Y1);
            for(i=Y1;i>=Y2;i--)
                V.EB(X2,i);
            for(i=X2;i<=X3;i++)
                V.EB(i,Y1);
            for(i=Y1;i<=Y3;i++)
                V.EB(X3,i);
        }
    }
    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());
    cout<<V.size();
    for(i=0;i<V.size();i++)
        cout<<'\n'<<V[i].first<<' '<<V[i].second;
    cout<<endl;
    return 0;
}