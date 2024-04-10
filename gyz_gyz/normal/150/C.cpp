#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n   150005
#define DB  double
#define For(i,a,b)  for(int i=a;i<=b;i++)

int     N,M,C,A[n];
DB      Ans,X[n],P[n];

struct  Nod{
        DB  L,R,S,Max;

        void    reset(){
            L=max(0.,L);    R=max(0.,R);    Max=max(0.,Max);
        }
        Nod operator +  (const Nod&b){
            Nod c,a=*this;
            c.S=a.S+b.S;
            c.L=max(a.L,a.S+b.L);
            c.R=max(b.R,b.S+a.R);
            c.Max=max(max(a.Max,b.Max),a.R+b.L);
            reset();    return  c;
        }
}T[n<<2];

void    Build(int u,int l,int r){
        if  (l==r)  {
            T[u]=(Nod){X[l],X[l],X[l],X[l]};    T[u].reset();
            return  ;
        }   int Mid=l+r>>1;
        Build(u<<1,l,Mid);  Build(u<<1|1,Mid+1,r);  T[u]=T[u<<1]+T[u<<1|1];
}
Nod     Query(int u,int l,int r,int x,int y){
        if  (x<=l&&r<=y)return  T[u];   int Mid=l+r>>1;
        if  (y<=Mid)    return  Query(u<<1,l,Mid,x,y);
        if  (x>Mid)     return  Query(u<<1|1,Mid+1,r,x,y);
        return  Query(u<<1,l,Mid,x,y)+Query(u<<1|1,Mid+1,r,x,y);
}

int     main(){
        scanf("%d%d%d",&N,&M,&C);
        For(i,1,N)  scanf("%d",&A[i]);  N--;
        For(i,1,N)  scanf("%lf",&P[i]),X[i]=(A[i+1]-A[i])*.5-P[i]/100.*C;

        Build(1,1,N);
        for (int l,r;M--;)
            scanf("%d%d",&l,&r),Ans+=Query(1,1,N,l,r-1).Max;
        printf("%.10lf\n",Ans);
}