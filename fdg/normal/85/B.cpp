#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stack>

#define ll long long

using namespace std;

struct ev{
    ev(ll _tm = 0,int _num = 0,int _type = 0) : tm(_tm), num(_num), type(_type) {};
    int num,type;
    ll tm;
};

bool operator < (const ev & a,const ev & b)
{
    return a.tm<b.tm||a.tm==b.tm&&a.num<b.num||a.tm==b.tm&&a.num==b.num&&a.type<b.type;
}

int c[100005]={0};
ll end[100005]={0};
priority_queue <ll> q[3];
priority_queue <ev> Q;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int k1,k2,k3,t[3],n;
    cin >> k1 >> k2 >> k3 >> t[0] >> t[1] >> t[2] >> n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c[i]);
        Q.push(ev(-c[i],i,0));
    }
    if (k1>n) k1=n;
    if (k2>n) k2=n;
    if (k3>n) k3=n;
    for(int i=0;i<k1;i++) q[0].push(0);
    for(int i=0;i<k2;i++) q[1].push(0);
    for(int i=0;i<k3;i++) q[2].push(0);
    while(!Q.empty())
    {
        ev top=Q.top();
        Q.pop();
        if (top.type==3) continue;
        ll tm=min(q[top.type].top(),top.tm); q[top.type].pop();
        q[top.type].push(tm-t[top.type]);
        end[top.num]=t[top.type]-tm;
        Q.push(ev(tm-t[top.type],top.num,top.type+1));
    }
    ll ret=0;
    for(int i=0;i<n;i++)
        ret=max(end[i]-c[i],ret);
    cout << ret << endl;
    return 0;
}