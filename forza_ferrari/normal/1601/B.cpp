#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,a[300001],b[300001],bin[300001],dis[300001],ans[300001],cnt,pre[300001],f[300001];
int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        cin>>b[i];
    for(int i=1;i<n;++i)
        dis[i]=0x3f3f3f3f;
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int k=q.front();
        q.pop();
        if(a[k]==k)
        {
            cout<<dis[k]+1<<endl;
            ans[++cnt]=0;
            for(int i=k;i;i=pre[i])
                ans[++cnt]=i;
            for(int i=cnt-1;i;--i)
                cout<<f[ans[i]]<<" ";
            cout<<endl;
            return 0;
        }
        for(int i=anc(k-a[k]);i<k;i=anc(i+1))
        {
            bin[anc(i)]=anc(i+1);
            if(dis[i+b[i]]!=0x3f3f3f3f)
                continue;
            dis[i+b[i]]=dis[k]+1;
            pre[i+b[i]]=k;
            f[i+b[i]]=i;
            q.push(i+b[i]);
        }
    }
    cout<<-1<<endl;
    return 0;
}