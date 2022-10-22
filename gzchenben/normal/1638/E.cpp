#include<cstdio>
#include<set>
using namespace std;
int n,q;
long long Tag[1000005];
 
class BIT
{
    public:
 
    long long data[1000005];
    int lowbit(int x)
    {
        return x&(-x);
    }
    void Add(int pos,long long val)
    {
        while(pos<=n)
        {
            data[pos]+=val;
            pos+=lowbit(pos);
        }
    }
    void modify(int L,int R,long long val)
    {
        Add(L,val);
        Add(R+1,-val);
    }
    long long query(int pos)
    {
        long long res=0;
        while(pos)
        {
            res+=data[pos];
            pos-=lowbit(pos);
        }
        return res;
    }
}T;
 
struct Node
{
    int L,R,col;
};
bool operator <(Node x,Node y)
{
    if(x.L==y.L) return x.R<y.R;
    return x.L<y.L;
}
set<Node> st;
 
void Modify(int L,int R,int col)
{
    auto It=--st.upper_bound((Node){L+1,0,0});
    while(It!=st.end() && It->L<=R)
    {
        // printf("-- It = %d %d %d\n",It->L,It->R,It->col);
        if(It->R < L) 
        {
            It++;
            continue;
        }
        auto tmpIt=It;
        tmpIt++;
        if(It->L < L)
        {
            // printf("added %d %d %d\n",It->L,L-1,It->col);
            st.insert((Node){It->L,L-1,It->col});
            // printf("printing----------------");
            // for(auto &p : st)
            // {
            //     printf("%d %d %d\n",p.L,p.R,p.col);
            // }
        }
        if(It->R > R)
        {
            st.insert((Node){R+1,It->R,It->col});
        }
        T.modify(max(It->L,L),min(It->R,R),Tag[It->col]-Tag[col]);
        // printf("modify %d %d %d\n",max(It->L,L),min(It->R,R),Tag[It->col]-Tag[col]);
        st.erase(It);
        It=tmpIt;
    }
    st.insert((Node){L,R,col});
    // for(auto &p : st)
    // {
    //     printf("%d %d %d\n",p.L,p.R,p.col);
    // }
}
 
long long Query(int pos)
{
    auto It=--st.upper_bound((Node){pos+1,0,0});
    // printf("%d %d %d\n",It->L,It->R,It->col);
    if(It->R < pos) return T.query(pos);
    return Tag[It->col]+T.query(pos);
}
 
char tmp[20];
int main()
{
    scanf("%d%d",&n,&q);
    st.insert((Node){0,0,0});
    st.insert((Node){n+1,n+1,0});
    st.insert((Node){1,n,1});
    for(int i=1;i<=q;i++)
    {
        scanf("%s",tmp);
        if(tmp[0]=='C')
        {
            int L,R,C;
            scanf("%d%d%d",&L,&R,&C);
            Modify(L,R,C);
        }
        if(tmp[0]=='A')
        {
            int C;
            long long X;
            scanf("%d%lld",&C,&X);
            Tag[C]+=X;
        }
        if(tmp[0]=='Q')
        {
            int pos;
            scanf("%d",&pos);
            printf("%lld\n",Query(pos));
        }
    }
}