#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 4010
using namespace std;
char s[N],t[N];
int a[N],b[N];
int ca[5],cb[5];
vector<int>ans;
void rev(int a[],int l,int r)
{
    reverse(a+l,a+r+1);
    for(int i=l;i<=r;i++)
    if(a[i]==1 || a[i]==2) a[i]=3-a[i];
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T --> 0)
    {
        int rv=0;
        ans.clear();memset(ca,0,sizeof(ca)),memset(cb,0,sizeof(cb));
        scanf("%s%s",s+1,t+1);
        int n=strlen(s+1);
        if(strlen(t+1)!=n){puts("-1");continue;}
        if(n&1)
        {
            if(s[n]!=t[n]){puts("-1");continue;}
            n--;
        }
        for(int i=2;i<=n;i+=2) a[i/2]=(s[i-1]-'0')*2+(s[i]-'0'),ca[a[i/2]]++;
        for(int i=2;i<=n;i+=2) b[i/2]=(t[i-1]-'0')*2+(t[i]-'0'),cb[b[i/2]]++;
        n/=2;
        if(ca[0]!=cb[0] || ca[3]!=cb[3]){puts("-1");continue;}
        if(ca[1]!=cb[2])
        {
            int d=0;
            bool can=false;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) ++d;
                if(a[i]==2) --d;
                if(ca[1]-d==cb[2]){can=true;ans.push_back(i*2);rev(a,1,i);break;}
            }
            d=0;
            if(!can)
            for(int i=1;i<=n;i++)
            {
                if(b[i]==2) ++d;
                if(b[i]==1) --d;
                if(cb[2]-d==ca[1]){rv=i*2;rev(b,1,i);break;}
            }
        }
        for(int i=n;i>=1;i--)
            for(int j=n-i+1;j<=n;j++)
            if((b[i]==0 && a[j]==0) || (b[i]==1 && a[j]==2) || (b[i]==2 && a[j]==1) || (b[i]==3 && a[j]==3))
            {
                if(j!=1) ans.push_back((j-1)*2),rev(a,1,j-1);
                ans.push_back(j*2),rev(a,1,j);break;
            }
        if(rv) ans.push_back(rv);
        printf("%d\n",(int)ans.size());
        for(int v:ans) printf("%d ",v);puts("");
    }
    return 0;
}