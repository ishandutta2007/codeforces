#include<bits/stdc++.h>
using namespace std;
struct PP
{
    int p,q,r;
};
struct comp
{
    bool operator()(PP X,PP Y)
    {
        return X.q>Y.q;
    }
};
priority_queue<PP,vector<PP>,comp>pq;
PP pp;
vector<int>vv;
int a[123456],b[123456],ch[2345678];
int i,j,n,q,x,y,s,k,l;
int main()
{
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);
        pp.p=i;
        pp.q=x;
        pp.r=y;
        pq.push(pp);
    }
    ch[0]=1;
    s=1;
    j=0;
    vv.push_back(0);
    for(i=0;i<q;i++)
    {
        pp=pq.top();
        pq.pop();
        while(j<pp.q)
        {
            if(ch[a[j]])
            {
                s=(s*2)%1000000007;
            }
            else
            {
                l=vv.size();
                for(k=0;k<l;k++)
                {
                    ch[vv[k]^a[j]]=1;
                    vv.push_back(vv[k]^a[j]);
                }
            }
            j++;
        }
        if(ch[pp.r])
        {
            b[pp.p]=s;
        }
        else
        {
            b[pp.p]=0;
        }
    }
    for(i=0;i<q;i++)
    {
        printf("%d\n",b[i]);
    }
    return 0;
}