#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

const double Pi=3.1415926535897932384626;

struct ball{
    ball(int a,int b) : x(a), c(b) {};
    int x,c;
};

bool operator <(const ball & a,const ball & b)
{
    if (a.x<b.x) return true;
    return false;
}

ll dp[3005][3005]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,b;
    scanf("%d",&n);
    vector <ball> v;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        v.push_back(ball(a,b));
    }
    sort(v.begin(),v.end());
    dp[0][0]=v[0].c;
    for(int i=1;i<n;i++)
    {
        ll mn=0;
        bool finded=false;
        for(int j=0;j<i;j++)
            if (finded==false||mn>dp[i-1][j])
            {
                mn=dp[i-1][j];
                finded=true;
            }
        dp[i][i]=mn+v[i].c;
        for(int j=0;j<i;j++)
        {
            dp[i][j]=dp[i-1][j]+v[i].x-v[j].x;
        }
    }
    ll ans=0;
    bool f=false;
    for(int i=0;i<n;i++)
        if (f==false||ans>dp[n-1][i])
        {
            ans=dp[n-1][i];
            f=true;
        }
    cout << ans << endl;
    return 0;
}