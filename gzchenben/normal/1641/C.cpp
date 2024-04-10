#include<cstdio>
#include<algorithm>
using namespace std;
int n,q;
bool sick[200005];

struct Node
{
    int L,R;
    int ToL,ToR;
    bool flag;
}a[200005];
int F[200005];
int Find(int x)
{
    return F[x] == x ? x : F[x]=Find(F[x]);
}
void Merge(int x,int y)
{
    if(x>y) swap(x,y);
    x=Find(x);
    y=Find(y);
    if(x==y) return;
    a[x].R=a[y].R;
    if(a[x].ToL==-1 || a[y].ToL==-1) a[x].ToL=a[x].ToL+a[y].ToL+1;
    else a[x].ToL=max(a[x].ToL,a[y].ToL);
    if(a[x].ToR==-1 || a[y].ToR==-1) a[x].ToR=a[x].ToR+a[y].ToR+1;
    else a[x].ToR=min(a[x].ToR,a[y].ToR);
    a[x].flag=true;
    F[y]=x;
}

int main()
{
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) 
    {
        F[i]=i;
        a[i].ToL=a[i].ToR=-1;
        a[i].L=a[i].R=i;
    }
    for(int i=1;i<=q;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        if(tmp==0)
        {
            int L,R,x;
            scanf("%d%d%d",&L,&R,&x);
            if(x==0)
            {
                int Fir=Find(R);
                if(R!=n && a[Find(R+1)].flag) Fir=Find(R+1);
                a[Fir].flag=true;
                while(Fir>L)
                {
                    Merge(Fir,Find(Fir-1));
                    Fir=Find(Fir);
                }
                if(Fir==L)
                {
                    if(L!=1 && a[Find(L-1)].flag) Merge(Fir,Find(Fir-1));
                }
            }
            if(x==1)
            {
                //if(L!=1)
                //{
                    a[Find(L)].ToR=(a[Find(L)].ToR == -1) ? R : min(a[Find(L)].ToR,R);
                //}
                //if(R!=n)
                //{
                    a[Find(R)].ToL=(a[Find(R)].ToL == -1) ? L : max(a[Find(R)].ToL,L);
                //}
                if(L==R) sick[L]=true;
            }
        }
        if(tmp==1)
        {
            int x;
            scanf("%d",&x);
            if(a[Find(x)].flag) 
            {
                printf("NO\n");
                continue;
            }
            if(sick[x])
            {
                printf("YES\n");
                continue;
            }
            int tmpL=x,tmpR=x;
            if(x!=1 && a[Find(x-1)].flag) tmpL=a[Find(x-1)].L;
            if(x!=n && a[Find(x+1)].flag) tmpR=a[Find(x+1)].R;
            if(x!=1 && a[Find(x-1)].flag && a[Find(x-1)].ToR!=-1 && a[Find(x-1)].ToR<=tmpR)
            {
                printf("YES\n");
            }
            else if(x!=n && a[Find(x+1)].flag && a[Find(x+1)].ToL!=-1 && a[Find(x+1)].ToL>=tmpL)
            {
                printf("YES\n");
            }
            else printf("N/A\n");
        }   
        // printf("printing -- \n");
        // for(int i=1;i<=n;i++)
        // {
        //     printf("F[%d]=%d L=%d R=%d ToL=%d ToR=%d flag=%d\n",i,F[i],a[i].L,a[i].R,a[i].ToL,a[i].ToR,a[i].flag);
        // }
    }
}