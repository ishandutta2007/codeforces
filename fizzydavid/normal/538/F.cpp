//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;

//My own input/output stream
#define input1(x) x=getnum()
#define input2(x,y) input1(x),y=getnum()
#define input3(x,y,z) input2(x,y),z=getnum()
#define input4(x,y,z,w) input3(x,y,z),w=getnum()
#define output1(x) putnum(x)
#define output2(x,y) output1(x),putnum(y)
#define output3(x,y,z) output2(x,y),putnum(z)
#define output4(x,y,z,w) output3(x,y,z),putnum(w)
inline ll getnum()
{
    register ll r=0;register bool ng=0;register char c;c=getchar();
    while(c!='-'&&(c<'0'||c>'9'))c=getchar();
    if(c=='-')ng=1,c=getchar();
    while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
    if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
    if(x<0)putchar('-'),x=-x;
    register short a[20]={},sz=0;
    while(x>0)a[sz++]=x%10,x/=10;
    if(sz==0)putchar('0');
    for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}

int n,a[200111],ans[200111];
int main()
{
    input1(n);
    for(int i=0;i<n;i++)
        input1(a[i]);
    for(int i=1;i<n;i++)
    {
        int tmp=0,j;
        for(j=1;j*j<=(i-1);j++)
        {
            if(a[i]<a[(i-1)/j])
                ans[j]++,ans[j+1]--;
            tmp=j;
        }
        int pre=n-1;
        for(j=1;j*j<(i-1);j++)
        {
            if(pre-(i-1)/j>0&&a[i]<a[j-1])
                ans[(i-1)/j+1]++,ans[pre+1]--;
            pre=(i-1)/j;
        }
        if(pre-tmp>0&&a[i]<a[j-1])
        {
            ans[tmp+1]++,ans[pre+1]--;
        }
    }
    int sum=0;
    for(int i=1;i<n;i++)
        sum+=ans[i],putnum(sum),putsp();
    return 0;
}