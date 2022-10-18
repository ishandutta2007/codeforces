#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int p[4]={0},a,b,ans=0;
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;
    sort(p,p+4);
    for(int i=a;i<=b;i++)
    {
        int kol=0;
        do{
            int cur=i;
            for(int j=0;j<4;j++)
            cur%=p[j];
            if (i==cur) kol++;
        }while(next_permutation(p,p+4));
        if (kol>=7) ans++;
    }
    cout << ans << endl;
    return 0;
}