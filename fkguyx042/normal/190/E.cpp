#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#include<map>
#include<vector>

#define N 1000007
#define Mo 2333333
using namespace std;
int i,j,m,n,p,k,Q[N],x,y,ans,lastr,size[N];
set<int>st;
vector<int>v[N];
vector<pair<int,int> >vx[Mo];
void hash(int x,int y)
{
	  if (x>y) swap(x,y);
	  int seed=(1ll*N*x%Mo+y)%Mo;
	  vx[seed].push_back(make_pair(x,y));
}
int get(int x,int y)
{
	  if (x>y) swap(x,y); pair<int,int> c=make_pair(x,y);
	  int seed=(1ll*N*x%Mo+y)%Mo,i;
	  for (i=0;i<(int)vx[seed].size();++i)
	    if (vx[seed][i]==c) return 1;
	    return 0;
}
char nc(){static char buf[100000],*p1=buf+100000,*pend=buf+100000;if (p1==pend) p1=buf,pend=buf+fread(buf,1,100000,stdin);return *p1++;}
void read(int &x){char ch=nc();x=0;for (;ch<'0'||ch>'9';ch=nc());for (;ch>='0'&&ch<='9';ch=nc()) x=x*10+ch-'0';}
int main()
{
	 read(n); read(m);
	 for (;m--;)
	 {
	 	 read(x); read(y);
	 	  hash(x,y);
	 }
	 set<int>::iterator it;
	 for (i=1;i<=n;++i) st.insert(i);
	 for (;n;)
	 {
	 	 Q[Q[0]=1]=*st.begin();
	 	 st.erase(st.begin());
	 	 int l;
	 	 for (l=1;l<=Q[0];++l)
	 	 {
	 	 	int p=Q[l]; lastr=Q[0];
			   for (it=st.begin();it!=st.end();++it)
			     if (!get(p,*it)) Q[++Q[0]]=*it;
			for (i=lastr+1;i<=Q[0];++i)
				  st.erase(Q[i]);
		}
		++ans;
		size[ans]=Q[0];
		for (i=1;i<=Q[0];++i) v[ans].push_back(Q[i]);
		n-=Q[0];
	 }
	 printf("%d\n",ans);
	 for (i=1;i<=ans;++i)
	 {
	 	  printf("%d",size[i]);
	 	  for (j=0;j<size[i];++j) printf(" %d",v[i][j]);
	 	  puts("");
	 }
}