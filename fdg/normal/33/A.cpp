#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    vector <int> mn(m,10000000);
    for(int i=0;i<n;i++)
    {
        int r,c;
        scanf("%d%d",&r,&c);
        if (mn[r-1]>c) mn[r-1]=c;
    }
    int kol=0;
    for(int i=0;i<m;i++)
        if (mn[i]!=10000000) kol+=mn[i];
    if (kol>=k) printf("%d\n",k);
    else printf("%d\n",kol);
    return 0;
}