#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
int n,p,s,a[3005],b[3005],tag[3005],ans;
priority_queue<pair<int,int> > q1,q2,q3,q4;
int main()
{
    scanf("%d%d%d",&n,&p,&s);
    for(register int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        q1.push(make_pair(a[i],i));
    }
    for(register int i=1;i<=n;++i)
    {
        scanf("%d",&b[i]);
        q2.push(make_pair(b[i],i));
    }
    while(p|s)
    {
        while(!q1.empty()&&tag[q1.top().second])
            q1.pop();
        while(!q2.empty()&&tag[q2.top().second])
            q2.pop();
        while(!q3.empty()&&tag[q3.top().second]!=1)
            q3.pop();
        while(!q4.empty()&&tag[q4.top().second]!=2)
            q4.pop();
        int maxn=0,opt=0;
        if(p&&!q1.empty()&&q1.top().first>maxn)
        {
            maxn=q1.top().first;
            opt=1;
        }
        if(s&&!q2.empty()&&q2.top().first>maxn)
        {
            maxn=q2.top().first;
            opt=2;
        }
        if(s&&!q1.empty()&&!q3.empty()&&q1.top().first+q3.top().first>maxn)
        {
            maxn=q1.top().first+q3.top().first;
            opt=3;
        }
        if(p&&!q2.empty()&&!q4.empty()&&q2.top().first+q4.top().first>maxn)
        {
            maxn=q2.top().first+q4.top().first;
            opt=4;
        }
        ans+=maxn;
        //cout<<opt<<" "<<p<<" "<<s<<endl;
        if(opt==1)
        {
            --p;
            tag[q1.top().second]=1;
            q3.push(make_pair(b[q1.top().second]-q1.top().first,q1.top().second));
        }
        if(opt==2)
        {
            --s;
            tag[q2.top().second]=2;
            q4.push(make_pair(a[q2.top().second]-q2.top().first,q2.top().second));
        }
        if(opt==3)
        {
            --s;
            tag[q1.top().second]=1;
            tag[q3.top().second]=2;
            q4.push(make_pair(-q3.top().first,q3.top().second));
            q3.push(make_pair(b[q1.top().second]-q1.top().first,q1.top().second));
        }
        if(opt==4)
        {
            --p;
            tag[q2.top().second]=2;
            tag[q4.top().second]=1;
            q3.push(make_pair(-q4.top().first,q4.top().second));
            q4.push(make_pair(a[q2.top().second]-q2.top().first,q2.top().second));
        }
    }
    printf("%d\n",ans);
    for(register int i=1;i<=n;++i)
        if(tag[i]==1)
            printf("%d ",i);
    puts("");
    for(register int i=1;i<=n;++i)
        if(tag[i]==2)
            printf("%d ",i);
    puts("");
    return 0;
}