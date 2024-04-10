#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>

#define ll long long

using namespace std;

char str[30003][22];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
        gets(str[i]);
    int ans=0;
    for(int t=strlen(str[0]);t>0;--t) {
        bool ok=true;
        for(int i=1;i<n;++i)
            if (str[i][ans]!=str[0][ans]) ok=false;
        if (ok) ++ans;
        else break;
    }
    printf("%d\n",ans);
    return 0;
}