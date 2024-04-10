#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <set>
#include <cstdio>
#include <ctime>

#define ll long long

using namespace std;

int x[1002]={0},y[1002]={0};

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    int n,m,k,t,a,b;
    scanf("%d%d%d%d",&n,&m,&k,&t);
    for(int i=0;i<k;i++)
        scanf("%d%d",&x[i],&y[i]);
    for(int i=0;i<t;i++)
    {
        scanf("%d%d",&a,&b);
        int cnt=0,was=0;
        for(int j=0;j<k;j++)
        {
            if (x[j]<a||x[j]==a&&y[j]<=b) cnt++;
            if (x[j]==a&&y[j]==b) was=1;
        }
        if (was) printf("Waste\n");
        else
        {
            int all=(a-1)*m+b-cnt;
            if (all%3==1) printf("Carrots\n");
            else if (all%3==2) printf("Kiwis\n");
            else printf("Grapes\n");
        }
    }
    return 0;
}