#include<iostream>
#include<cstdio>
using namespace std;
int t,p,f,cnts,cntw,s,w,ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d%d%d%d%d",&p,&f,&cnts,&cntw,&s,&w);
        if(s>w)
        {
            s^=w^=s^=w;
            cnts^=cntw^=cnts^=cntw;
        }
        for(register int i=0;i<=cnts&&i*s<=p;++i)
        {
            int cnt=0,t1=cnts,t2=cntw,t3,t4,t5;
            cnt+=i;
            t1-=i;
            t3=min((p-i*s)/w,t2);
            cnt+=t3;
            t2-=t3;
            t4=min(f/s,t1);
            cnt+=t4;
            t1-=t4;
            t5=min((f-t4*s)/w,t2);
            cnt+=t5;
            ans=max(ans,cnt);
        }
        printf("%d\n",ans);
    }
    return 0;
}