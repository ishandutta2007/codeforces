#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stack>

#define ll long long

using namespace std;

char D[101][101]={0};
int F[101][101]={0};
vector <char> ans;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a,b,c,d,n,x[27]={0},N,M;
    cin >> a >> b >> c >> d >> n;
    N=max(b,d); M=a+c;
    for(int i=0;i<n;i++)
        cin >> x[i];
    for(int i=0;i<max(b,d);i++)
        for(int j=0;j<a+c;j++)
            D[i][j]='.';
    for(int i=0;i<b;i++)
        for(int j=0;j<a;j++)
            D[i][j]='*';
    for(int i=0;i<d;i++)
        for(int j=0;j<c;j++)
            D[i][a+j]='*';
    int cur=1;
    for(int j=a+c-1;j>=a;j--)
    {
        if ((a+c-1-j)%2==((c&1)^1))
        {
            for(int i=d-1;i>=0;i--)
            {
                F[i][j]=cur++;
            }
        }
        else
        {
            for(int i=0;i<d;i++)
                F[i][j]=cur++;
        }
    }
    for(int j=a-1;j>=0;j--)
    {
        if ((a-1-j)%2==0)
        {
            for(int i=0;i<b;i++)
                F[i][j]=cur++;
        }
        else
            for(int i=b-1;i>=0;i--)
                F[i][j]=cur++;
    }
    int l=1,r=0;
    for(int t=0;t<n;t++)
    {
        l=r+1; r=l+x[t]-1;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if (F[i][j]>=l&&F[i][j]<=r&&D[i][j]=='*') D[i][j]='a'+t;
            }
        }
    }
/*  for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout << F[i][j] << "    ";
        }
        cout << endl;
    }*/
    cout << "YES\n";
    for(int i=0;i<max(b,d);i++)
        cout << D[i] << endl;
    return 0;
}