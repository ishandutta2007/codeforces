#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<string>
using namespace std;
int p,tip,l,r,tot,l1,l2,i,INF,Sol,n,Q,v1[100009],v2[100009];
struct T
{
    int nr,K,P,S;
    bool rev;
    T *l,*r;
    T(int S,int K,int P,int nr,bool rev,T *l,T *r)
    {
        this->S=S;
        this->P=P;
        this->K=K;
        this->nr=nr;
        this->rev=rev;
        this->l=l;
        this->r=r;
    }
}*R,*nil,*p1,*p2,*p3,*p4,*aux;

int Rand() {return ((rand()%32768)<<15)+(rand()%32768)+1;}

void Splitrev(T *&n)
{
    if(n->rev==0) return ;
    n->rev=0;
    T *aux=n->l;
    n->l=n->r;
    n->r=aux;
    n->l->rev^=1;
    n->r->rev^=1;
}

void reup(T *&n)
{
    n->nr=n->l->nr+n->r->nr+1;
    n->S=n->l->S+n->r->S+n->K;
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
    Splitrev(n);
    if(n->l->P>n->P)
    {
        Splitrev(n->l);
        rotleft(n);
    }
    else
    if(n->r->P>n->P)
    {
        Splitrev(n->r);
        rotright(n);
    }
}

void Insert(T *&n,int Poz,int K,int P)
{
    if(n==nil)
    {
        n=new T(K,K,P,1,0,nil,nil);
        return ;
    }
    Splitrev(n);
    if(n->l->nr>=Poz) Insert(n->l,Poz,K,P);
    else Insert(n->r,Poz-n->l->nr-1,K,P);
    reup(n);
    balance(n);
}

void Erase(T *&n,int Poz)
{
    Splitrev(n);
    if(n->l->nr>=Poz) Erase(n->l,Poz);
    else
    if(n->l->nr+1<Poz) Erase(n->r,Poz-n->l->nr-1);
    else
    {
        if(n->l==nil&&n->r==nil)
        {
            delete n;
            n=nil;
        }
        else
        {
            if(n->l->P>n->r->P)
            {
                Splitrev(n->l);
                rotleft(n);
            }
            else
            {
                Splitrev(n->r);
                rotright(n);
            }
            Erase(n,Poz);
        }
    }
    if(n!=nil) reup(n);
}

void acces(T *&n,int Poz)
{
    Splitrev(n);
    if(n->l->nr>=Poz) acces(n->l,Poz);
    else
    if(n->l->nr+1<Poz) acces(n->r,Poz-n->l->nr-1);
    else
    {
        Sol=n->K;
        return ;
    }
}

void Split(T *&R,T *&Rl,T *&Rr,int Poz)
{
    Insert(R,Poz,0,INF);
    Rl=R->l;
    Rr=R->r;
    delete R;R=nil;
}

void Join(T *&R,T *&Rl,T *&Rr)
{
    R=new T(0,0,0,Rl->nr+Rr->nr+1,0,Rl,Rr);
    Erase(R,Rl->nr+1);
}

void afis(T *&R)
{
    if(R==nil) return ;
    Splitrev(R);
    afis(R->l);
    printf("%d ",R->K);
    afis(R->r);
}
void Get(T *&R,int &nr,int v[])
{
    if(R==nil) return ;
    Splitrev(R);
    Get(R->l,nr,v);
    v[++nr]=R->K;
    Get(R->r,nr,v);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
srand(time(0));
scanf("%d",&n);
scanf("%d",&Q);
INF=(1<<30)+5;
nil=new T(0,0,0,0,0,0,0);
R=nil;
for(i=1;i<=n;i++)
    Insert(R,i-1,1,Rand());
while(Q)
{
    Q--;
    scanf("%d",&tip);
    if(tip==1)
    {
        scanf("%d",&p);
        if(2*p<=R->nr)
        {
            Split(R,p1,aux,p);
            Split(aux,p2,p3,p);
            /*afis(p1);printf("||||");
            afis(p2);printf("||||");
            afis(p3);printf("\n\n");*/
            l1=l2=0;
            Get(p1,l1,v1);
            Get(p2,l2,v2);
            for(i=1;i<=l2;i++)
                v2[i]+=v1[l1-i+1];
            R=p3;
            for(i=l2;i>=1;i--)
                Insert(R,0,v2[i],Rand());
        }
        else
        {
            tot=R->nr;
            p=tot-p;
            Split(R,aux,p3,tot-p);
            Split(aux,p1,p2,tot-2*p);
            /*afis(p1);printf("||||");
            afis(p2);printf("||||");
            afis(p3);printf("\n\n");*/
            l1=l2=0;
            Get(p2,l1,v1);
            Get(p3,l2,v2);
            for(i=1;i<=l2;i++)
                v2[i]+=v1[l1-i+1];
            aux=nil;
            for(i=l2;i>=1;i--)
                Insert(aux,0,v2[i],Rand());
            p1->rev^=1;
            Join(R,aux,p1);
            //return 0;
        }
/*        printf("U ");
        afis(R);
        printf("\n");*/
    }
    else
    {
        scanf("%d%d",&l,&r);
        l++;
        Split(R,p1,aux,l-1);
        Split(aux,p2,p3,r-l+1);
        printf("%d\n",p2->S);
        Join(aux,p1,p2);
        Join(R,aux,p3);
    }
    p1=p2=p3=aux=0;
    //return 0;
}
return 0;
}