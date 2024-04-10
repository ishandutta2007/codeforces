#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
#define INF 9999999999999999LL

int n,m;
int d[100011];
int h[100011];

int LEAFOFFSET=1;

pair<Int,int> MAX(pair<Int,int> A,pair<Int,int> B)
{
    if (A>B)
    return A;
    else
    return B;
}

///Sum+2H

pair<Int,int> IT1[500001];

void T1()
{
    int i;
    Int sum=0;

    for (i=1;i<=n;i++)
    {
        IT1[LEAFOFFSET+i]=make_pair(2LL*h[i]+sum,i);
        sum+=(Int)d[i];
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT1[i]=MAX(IT1[2*i],IT1[2*i+1]);
    }

    return;
}

pair<Int,int> GetMax1(int ver,int L,int R,int l,int r)
{
    if (L>r || R<l)
    return make_pair(-INF,0);
    else if (L>=l && R<=r)
    {
        return IT1[ver];
    }
    else
    {
        return MAX( GetMax1(2*ver,L,(L+R)/2,l,r) , GetMax1(2*ver+1,(L+R)/2+1,R,l,r) );
    }
}

///Sum+2H

pair<Int,int> IT2[500001];

void T2()
{
    int i;
    Int sum=0;

    for (i=1;i<=n;i++)
    {
        IT2[LEAFOFFSET+i]=make_pair(2LL*h[i]-sum,i);
        sum+=(Int)d[i];
    }

    for (i=LEAFOFFSET+n+1;i<=2*LEAFOFFSET+1;i++)
    {
        IT2[i]=make_pair(-INF,i);
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT2[i]=MAX(IT2[2*i],IT2[2*i+1]);
    }

    return;
}

pair<Int,int> GetMax2(int ver,int L,int R,int l,int r)
{
    if (L>r || R<l)
    return make_pair(-INF,0);
    else if (L>=l && R<=r)
    {
        return IT2[ver];
    }
    else
    {
        return MAX( GetMax2(2*ver,L,(L+R)/2,l,r) , GetMax2(2*ver+1,(L+R)/2+1,R,l,r) );
    }
}

///RSum+2H

pair<Int,int> IT3[500001];

void T3()
{
    int i;
    Int sum=0;

    for (i=n;i>=1;i--)
    {
        IT3[LEAFOFFSET+i]=make_pair(2LL*h[i]+sum,i);
        sum+=(Int)d[i-1];
    }

    for (i=LEAFOFFSET;i>=1;i--)
    {
        IT3[i]=MAX(IT3[2*i],IT3[2*i+1]);
    }

    return;
}

pair<Int,int> GetMax3(int ver,int L,int R,int l,int r)
{
    if (L>r || R<l)
    return make_pair(-INF,0);
    else if (L>=l && R<=r)
    {
        return IT3[ver];
    }
    else
    {
        return MAX( GetMax3(2*ver,L,(L+R)/2,l,r) , GetMax3(2*ver+1,(L+R)/2+1,R,l,r) );
    }
}

///

pair<Int,int> Q(int l,int r,int q)
{
    if (q==1)
    return GetMax1(1,1,LEAFOFFSET+1,l,r);
    if (q==2)
    return GetMax2(1,1,LEAFOFFSET+1,l,r);
    if (q==3)
    return GetMax3(1,1,LEAFOFFSET+1,l,r);
}

void BuildTrees()
{
    while(LEAFOFFSET<n)
    LEAFOFFSET*=2;
    LEAFOFFSET--;

    T1();
    T2();
    T3();

    return;
}

Int GetLinearAns(int L,int R)
{
    pair<Int,int> V1,V2;
    pair<Int,int> V3,V4;
    Int ans;

    V1=Q(L,R,1);
    V2=Q(L,R,2);

    //cout<<V1.second<<" and "<<V2.second<<endl;

    if (V1.second==V2.second) ///special case
    {
        if (V2.second==L)
        {
            V1=Q(V1.second+1,R,1);

            return V1.first+V2.first;
        }

        if (V1.second==R)
        {
            V2=Q(L,V2.second-1,2);

            return V1.first+V2.first;
        }

        V3=Q(L,V1.second-1,2);
        V4=Q(V1.second+1,R,1);

        ans=V3.first+V1.first;

        if (V2.first+V4.first>ans)
        ans=V2.first+V4.first;

        return ans;
    }
    else
    {
        return V1.first+V2.first;
    }
}

int main()
{
    int i;
    int L,R;
    Int ans;
    Int ans2;
    Int v1,v2;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
    }

    for (i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }

    BuildTrees();

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&L,&R);

        if (L>R)
        {
            ans=GetLinearAns(R+1,L-1);

            printf("%lld\n",ans);
        }
        else
        {
            ans=-INF;

            if (L>2)
            {
                ans=GetLinearAns(1,L-1);
                //cout<<"here and "<<ans<<endl;
            }

            if (R<n-1)
            {
                ans2=GetLinearAns(R+1,n);
                if (ans2>ans)
                ans=ans2;
            }

            if (L>1 || R<n)
            {
                v1=Q(1,L-1,1).first;
                v2=Q(R+1,n,3).first;

                //cout<<"here only and "<<v1<<"+"<<v2<<endl;

                if (v1+v2+d[n]>ans)
                ans=v1+v2+d[n];
            }

            printf("%lld\n",ans);

            //while(1);
        }
    }

    return 0;
}
/**
5 3
2 2 2 2 2
3 5 2 1 4
1 3
2 2
4 5
**/