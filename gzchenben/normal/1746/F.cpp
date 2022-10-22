#include<bits/stdc++.h>
using namespace std;

const int tot = 35;

int n,q,a[300005];
int opt[300005],x[300005],y[300005],k[300005];

long long c[36][300005];
int lowbit(int x)
{
    return x & (-x);
}
void Add(int x,int pos,int val)
{
    // printf("Add %d %d %d\n",x,pos,val);
    while(pos <= n)
    {
        c[x][pos] += val;
        pos += lowbit(pos);
    }
}
long long Query(int x,int pos)
{
    long long res = 0;
    while(pos)
    {
        res += c[x][pos];
        pos -= lowbit(pos);
    }
    // printf("Q %d %d %llu\n",x,pos,res);    
    return res;
}

int mp[36][600005];

unsigned int s = 1e9+7;
int R()
{
    s = (s<<10) + (s>>10) + s + 1e9 + 7;
    return s/2;
}

int main()
{
    vector<int> All;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        All.push_back(a[i]);
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d",&opt[i]);    
        if(opt[i] == 1)
        {
            scanf("%d%d",&x[i],&y[i]);
            All.push_back(y[i]);
        }
        else
        {
            scanf("%d%d%d",&x[i],&y[i],&k[i]);
        }
    }
    sort(All.begin(),All.end());
    All.resize(unique(All.begin(),All.end()) - All.begin());

    for(int i=0;i<All.size();i++)
        for(int j=1;j<=tot;j++)
            mp[j][i] = R();

    for(int i=1;i<=n;i++)
    {
        a[i] = lower_bound(All.begin(),All.end(),a[i]) - All.begin();
        for(int j=1;j<=tot;j++)
            Add(j,i,mp[j][a[i]]);
    }
    for(int i=1;i<=q;i++)
    {
        if(opt[i] == 1)
        {
            y[i] = lower_bound(All.begin(),All.end(),y[i]) - All.begin();
            for(int j=1;j<=tot;j++)
            {
                Add(j,x[i],mp[j][y[i]]-mp[j][a[x[i]]]);
            }
            a[x[i]] = y[i];
        }
        if(opt[i] == 2)
        {
            bool flag=true;
            for(int j=1;j<=tot;j++)
            {
                long long Qr = Query(j,y[i]);
                long long Ql = Query(j,x[i]-1);
                if((Qr - Ql) % k[i] != 0) 
                {
                    flag=false;
                    break;
                } 
            }
            printf(flag ? "YES\n" : "NO\n");
        }
    }
    
}