//source:
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int n,s,mx;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>s;
    mx=-1;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x<s||(x==s&&y==0))
        {
            mx=max(mx,(100-y)%100);
        }
    }
    cout<<mx;
    return 0;
}