/*
while(true)rp++;
*/
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
int n,m,a,b;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>a>>b;
    if(b<=a*m)
    {
        cout<<n/m*b+min(b,a*(n-n/m*m));
    }
    else
    {
        cout<<n*a;
    }
    return 0;
}