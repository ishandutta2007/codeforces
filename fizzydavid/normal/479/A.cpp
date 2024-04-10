//while(true)rp++;
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
const ll INF=1<<28;
const ll LINF=1ll<<61;
int a,b,c;
int main()
{
    ios::sync_with_stdio(false);
    cin>>a>>b>>c;
    cout<<max(a+b*c,max(a*b+c,max(a*b*c,max(a+b+c,max((a+b)*c,a*(b+c))))));
    return 0;
}