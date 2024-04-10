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
struct data
{
    int x,y;
    bool operator<(data tmp)const
    {
        if(x!=tmp.x)return x<tmp.x;
        return y<tmp.y;
    }
}a[5111];
int n;
set<data>s;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        s.insert(a[i]);
    }
    int date=0;
    for(set<data>::iterator it=s.begin();it!=s.end();it++)
    {
        if((*it).y>=date)date=(*it).y;else date=(*it).x;
    }
    cout<<date<<endl;
    return 0;
}