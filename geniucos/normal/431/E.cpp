#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int tip,i,vi,n,m,a[400009];
long long eps,x,ceva;
double Rq=0;
double p,u,mij,ras;
struct T
{
    int K,P,nr;
    long long s;
    T *l,*r;
    T(int k,int p,long long s,int nr,T *l,T *r)
    {
        this->K=k;
        this->P=p;
        this->nr=nr;
        this->l=l;
        this->r=r;
        this->s=s;
    }
}*R,*nil;
int Rand(){return ((rand()%32768)<<15)+rand()%32768;}
void reup(T *&n)
{
    n->nr=n->l->nr+n->r->nr+1;
    n->s=(long long)n->l->s+n->r->s+n->K;
}

void rotleft(T *&n)
{
    T *t=n->l;
    n->l=t->r;t->r=n;
    reup(n);
    reup(t);
    n=t;
}

void rotright(T *&n)
{
    T *t=n->r;
    n->r=t->l;t->l=n;
    reup(n);
    reup(t);
    n=t;
}

void balance(T *&n)
{
    if(n->l->P>n->P) rotleft(n);
    else
    if(n->r->P>n->P) rotright(n);
}
void Insert(T *&n,int K)
{
    if(n==nil)
    {
        n=new T(K,Rand(),K,1,nil,nil);
        return ;
    }
    if(n->K>K) Insert(n->l,K);
    else Insert(n->r,K);
    reup (n);
    balance(n);
}
void Erase(T *&n,int K)
{
    if(n->K>K) Erase(n->l,K);
    else
    if(n->K<K) Erase(n->r,K);
    else
    if(n->K==K)
    {
        if(n->l==nil&&n->r==nil){delete n;n=nil;}
        else
        {
            if(n->l->P>n->r->P) rotleft(n),Erase(n->r,K);
            else rotright(n),Erase(n->l,K);
        }
    }
    if(n!=nil) reup (n);
}
void Qr(T *&n,double v)
{
    if(n==nil) return;
    if(n->K<=v)
    {
        Rq+=(double)v*(n->l->nr+1)-(n->l->s+n->K);
        Qr(n->r,v);
        return;
    }
    Qr(n->l,v);
}
bool ok(double mij)
{
    Rq=0;
    Qr(R,mij);
//    return (Rq>=ceva);
    return (Rq-ceva>=eps);
}
void afis(T *&n)
{
    if(n==nil) return;
    afis(n->l);
    printf("%d ",n->K);
    afis(n->r);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
srand(time(0));
scanf("%d",&n);
scanf("%d",&m);
nil=new T(0,0,0,0,NULL,NULL);
scanf("%d",&a[1]);
R=new T(a[1],Rand(),a[1],1,nil,nil);
for(i=2;i<=n;i++)
    scanf("%d",&a[i]),Insert(R,a[i]);
eps=0.000001;
while(m)
{
    m--;
    scanf("%d",&tip);
    if(tip==1)
    {
        scanf("%d%d",&i,&vi);
        Erase(R,a[i]);
        a[i]=vi;
        Insert(R,vi);
    }
    else
    {
        scanf("%I64d",&ceva);
        x=ceva/4+a[1];
        p=0;
        u=(double)20000000000000000;
        while(u-p>0.00001)
        {
            mij=(double)p+(double)(u-p)/2.0;
            if(ok(mij)==0) p=mij+eps;
            else
            {
                ras=mij;
                u=mij-eps;
            }
            //printf("%.10lf %.10lf\n",p,u);
        }
        printf("%.5f\n",ras);
    }
    /*afis(R);
    printf("\n");*/
}
return 0;
}