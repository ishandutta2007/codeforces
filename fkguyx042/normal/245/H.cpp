#include<cstdio>
#include<algorithm>  
#include<cstring>  
#include<vector>
using namespace std;  
const int Mo=19930726;
const int N=100010;  
int p[N],i,j,m,n,x,px,ans[2000005],q,l,r,tree[N],C;
long long k;  
struct Node{int l,r,id;}Q[2000005];
vector<int>v[N];
char s[N], str[N];  
#define _min(x, y) ((x)<(y)?(x):(y))  
void kp()  
{  
    int i;  
    int mx = 0;  
    int id;  
    for(i=n; str[i]!=0; i++)  
        str[i] = 0; 
    for(i=1; i<n; i++)  
    {  
        if( mx > i )  
            p[i] = _min( p[2*id-i], p[id]+id-i );  
        else
            p[i] = 1;  
        for(; str[i+p[i]] == str[i-p[i]]; p[i]++)  
            ;  
        if( p[i] + i > mx )  
        {  
            mx = p[i] + i;  
            id = i;  
        }  
    }  
}  
int lowbit(int x) { return x&-x; }
void ins(int x,int y)
{
	  for (;x<=C;x+=lowbit(x)) tree[x]+=y;
}
int ask(int x)
{
      int sum=0;
	  for (;x;x-=lowbit(x)) sum+=tree[x];
	  return sum;
}
void init()  
{  
    int i;  
    str[0] = '$';  
    str[1] = '#';  
    for(i=0; i<n; i++)  
    {  
        str[i*2+2] = s[i];  
        str[i*2+3] = '#';  
    }  
    n = n*2+2;  
    s[n] = 0;  
}  
inline bool cmp(Node a,Node b) { return a.l<b.l; } 
int main()
{ scanf("%s",s);
  n=strlen(s); C=n;
  init();
  kp();
  n--;
  for (i=1;i<=n;++i) 
     for (j=1;j<=p[i];++j)
	   if ((i-j+1)%2==0)
	    v[(i-j+1)/2].push_back((i+j-1)/2),ins((i+j-1)/2,1);
  scanf("%d",&q);
  for (i=1;i<=q;++i)
  {
  	 scanf("%d%d",&Q[i].l,&Q[i].r); Q[i].id=i;
  }
  sort(Q+1,Q+q+1,cmp); int L=1;
  for (i=1;i<=q;++i)
  {
  	  while (L<Q[i].l) 
  	{
  		  for (j=0;j<(int)v[L].size();++j) ins(v[L][j],-1);
  		  L++;
  	}
  	ans[Q[i].id]=ask(Q[i].r);
  }
  for (i=1;i<=q;++i) printf("%d\n",ans[i]);
}