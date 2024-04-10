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

int val[100005]={0},l[100005]={0},r[100005]={0},p[100005]={0};
int le[100005]={0},ri[100005]={0}; 

pair <int,int> calc1(int i)
{
    if (l[i]==-1&&r[i]==-1) return make_pair(val[i],val[i]);
    pair <int,int> lp=calc1(l[i]),rp=calc1(r[i]);
    le[i]=lp.second; ri[i]=rp.first;
    return make_pair(lp.first,rp.second);
}

double m[100005]={0};

void calc2(int i,ll res = 0,int cnt = 0)
{
    if (l[i]==-1&&r[i]==-1) m[i]=1.0*res/cnt;
    else
    {
        calc2(l[i],res+ri[i],cnt+1);
        calc2(r[i],res+le[i],cnt+1);
    }
}

vector <double> v1;
vector <int> v2;

void calc3(int i)
{
    if (l[i]==-1)
    {
        v1.push_back(m[i]);
        v2.push_back(val[i]);
    }
    else
    {
        calc3(l[i]);
        v1.push_back(m[i]);
        v2.push_back(val[i]);
        calc3(r[i]);
    }
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,k,par,vv,root=-1;
    scanf("%d",&n);
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&par,&vv); par--;
        val[i]=vv; p[i]=par;
        if (par!=-2)
        {
            if (l[par]==-1) l[par]=i;
            else
            {
                r[par]=i;
                if (val[l[par]]>val[r[par]]) swap(l[par],r[par]);
            }
        } else root=i;
    }
    for(int i=0;i<100003;i++)
        m[i]=-1;
    calc1(root);
    calc2(root);
//  for(int i=0;i<n;i++)
//      cout << val[i] << " " << m[i] << endl;
    v1.clear();
    v2.clear();
    calc3(root);
    double pp=0;
    for(int i=v1.size()-1;i>=0;i--)
        if (v1[i]!=-1)
        {
            pp=v1[i];
            for(;i<v1.size();i++) v1[i]=pp;
            break;
        }
    for(int i=0;i<v1.size();i++)
    {
        if (v1[i]==-1) v1[i]=pp;
        else pp=v1[i];
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&vv);
        vector <int>::iterator it=upper_bound(v2.begin(),v2.end(),vv);
        int pos=it-v2.begin();
        if (it==v2.end()) pos--;
//      if (v2[pos]>v&&pos>0) pos--;
        printf("%.9lf\n",v1[pos]);
    }
    return 0;
}