#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>

#define ll long long

using namespace std;

set <int> f;
vector < pair <int,int> > q;

int nums[20000002]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    ll n,m;
    cin >> n >> m;
    ll ans=0;
    for(ll b=1;b<=n;b++)
    {
        ll B=b,c=2*b-1,kol=0;
        while(B>=1&&c<=m&&c>=1&&c<=b*b)
        {
            ++nums[10000000+int(-b+sqrt((double)(b*b-c)))];
            ++nums[10000000+int(-b-sqrt((double)(b*b-c)))];
            --B;
            c+=2*B-1;
            ++kol;
        }
        ans+=2*(min(m,b*b)-kol);
    }
    int r=0;
    for(int j=0;j<=20000000;j++)
        if (nums[j]!=0) ++r;
    cout << ans+r << endl;
//  for(set <int>::iterator it=f.begin();it!=f.end();it++)
//      cout << (*it) << endl;
    return 0;
}