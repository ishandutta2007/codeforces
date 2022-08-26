#include<bits/stdc++.h>
#define maxn 305

using namespace std;
int n,k,t[maxn*maxn][6],p;

void solve(int x)
{
    if (x==3) {
        t[p][0]=3;
        t[p][1]=1;
        t[p][2]=2;
        t[p][3]=3;p++;
        t[p][0]=3;
        t[p][1]=1;
        t[p][2]=2;
        t[p][3]=3;p++;
    }
    else if (x==4){
        t[p][0]=3;
        t[p][1]=1;
        t[p][2]=2;
        t[p][3]=3;p++;
        t[p][0]=3;
        t[p][1]=1;
        t[p][2]=2;
        t[p][3]=4;p++;
        t[p][0]=3;
        t[p][1]=1;
        t[p][2]=3;
        t[p][3]=4;p++;
        t[p][0]=3;
        t[p][1]=2;
        t[p][2]=3;
        t[p][3]=4;p++;
    }
    else {
        solve(x-2);
        for (int i=1;i<=(x-3)/2;i++){
            t[p][0]=4;
            t[p][1]=x-1;
            t[p][2]=i*2-1;
            t[p][3]=x;
            t[p][4]=i*2;p++;
            t[p][0]=4;
            t[p][1]=x-1;
            t[p][2]=i*2-1;
            t[p][3]=x;
            t[p][4]=i*2;p++;
        }
        if (x&1){
            t[p][0]=3;
            t[p][1]=x-2;
            t[p][2]=x-1;
            t[p][3]=x;p++;
            t[p][0]=3;
            t[p][1]=x-2;
            t[p][2]=x-1;
            t[p][3]=x;p++;
        }
        else {
            t[p][0]=3;
            t[p][1]=x-3;
            t[p][2]=x-1;
            t[p][3]=x;p++;
            t[p][0]=3;
            t[p][1]=x-2;
            t[p][2]=x-1;
            t[p][3]=x;p++;
            t[p][0]=4;
            t[p][1]=x-3;
            t[p][2]=x-1;
            t[p][3]=x-2;
            t[p][4]=x;p++;
        }
    }
}

int main()
{
    cin >> n;
    solve(n);
    cout << p << endl;
    for (int i=0;i<p;i++)
    {
        printf("%d",t[i][0]);
        for (int j=1;j<=t[i][0];j++) printf(" %d",t[i][j]);
        printf("\n");
    }
    return 0;
}