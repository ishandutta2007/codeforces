#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int gcd(int a,int b) {return b==0 ? a : gcd(b,a%b);};

int res[1004]={0};
vector < pair <int,int> > v;

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,a;
    scanf("%d%d",&n,&m);
    v.clear();
    for(int i=0;i<m;i++)
    {
        scanf("%d",&a);
        v.push_back(make_pair(a,i+1));
    }
    sort(v.rbegin(),v.rend());
    int sum=0;
    for(int i=0;i<v.size();i++)
    {
        if (v[i].first>(n/2)) v[i].first=(n/2);
        sum+=v[i].first;
    }
    if (sum<n||m==1)
    {
        printf("-1\n");
        return 0;
    }
    int kol[50]={0};
    for(int i=0;i<v.size();i++)
        kol[i]=v[i].first;
    if (n&1)
    {
        res[0]=v[1].second;
        kol[1]--;
        int cur=1,num=0;
        while(cur<n)
        {
            while(cur<n&&kol[num]>0)
            {
                res[cur]=v[num].second;
                cur+=2;
                kol[num]--;
            }
            if (kol[num]==0) num++;
        }
        cur=2;
        while(cur<n)
        {
            while(cur<n&&kol[num]>0)
            {
                res[cur]=v[num].second;
                cur+=2;
                kol[num]--;
            }
            if (kol[num]==0) num++;
        }
    }
    else
    {
        int cur=0,num=0;
        while(cur<n)
        {
            while(cur<n&&kol[num]>0)
            {
                res[cur]=v[num].second;
                cur+=2;
                kol[num]--;
            }
            if (kol[num]==0) num++;
        }
        cur=1;
        while(cur<n)
        {
            while(cur<n&&kol[num]>0)
            {
                res[cur]=v[num].second;
                cur+=2;
                kol[num]--;
            }
            if (kol[num]==0) num++;
        }
    }
    bool ok=(res[0]!=res[n-1]);
    for(int i=1;i<n;i++)
    {
        if (res[i-1]==res[i]) ok=false;
    }
    if (ok)
    {
        printf("%d",res[0]);
        for(int i=1;i<n;i++)
            printf(" %d",res[i]);
        printf("\n");
    }
    else
        printf("-1\n");
    return 0;
}