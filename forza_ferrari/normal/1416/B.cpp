#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int t,n,a[10001],num;
struct node
{
    int x,y,z;
    node(int x_,int y_,int z_):
        x(x_),y(y_),z(z_){}
};
vector<node> v;
int main()
{
    scanf("%d",&t);//
    while(t--)
    {
        scanf("%d",&n);
        num=0;
        v.clear();
        for(register int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            num+=a[i];
        }
        if(num%n)
        {
            puts("-1");
            continue;
        }
        num/=n;
        for(register int i=2;i<=n;++i)
        {
            int sum=(i-a[i]%i)%i;
            if(sum)
                v.push_back(node(1,i,sum));
            a[1]-=sum;
            a[i]+=sum;
            v.push_back(node(i,1,a[i]/i));
            a[1]+=a[i];
            a[i]=0;
        }
        for(register int i=2;i<=n;++i)
            v.push_back(node(1,i,num));
        printf("%d\n",(int)v.size());
        for(register int i=0;i<(int)v.size();++i)
            printf("%d %d %d\n",v[i].x,v[i].y,v[i].z);
    }
    return 0;
}