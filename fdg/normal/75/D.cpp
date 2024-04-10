#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

#define ll long long

using namespace std;

vector < vector <int> > v;
int arr[250005]={0};
int sum_all[52]={0};
int mn_r[52]={0};
int mn_l[52]={0};
ll sum_r[250005]={0};
ll m_r[250005]={0};
bool used[52]={0};

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,l;
    scanf("%d%d",&n,&m);
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&l);
        v[i].resize(l);
        for(int j=0;j<l;j++)
            scanf("%d",&v[i][j]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
        arr[i]--; used[arr[i]]=true;
    }
    for(int i=0;i<n;i++)
    {
        sum_all[i]=v[i][0];
        for(int j=1;j<v[i].size();j++)
            sum_all[i]+=v[i][j];
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        mn_r[i]=0;
        for(int j=v[i].size()-1;j>=0;j--)
        {
            sum+=v[i][j];
            mn_r[i]=min(mn_r[i],sum);
        }
    }
    for(int i=0;i<n;i++)
    {
        int sum=0;
        mn_l[i]=0;
        for(int j=0;j<v[i].size()-1;j++)
        {
            sum+=v[i][j];
            mn_l[i]=min(mn_l[i],sum);
        }
    }
    m_r[m]=0;
//  m_r[m-1]=mn_r[arr[m-1]];
    ll cur=0;
    for(int i=m-1;i>=0;i--)
    {
        m_r[i]=cur+mn_r[arr[i]];
        cur+=sum_all[arr[i]];
        sum_r[i]=cur;
    }
    for(int i=m-1;i>=0;i--)
        m_r[i]=min(m_r[i],m_r[i+1]);
    ll best=v[arr[0]][0];
    for(int l=0;l<m;l++)
    {
        cur=sum_r[l]-mn_l[arr[l]]-m_r[l+1];
        if (best<cur) best=cur;
    }
    for(int i=0;i<n;i++)
    {
        if (!used[i]) continue;
        ll rsum[5002]={0}; rsum[v[i].size()]=0;
        for(int j=v[i].size()-1;j>=0;j--)
            rsum[j]=rsum[j+1]+v[i][j];
        ll rmin[5002]={0}; rmin[v[i].size()]=0;
        for(int j=v[i].size()-1;j>=0;j--)
            rmin[j]=min(rmin[j+1],rsum[j]);
        for(int l=0;l<v[i].size();l++)
        {
            cur=rsum[l]-rmin[l+1];
            if (cur>best) best=cur;
        }
    }
    cout << best << endl;
    return 0;
}