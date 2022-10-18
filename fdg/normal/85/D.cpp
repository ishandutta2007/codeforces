#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <stack>

#define ll long long

using namespace std;

typedef struct tree * PTree;

struct tree{
    tree(int a = 0,int b = -1) : value(a), prior(b) { l=r=NULL; cnt=1; sum=a; };
    int value,prior,cnt;
    ll sum;
    PTree l,r;
};

int Rand()
{
    return rand()*RAND_MAX+rand();
}

int cnt(PTree a)
{
    return a ? a->cnt : 0;
}

void upd_cnt(PTree a)
{
    if (a) a->cnt=cnt(a->l)+1+cnt(a->r);
}

ll sum(PTree a)
{
    return a ? a->sum : 0;
}

void upd_sum(PTree a)
{
    if (a) a->sum=sum(a->l)+a->value+sum(a->r);
}

void merge(PTree & t,PTree l,PTree r)
{
    if (!l||!r)
        t=l ? l : r;
    else
        if (l->prior>r->prior) merge(l->r,l->r,r),t=l;
        else merge(r->l,l,r->l),t=r;
    upd_cnt(t);
    upd_sum(t);
}

void split(PTree t,PTree & l,PTree & r,int key,int add = 0)
{
    if (!t)
    {
        l=r=NULL;
        return;
    }
    int cur_key=cnt(t->l)+add;
    if (cur_key>=key)
        split(t->l,l,t->l,key,add),r=t;
    else
        split(t->r,t->r,r,key,add+1+cnt(t->l)),l=t;
    upd_cnt(t);
    upd_sum(t);
}

PTree tr[5]={0};

int findPos(PTree a,int val)
{
    if (!a) return 0;
    if (a->value>val) return findPos(a->l,val);
    if (a->value==val) return cnt(a->l);
    return cnt(a->l)+1+findPos(a->r,val);
}

bool was(PTree a,int val)
{
    if (!a) return false;
    if (a->value>val) return was(a->l,val);
    if (a->value==val) return true;
    return was(a->r,val);

}

void add(int val)
{
    PTree tmp[5]={0};
    for(int i=0;i<5;i++)
    {
        int pos=findPos(tr[i],val);
        split(tr[i],tr[i],tmp[i],pos);
    }
    int kol=0;
    for(int i=0;i<5;i++)
        kol+=cnt(tr[i]);
    merge(tr[(kol+1)%5],tr[(kol+1)%5],new tree(val,Rand()));
    for(int i=0;i<5;i++)
        merge(tr[i],tr[i],tmp[(i+4)%5]);
}

void del(int val)
{
    PTree tmp[5]={0},test=NULL;
    for(int i=0;i<5;i++)
    {
        int pos=findPos(tr[i],val);
        bool w=was(tr[i],val);
        if (!w)
        {
            split(tr[i],tr[i],tmp[i],pos);
        }
        else
        {
            split(tr[i],tr[i],tmp[i],pos+1);
            split(tr[i],tr[i],test,pos);
        }
    }
    for(int i=0;i<5;i++)
        merge(tr[i],tr[i],tmp[(i+1)%5]);
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,val;
    scanf("%d\n",&n);
    char str[10]={0};
    for(int t=0;t<n;t++)
    {
        scanf("%s",str);
        if (str[0]=='a')
        {
            scanf("%d\n",&val);
            add(val);
            continue;
        }
        if (str[0]=='d')
        {
            scanf("%d\n",&val);
            del(val);
            continue;
        }
        scanf("\n");
        printf("%I64d\n",sum(tr[3]));
    }
    return 0;
}