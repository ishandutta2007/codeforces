#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

#define ll long long

using namespace std;

typedef struct tree * PTree;

struct tree{
    tree(int a = 0,int b = -1,int c = 0) : value(a), prior(b), num(c) { l=r=NULL; cnt=1; mx=a; };
    int value,prior,cnt,mx,num;
    PTree l,r;
};

int cnt(PTree a)
{
    return a ? a->cnt : 0;
}

void upd_cnt(PTree a)
{
    if (a) a->cnt=cnt(a->l)+1+cnt(a->r);
}

int sum(PTree a)
{
    return a ? a->mx : 0;
}

void upd_sum(PTree a)
{
    if (a) a->mx=max(sum(a->l),max(a->value,sum(a->r)));
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

vector <int> ans;

void output(PTree t)
{
    if (!t) return;
    output (t->l);
    ans.push_back(t->num);
    output (t->r);
}

void insert(PTree & t,int pos,PTree & I)
{
    PTree t1,t2;
    split(t,t1,t2,pos);
    merge(t,t1,I);
    merge(t,t,t2);
}

int findPos(PTree T,int l,int r,int val)
{
    if (l>r) return 0;
    if (l==r)
    {
        if (sum(T)>val) return l;
    }
    if (sum(T)<val) return r+1;
//  PTree t1,t2,t3;
//  split(T,t2,t3,r+1);
//  split(t2,t1,t2,l);
    int m=(l+r)/2,k;
    PTree t1,t2;
    split(T,t1,t2,m-l+1);
    if (sum(t1)<val) k=findPos(t2,m+1,r,val);
    else k=findPos(t1,l,m,val);
    merge(T,t1,t2);
    return k;
}

int Rand()
{
    return rand()*RAND_MAX+rand();
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,a,c;
    PTree T=NULL;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&c);
        PTree d=new tree(a,Rand(),i+1);
        int pos=findPos(T,0,i-1,a);
        if (pos>c) pos=c;
        insert(T,pos,d);
    }
    ans.clear();
    output(T);
    printf("%d",ans[ans.size()-1]);
    for(int i=ans.size()-2;i>=0;i--)
        printf(" %d",ans[i]);
    printf("\n");
    return 0;
}