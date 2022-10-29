#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int i,j,m,n,p,k,l,r,x[100005],ans[100005],tot;
struct Node{int l,r,id,type;}Q[400005];
inline void ins(int l,int r,int type,int id)
{
        ++tot;
        Q[tot].l=l; Q[tot].r=r; Q[tot].type=type; Q[tot].id=id;
}
inline bool cmp(Node x,Node y)
{
        if (x.l!=y.l) return x.l<y.l;
        return x.type<y.type;
}
set<pair<int,int> >st;
pair<int,int>z;
int main()
{
     scanf("%d",&n);
     for (i=1;i<=n;++i) scanf("%d%d",&l,&r),ins(l,r,1,i);
     scanf("%d",&m);
     for (i=1;i<=m;++i) scanf("%d%d%d",&l,&r,&x[i]),ins(l,r,0,i);
     sort(Q+1,Q+tot+1,cmp);
     set<pair<int,int> >::iterator it;
     for (i=1;i<=tot;++i)
      if (!Q[i].type) st.insert(make_pair(Q[i].r,Q[i].id));
       else 
       {
              it=st.lower_bound(make_pair(Q[i].r,0));
              if (it==st.end()) { printf("NO\n"); return 0; }
              z=*it;
              int Type=z.second;
              ans[Q[i].id]=Type;
              x[Type]--;
              if (!x[Type]) st.erase(it);
       }
      printf("YES\n");
      for (i=1;i<=n;++i) printf("%d ",ans[i]);
}