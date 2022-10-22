#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
//typedef tuple<int,int,int> TP;
typedef tuple<int,int,int,int> TP;
const int N=3e5+5;
const ll MOD=1e9+7;
ll n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n&1) cout<<0;
    else cout<<(1LL<<(n/2));
    return 0;
}