#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<set>

#define mk make_pair
#define fi first
#define se second

#define N 300005
 
using namespace std;
int i,j,m,n,p,k,id[N],a[N],b[N],pd,sum[N];
long long Ans,ans;
set<pair<int,int> >st,st1;
inline bool cmp(int A,int B) { return b[A]<b[B]; }
void change(int x)
{
	if (st.find(mk(a[x],x))!=st.end()) st.erase(mk(a[x],x)),ans-=a[x];
	else st1.erase(mk(a[x],x));
	st1.insert(mk(b[x]-a[x],x));
}
void get(int x)
{
     while ((int)st.size()>x)
     {
     	   set<pair<int,int> >::iterator it=--st.end();
     	   ans-=(*it).fi;
     	   st.erase(it);
     }
     while (st1.size()&&(int)st.size()<x)
     {
     	    set<pair<int,int> >::iterator it=st1.begin();
     	    ans+=(*it).fi;
     	    pair<int,int> z=*it;
     	    st1.erase(z);
     	    st.insert(z);
     }
     for (;st.size()&&st1.size();)
     {
     	    set<pair<int,int> >::iterator it=--st.end(),it1=st1.begin();
     	    pair<int,int> A=*it,B=*it1;
			 if (A.fi>B.fi)
			 {
			 	 ans-=A.fi; ans+=B.fi; 
			    st.erase(it); st1.erase(it1);
				st.insert(B); st1.insert(A);
			 }
			 else break;
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for (i=1;i<=n;++i) scanf("%d%d",&a[i],&b[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (i=1;i<=n;++i) st1.insert(mk(a[i],i));
	Ans=(long long)1e18;
	for (i=0;i<=min(n,k);++i)
 {
 	  if (i>0)
 	  {
 	  ans+=a[id[i]];
 	  change(id[i]);
      }
 	  get(k-i);
 	  if (i+n>=k&&Ans>ans)
	   { 
	       Ans=min(Ans,ans);
	       pd=i;
	   }
 }
 cout<<Ans<<endl;
     st.clear(); st1.clear(); ans=0;
     for (i=1;i<=n;++i) st1.insert(mk(a[i],i));
       for (i=0;i<=pd;++i) 
       {
       	    if (i>0)
 	        {
 	           ans+=a[id[i]];
 	           change(id[i]);
            }
 	        get(k-i);
       }
       for (i=1;i<=pd;++i) sum[id[i]]=1;
       set<pair<int,int> >::iterator it;
       for (it=st.begin();it!=st.end();++it)
          sum[(*it).se]++;
       for (i=1;i<=n;++i) printf("%d",sum[i]);
}