#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <ctime>
#include <map>

#define ll long long

using namespace std;


int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    long long a,b,x1,y1,x2,y2,ans=0,v1=0,v2=0;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    long long l=x1+y1,r=x2+y2;
    if (l>r) swap(l,r);
    long long l1=l/(2*a)+(l>0 ? 1 : 0),r1=r/(2*a)+(r>0 ? 0 : -1);
    if (r1>=l1) v1=r1-l1+1;
    l=x1-y1,r=x2-y2;
    if (l>r) swap(l,r);
    l1=l/(2*b)+(l>0 ? 1 : 0),r1=r/(2*b)+(r>0 ? 0 : -1);
    if (r1>=l1) v2=r1-l1+1;
    ans=max(v1,v2);
    cout << ans << endl;
    return 0;
}