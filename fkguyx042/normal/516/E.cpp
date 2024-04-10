#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<map>
using namespace std;
const long long INF=(long long)1e18;
struct Bian{int ed,before;
}s[200005];
map<int,long long>mp;
int i,j,m,n,p,k,ni,mi,g,size[2],inv[2],K,x,k1,A[3],C[300005];
int Size[200005][2],fox[200005][2];
struct Node {int x,y,z;}G;
long long ans;
Node gcd(int x,int y)
{ 
  if (!y) return (Node){1,0,x};
  else
  {
  	 Node t=gcd(y,x%y);
  	 return (Node){t.y,t.x-t.y*(x/y),t.z};
  }
}
void ins(int x,long long y)
{ 
   if (mp.count(x)) 
	{ 
	if (y==INF) return;
	long long &z=mp[x];
    z=(z>y)?y:z;
    }
	else mp[x]=y;
}
void Min(long long &x,long long y){ x=min(x,y); }
void Do(long long &x,int Round)
{
	  map<int,long long>::iterator it;
	  for (it=mp.begin();it!=mp.end();)
	  {
	  	   Min(it->second,x);
	  	   Min(x,it->second);
	  	   int N=it->first;
	  	   ++it;  int af;
	       if (it!=mp.end()) af=it->first;
		   else af=mp.begin()->first+size[Round];
		   x+=1ll*(af-N)*size[Round^1]*g;
	 }
}
long long get(int x)
{
	int i,j,p,k; long long sum=-1;
	for (i=0;i<2;++i)
	{
		mp.clear(); C[0]=0;
		for (j=0;j<2;++j)
		  for (k=fox[x][j];k;k=s[k].before)
		  {
		  	  int R=s[k].ed;
			  int Now=1ll*R*inv[i]%size[i];
		  	  ins(Now,1ll*R*g); 
		  	  if (i==j) C[++C[0]]=Now;
		  	  ins((Now+size[i]-1)%size[i],INF);
	      }
	      sort(C+1,C+C[0]+1);
	    long long Now=INF,R=1;
	    for (j=0;j<2;++j) Do(Now,i);
	 map<int,long long>::iterator it;
	 for (it=mp.begin();it!=mp.end();++it) 
	 {
	 	 while (R<=C[0]&&C[R]<it->first) ++R;
		if (R>C[0]||C[R]>it->first)
	    sum=max(sum,it->second);
     }
    }
    if (sum==-1) return -INF;
   return sum;
}
inline int read()
{
	 int x=0; char c;
	 while (c=getchar(),c<'0'||c>'9');
	 x=c-'0';
	 while (c=getchar(),c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0';
	 return x;
}
void add(int x,int y,int z)
{
	 s[++k1].ed=z; s[k1].before=fox[x][y]; fox[x][y]=k1;
}
int main()
{
	scanf("%d%d",&n,&m);
	G=gcd(n,m);  g=G.z; 
	size[0]=n/g; size[1]=m/g; 
    inv[0]=(G.y%size[0]+size[0])%size[0];
    inv[1]=(G.x%size[1]+size[1])%size[1];
	if (g>200000) { printf("-1\n"); return 0;}
	for (i=0;i<2;++i)
	{
		K=read();  A[i]=K;
		 for (;K--;) x=read(),k=x%g,add(k,i,x/g),Size[k][i]++;
	}
	for (i=0;i<g;++i) if (Size[i][0]+Size[i][1]==0) { printf("-1\n"); return 0; }
	for (i=0;i<g;++i) ans=max(ans,get(i)+i);
	cout<<ans<<endl;
}