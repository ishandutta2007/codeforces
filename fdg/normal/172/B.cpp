#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>

#define ll long long

using namespace std;

int pos[100005];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a,b,m,r0;
    scanf("%d%d%d%d",&a,&b,&m,&r0);
    for(int t=1;;++t) {
        r0=(1LL*a*r0+b)%m;
        if (pos[r0]) {
            printf("%d\n",t-pos[r0]);
            break;
        }
        pos[r0]=t;
    }
    return 0;
}