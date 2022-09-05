//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
inline int getval()
{
    int __res=0;bool __neg=0;
    char __c;__c=getchar();
    while(__c==' '||__c=='\n')__c=getchar();
    while(__c!=' '&&__c!='\n')
    {
        if(__c=='-')__neg=1;
        else __res=__res*10+__c-'0';
        __c=getchar();
    }
    if(__neg)__res=-__res;
    return __res;
}
int n,a[100111],b[100111],c[100111];
map<int,int>ma,mb,mc;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;scanf("%d",&a[i]);
        ma[a[i]]++;
    }
    for(int i=1;i<n;i++)
    {
        int x;scanf("%d",&b[i]);
        mb[b[i]]++;
    }
    for(int i=1;i<n-1;i++)
    {
        int x;scanf("%d",&c[i]);
        mc[c[i]]++;
    }
    for(int i=1;i<=n;i++)if(ma[a[i]]>mb[a[i]])printf("%d\n",a[i]),ma[a[i]]--;
    for(int i=1;i<n;i++)if(mb[b[i]]>mc[b[i]])printf("%d\n",b[i]),mb[b[i]]--;
    return 0;
}