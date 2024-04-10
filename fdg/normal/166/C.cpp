#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,x,a,ans=0;
    scanf("%d%d",&n,&x);
    vector <int> v;
    for(int i=0;i<n;++i) {
        scanf("%d",&a);
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    while(v[(n+1)/2-1]!=x) {
        v.push_back(x);
        sort(v.begin(),v.end());
        ++n; ++ans;
    }
    printf("%d\n",ans);
    return 0;
}