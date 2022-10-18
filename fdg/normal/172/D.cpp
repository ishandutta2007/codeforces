#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <ctime>

#define ll long long

using namespace std;

int sq[10000004];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int a,n;
    scanf("%d%d",&a,&n);
    for(int i=1,j=3;i<=10000000;i+=j,j+=2) {
        for(int t=i;t<=10000000;t+=i)
            sq[t]=i;
    }
    long long ans=0;
    for(int i=0;i<n;++i)
        ans+=(a+i)/sq[a+i];
    cout << ans << endl;
    return 0;
}