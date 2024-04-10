#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <list>
#include <cmath>

#define ll long long

using namespace std;

struct target{
    target(double a,double b,double c,double d) : x(a), y(b), t(c), p(d) {mm=0; kol=0;};
    double x,y,t,p,mm;
    int kol;
};

bool operator < (const target & a,const target & b)
{
    return a.t<b.t;
}

double dist(const target & a,const target & b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    double a,b,c,d,mx=0,r=0;
    vector <target> v;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b >> c >> d;
        v.push_back(target(a,b,c,d));
    }
    sort(v.begin(),v.end());
    bool end[1002]={0};
    for(int i=0;i<n;i++)
    {
//      if (v[i].kol!=0) v[i].mm/=v[i].kol;
        v[i].mm+=v[i].p;
        for(int j=i+1;j<n;j++)
        {
            if (dist(v[i],v[j])<=v[j].t-v[i].t)
            {
                end[i]=true;
                if (v[j].mm<v[i].mm) v[j].mm=v[i].mm;
                v[j].kol++;
            }
        }
        if (mx<v[i].mm) mx=v[i].mm;
//      if (end[i]==false) mx+=v[i].mm,r++;
    }
    cout.precision(15);
    cout << mx << endl;
    return 0;
}