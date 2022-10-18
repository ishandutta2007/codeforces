#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <set>

#define ll long long

using namespace std;

char S[5][5]={0};
char D[300][300]={0};

bool isBlack(int x,int y,int N,int n)
{
    if (N==n)
    {
        if (S[x][y]=='*') return true;
        return false;
    }
    int side=N/n;
    if (S[x/side][y/side]=='*') return true;
    return isBlack(x-(x/side)*side,y-(y/side)*side,N/n,n);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,DIM;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        cin >> S[i];
    DIM=1;
    for(int i=0;i<k;i++)
        DIM*=n;
    for(int i=0;i<DIM;i++)
        for(int j=0;j<DIM;j++)
            if (isBlack(i,j,DIM,n)) D[i][j]='*';
            else D[i][j]='.';
    for(int i=0;i<DIM;i++)
        printf("%s\n",D[i]);
    return 0;
}