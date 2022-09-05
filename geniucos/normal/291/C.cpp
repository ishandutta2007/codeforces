#include<cstdio>
#include<vector>
using namespace std;
int p,cat,dif,po,n,i,j,k,km,a[100009][5],b[5];
char sir[100];
struct str
{
    short p1,p2;
};
vector < str > v[257][257];
vector < str >::iterator it;
str make_str(short p1,short p2)
{
    str aux;
    aux.p1=p1;
    aux.p2=p2;
    return aux;
}
void bag(short v1,short v2,short v3,short v4)
{
    for(it=v[v1][v2].begin();it!=v[v1][v2].end();it++)
        if(it->p1==v3&&it->p2==v4) return ;
    dif++;
    v[v1][v2].push_back(make_str(v3,v4));
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d\n",&km);
for(i=1;i<=n;i++)
{
    gets(sir+1);
    po=1;
    for(j=1;j<=4;j++)
    {
        while(sir[po]>='0'&&sir[po]<='9')
        {
            a[i][j]=a[i][j]*10+sir[po]-48;
            po++;
        }
        po++;
    }
}
for(i=1;i<=32;i++)
{
    if(i==9)
        cat=0;
    for(j=1;8*j<=i;j++)
        b[j]=255;
    cat=i%8;
    for(p=7;p>=7-cat+1;p--)
        b[j]|=(1<<p);
    for(j=j+1;j<=4;j++)
        b[j]=0;
    dif=0;
    for(j=1;j<=n;j++)
    {
        bag((a[j][1]&b[1]),(a[j][2]&b[2]),(a[j][3]&b[3]),(a[j][4]&b[4]));
        if(dif>km) break;
    }
    if(dif==km)
    {
        printf("%d.%d.%d.%d\n",b[1],b[2],b[3],b[4]);
        return 0;
    }
    for(k=0;k<256;k++)
        for(j=0;j<256;j++)
            v[k][j].clear();
}
printf("-1\n");
return 0;
}