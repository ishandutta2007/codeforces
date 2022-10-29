#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define n   200005
#define I64 long long
#define For(i,a,b)  for(int i=a;i<=b;i++)

I64     Ans,F[n];
int     N,W,C,Gt,G[n],T[n],Now[n],Cnt[n];

struct  Nod{int x,y;}A[n];
bool    Cmp(Nod a,Nod b)    {return a.y<b.y;}

bool    Check(int x,int y,int z){
        return  1ll*(z-x)*(F[y]-F[x])-1ll*(F[z]-F[x])*(y-x)<=0;
}
I64     f(int x,int y)  {return 1ll*x*y+F[x];}

void    Upd(int x)  {
        for (;Now[x]+1<=Cnt[x]&&f(G[Now[x]],T[x])<f(G[Now[x]+1],T[x]);Now[x]++);
}
void    Pre(int x)  {
        int l=(x-1)*300+1,r=x*300;  Cnt[x]=l-1;
        for (int i=l;i<=r;G[++Cnt[x]]=i++)
        for (;Cnt[x]>l&&Check(G[Cnt[x]-1],G[Cnt[x]],i);Cnt[x]--);
        Now[x]=l;   Upd(x);
}
void    Modify(int t){
        int x=1;
        for (;x<C&&x*300<=t;x++)    T[x]++,Upd(x);
        For(i,(x-1)*300+1,t)F[i]+=i;Pre(x);
}

int     main(){
        scanf("%d%d",&N,&W);
        For(i,1,N)  scanf("%d%d",&A[i].x,&A[i].y);
        sort(A+1,A+N+1,Cmp);

        C=100000/300+1; For(i,1,C)  Pre(i);
        for (int c=0,i=1;i<=N;c++){
            printf("%I64d %d\n",1ll*(N-i+1)*c*W+Ans,Gt);
            for (;i<=N&&A[i].y==c;i++)  Modify(A[i].x);

            Ans=Gt=0;
            For(j,1,C)  {
                I64 t=f(G[Now[j]],T[j]);
                if  (t>Ans) Ans=t,Gt=G[Now[j]];
            }
        }   printf("%I64d %d\n",Ans,Gt);
}