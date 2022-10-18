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
#define INF 10000000

using namespace std;

int B[1002]={0},A[1002]={0},Min[1002]={0};
bool used[1002]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&B[i]);
    Min[0]=1; B[0]=1;
    for(int i=1;i<=n;i++)
        Min[i]=min(Min[i-1],B[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if (used[j]) continue;
            if (B[j]==0&&(j-k<=0||Min[j-k]>0))
            {
                A[i]=j;
                used[j]=true;
                for(int t=0;t+k+1<=j;t++)
                {
                    if (!used[t+1])
                    {
                        B[t+1]--;
                    }
                    else Min[t+1]=Min[t];
                }
                break;
            }
        }
        for(int t=0;t<n/*+k+1<=A[i]*/;t++)
        {
            if (!used[t+1])
            {
                if (t==0) Min[t+1]=B[t+1];
                else Min[t+1]=min(Min[t],B[t+1]);
            }
            else Min[t+1]=Min[t];
        }
    }
    for(int i=0;i<n;i++)
    {
        if (i!=0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    return 0;
}