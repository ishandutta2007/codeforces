#include <iostream>
#include <stdio.h>
using namespace std;

struct Node
{
    int s1=0,s2=0;
    int sum=0;
};

Node Mem[35000111];
int MSL=0;

int allocMem()
{
    MSL++;
    return MSL;
}

struct Tree
{
    int root;

    void Init()
    {
        root=allocMem();
        return;
    }

    void upd(int ver,int L,int R,int ind,int val)
    {
        if (L==R)
        {
            Mem[ver].sum+=val;
            return;
        }

        int mid=(L+R)/2;

        if (ind<=mid)
        {
            if (Mem[ver].s1==0)
                Mem[ver].s1=allocMem();

            upd(Mem[ver].s1,L,mid,ind,val);
        }
        else
        {
            if (Mem[ver].s2==0)
                Mem[ver].s2=allocMem();

            upd(Mem[ver].s2,mid+1,R,ind,val);
        }

        Mem[ver].sum=Mem[ Mem[ver].s1 ].sum+Mem[ Mem[ver].s2 ].sum;

        return;
    }

    void Update(int ind,int val)
    {
        upd(root,1,(1<<30),ind,val);
    }

    int qr(int ver,int L,int R,int bt,int num)
    {
        if (L==R)
            return L;

        int mid=(L+R)/2;

        if (Mem[ Mem[ver].s1 ].sum==0)
            return qr(Mem[ver].s2,mid+1,R,bt-1,num);

        if (Mem[ Mem[ver].s2 ].sum==0)
            return qr(Mem[ver].s1,L,mid,bt-1,num);

        if ( (num&(1<<bt))==0 )
            return qr(Mem[ver].s1,L,mid,bt-1,num);
        else
            return qr(Mem[ver].s2,mid+1,R,bt-1,num);
    }

    int Query(int num)
    {
        return qr(root,1,(1<<30),29,num);
    }
};

int A[300111];
int P[300111];
int n;

Tree T;

int main()
{
    int i;
    int v;

    T.Init();

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&A[i]);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&P[i]);

        T.Update(P[i]+1,1);
    }

    for (i=1;i<=n;i++)
    {
        v=T.Query(A[i])-1;

        printf("%d",(v^A[i]));

        T.Update(v+1,-1);

        if (i!=n)
            printf(" ");
    }

    return 0;
}