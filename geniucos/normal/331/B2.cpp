#include<cstdio>
using namespace std;
int lst,s,aux,Q,n,x1,i,j,arb[300009<<2],tip,ap[300009],a[300009];
void build(int nod,int st,int dr)
{
    if(st==dr)
    {
        arb[nod]=1;
        return ;
    }
    int mij=(st+dr)>>1;
    build(nod<<1,st,mij);
    build((nod<<1)+1,mij+1,dr);
    if(ap[mij]<=ap[mij+1]) arb[nod]=arb[nod<<1]+arb[(nod<<1)+1]-1;
    else arb[nod]=arb[nod<<1]+arb[(nod<<1)+1];
}
void update(int nod,int st,int dr,int poz)
{
    if(st==dr)
    {
        arb[nod]=1;
        return ;
    }
    int mij=(st+dr)>>1;
    if(poz<=mij)
        update(nod<<1,st,mij,poz);
    else
        update((nod<<1)+1,mij+1,dr,poz);
    if(ap[mij]<=ap[mij+1]) arb[nod]=arb[nod<<1]+arb[(nod<<1)+1]-1;
    else arb[nod]=arb[nod<<1]+arb[(nod<<1)+1];
}
void query(int nod,int st,int dr,int x,int y)
{
    if(x<=st&&dr<=y)
    {
        s+=arb[nod];
        if(ap[lst]<=ap[st]&&lst) s--;
        lst=dr;
        return ;
    }
    int mij=(st+dr)>>1,s=0;
    if(x<=mij)
        query(nod<<1,st,mij,x,y);
    if(y>mij)
        query((nod<<1)+1,mij+1,dr,x,y);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&x1);
    a[i]=x1;
    ap[x1]=i;
}
build(1,1,n);
scanf("%d",&Q);
while(Q)
{
    Q--;
    scanf("%d",&tip);
    if(tip==1)
    {
        scanf("%d",&i);
        scanf("%d",&j);
        s=0;lst=0;
        query(1,1,n,i,j);
        printf("%d\n",s);
    }
    else
    {
        scanf("%d",&i);
        scanf("%d",&j);
        aux=ap[a[i]];
        ap[a[i]]=ap[a[j]];
        update(1,1,n,a[i]);
        ap[a[j]]=aux;
        update(1,1,n,a[j]);
        aux=a[i];
        a[i]=a[j];
        a[j]=aux;
    }
}
return 0;
}