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
ll n,a[100111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    ll x=-LINF;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x=max(x,a[i]);
    }
    cout<<x<<endl;
    return 0;
}