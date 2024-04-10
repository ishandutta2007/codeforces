#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair

#define N 400005
#define M 200005
#define seed 23333
#define Mo 998244353

using namespace std;
int i,j,m,n,p,k,ans,a[N],b[N],c[N],P[N],A[N],B[N],C[N],id[N];
set<pair<int,int> >st;
multiset<int>Ans;
inline bool cmp(int a,int b) { return A[a]>A[b]; }
void ins(pair<int,int> now)
{
	  set<pair<int,int> >::iterator i,j,k; k=st.upper_bound(now); if (k->se>=now.se) return;
	  i=st.insert(now).fi; j=i; --j; Ans.erase(Ans.lower_bound(j->fi+k->se)),Ans.insert(i->fi+k->se);
	  while (j->se<i->se) k=j--,Ans.erase(Ans.lower_bound(j->fi+k->se)),st.erase(k);
	  Ans.insert(j->fi+i->se);
}	  
int main()
{
	  scanf("%d",&n);
	  for (i=1;i<=n;++i) scanf("%d",&a[i]),P[++P[0]]=a[i];
	  for (i=1;i<=n;++i) scanf("%d",&b[i]),P[++P[0]]=b[i];
	  for (i=1;i<=n;++i) scanf("%d",&c[i]),P[++P[0]]=c[i];
	  sort(P+1,P+P[0]+1);
	  P[0]=unique(P+1,P+P[0]+1)-(P+1);
	  for (i=1;i<=n;++i) a[i]=lower_bound(P+1,P+P[0]+1,a[i])-P;
	  for (i=1;i<=n;++i) b[i]=lower_bound(P+1,P+P[0]+1,b[i])-P;
	  for (i=1;i<=n;++i) c[i]=lower_bound(P+1,P+P[0]+1,c[i])-P;
	  for (i=1;i<=P[0];++i) id[i]=i,A[i]=B[i]=C[i]=5*n;
	  for (i=1;i<=n;++i) if (A[a[i]]>n) A[a[i]]=i;
	  for (i=1;i<=n;++i) if (B[b[i]]>n) B[b[i]]=i;
	  for (i=1;i<=n;++i) if (C[c[i]]>n) C[c[i]]=i;
	  st.insert(mk(0,6*n)); st.insert(mk(6*n,0));
	  id[P[0]+1]=P[0]+1; sort(id+1,id+P[0]+1,cmp); Ans.insert(0);
	  ans=A[id[1]];
	  for (i=1;i<=P[0];++i)
	  {
	  	  ins(mk(B[id[i]],C[id[i]]));
	  	  ans=min(ans,A[id[i+1]]+*Ans.begin());
      }
      printf("%d\n",ans);
}