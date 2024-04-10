#include<cstdio>
#include<algorithm>
using namespace std;
int l,r,edu[100005],edv[100005],edx[100005],top;
void add(int x,int y,int v)
{
    top++;
    edu[top]=x;
    edv[top]=y;
    edx[top]=v;
}
int st[30],len[30];
void init()
{
    len[1]=1;
    st[1]=1;
    for(int i=2;i<=25;i++)
    {
        st[i]=2;
        if(i==2) len[i]=1;
        else len[i]=len[i-1]*2;
        int Now=1;
        for(int j=1;j<i;j++)
        {
            add(j,i,Now+1-st[j]);
            Now+=len[j];
        }
    }
}
int main()
{
    init();
    scanf("%d%d",&l,&r);
    if(l==1)
    {
        add(1,26,1);
        l++;
    }
    int len=(r-l+1);
    for(int i=0;i<=25;i++)
    {
        if(len&(1<<i)) 
        {
            add(i+2,26,l-1);
            l+=(1<<i);
        }
    }
    printf("YES\n");
    printf("26 %d\n",top);
    for(int i=1;i<=top;i++)
    {
        printf("%d %d %d\n",edu[i],edv[i],min(edx[i],1000000));
    }
}
/*
0
1
1 2
1 2 3 4
1 2 3 4 5 6 7 8 
*/