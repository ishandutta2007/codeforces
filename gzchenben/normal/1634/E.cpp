#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;
struct Node1
{
    int pos,ID,val;
};
bool operator <(Node1 x,Node1 y)
{
    if(x.val==y.val) return x.pos<y.pos;
    return x.val<y.val;
}
vector<Node1> BigSet;

struct Node2
{
    int ID,val,match;
};
bool operator <(Node2 x,Node2 y)
{
    if(x.val!=y.val) return x.val<y.val;
    return x.ID < y.ID;
}
set<Node2> st[100005];

int m;
set<pair<int,int> > Ori[100005];//pair<val,ID>
vector<int> Ans[100005];
map<int,int> mp1;
bool flag=true;

int main()
{
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        mp1.clear();
        Ans[i].resize(x+1);
        for(int j=1;j<=x;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(mp1[tmp])
            {
                int From=mp1[tmp];
                Ori[i].erase(make_pair(tmp,From));
                Ans[i][From]=1;
                Ans[i][j]=2;
                mp1[tmp]=0;
            }
            else
            {
                Ori[i].insert(make_pair(tmp,j));
                mp1[tmp]=j;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(auto &p : Ori[i])
        {
            BigSet.push_back((Node1){i,p.second,p.first});
        }
    }
    sort(BigSet.begin(),BigSet.end());
    for(int i=0;i<BigSet.size();i+=2)
    {
        auto p1=BigSet[i];
        auto p2=BigSet[i+1];
        if(p1.val!=p2.val)
        {
            flag=false;
            break;
        }
//        printf("pairing(<%d,%d,%d>,<%d,%d,%d>)\n",p1.ID,p1.pos,p1.val,p2.ID,p2.pos,p2.val);
        st[p1.pos].insert((Node2){p1.ID,p1.val,p2.pos});
        st[p2.pos].insert((Node2){p2.ID,p2.val,p1.pos});
    }
    if(!flag)
    {
        printf("NO\n");
        return 0;
    }
    int Unempty=1;
    while(st[Unempty].empty() && Unempty<=m) Unempty++;
    while(Unempty!=m+1)
    {
        int NowPos=Unempty;
        do
        {
            auto tmp=*st[NowPos].begin();
            Ans[NowPos][tmp.ID]=1;
            st[NowPos].erase(tmp);
            auto tmp2=*st[tmp.match].upper_bound((Node2){0,tmp.val,0});
            Ans[tmp.match][tmp2.ID]=2;
            st[tmp.match].erase(tmp2);
            NowPos=tmp.match;
//            printf("deleting (<%d,%d,%d>,<%d,%d,%d>)\n",tmp.ID,tmp.val,tmp.match,tmp2.ID,tmp2.val,tmp2.match);
        }while(st[NowPos].size()%2==1);
        while(st[Unempty].empty() && Unempty<=m) Unempty++;
    }
    printf("YES\n");
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<Ans[i].size();j++)
        {
            if(Ans[i][j]==1) printf("L");
            if(Ans[i][j]==2) printf("R");
        }
        printf("\n");
    }
}
/*
*/