#include<cstdio>
#include<algorithm>
#include<cstring>
#define mid ((l+r)>>1)
#define ls (t<<1)
#define rs ((t<<1)+1)
using namespace std;
const int INF=(int)1e9;
int i,j,m,n,p,k,x,y,A,B;
char c[3][200001];
struct Node{int ls_rs,ld_rs,ls_rd,ld_rd;}Tree[1000001];
Node Ans;
void up(Node &a,Node b,Node c)
{  a.ls_rs=a.ls_rd=a.ld_rs=a.ld_rd=INF;
   if (b.ls_rs!=-1&&c.ls_rs!=-1) a.ls_rs=min(a.ls_rs,b.ls_rs+c.ls_rs);
   if (b.ls_rs!=-1&&c.ls_rd!=-1) a.ls_rd=min(a.ls_rd,b.ls_rs+c.ls_rd);
   if (b.ls_rd!=-1&&c.ld_rs!=-1) a.ls_rs=min(a.ls_rs,b.ls_rd+c.ld_rs);
   if (b.ls_rd!=-1&&c.ld_rd!=-1) a.ls_rd=min(a.ls_rd,b.ls_rd+c.ld_rd);
   if (b.ld_rs!=-1&&c.ls_rs!=-1) a.ld_rs=min(a.ld_rs,b.ld_rs+c.ls_rs);
   if (b.ld_rs!=-1&&c.ls_rd!=-1) a.ld_rd=min(a.ld_rd,b.ld_rs+c.ls_rd);
   if (b.ld_rd!=-1&&c.ld_rs!=-1) a.ld_rs=min(a.ld_rs,b.ld_rd+c.ld_rs);
   if (b.ld_rd!=-1&&c.ld_rd!=-1) a.ld_rd=min(a.ld_rd,b.ld_rd+c.ld_rd);
   if (a.ls_rs==INF) a.ls_rs=-1;
   if (a.ls_rd==INF) a.ls_rd=-1;
   if (a.ld_rs==INF) a.ld_rs=-1;
   if (a.ld_rd==INF) a.ld_rd=-1;
}
void build_tree(int l,int r,int t)
{  if (l==r) {
	   if (c[1][l-1]=='.'&&c[2][l-1]=='.') 
	    {  Tree[t].ls_rs=Tree[t].ld_rd=1;
	       Tree[t].ls_rd=Tree[t].ld_rs=2;
	    }
	   if (c[1][l-1]=='.'&&c[2][l-1]=='X')
	    { Tree[t].ls_rd=Tree[t].ld_rs=Tree[t].ld_rd=-1;
	      Tree[t].ls_rs=1;
	    }
		if (c[1][l-1]=='X'&&c[2][l-1]=='.')
	    { Tree[t].ls_rd=Tree[t].ld_rs=Tree[t].ls_rs=-1;
	      Tree[t].ld_rd=1;
	    } 
	    if (c[1][l-1]=='X'&&c[2][l-1]=='X') Tree[t].ls_rs=Tree[t].ls_rd=Tree[t].ld_rs=Tree[t].ld_rd=-1;
} else build_tree(l,mid,ls),build_tree(mid+1,r,rs),up(Tree[t],Tree[ls],Tree[rs]);
}
void ask(int ll,int rr,int l,int r,int t)
{  if (ll<=l&&r<=rr){ if (ll==l) Ans=Tree[t]; else up(Ans,Ans,Tree[t]); }
   else { if (ll<=mid) ask(ll,rr,l,mid,ls);
          if (rr>mid) ask(ll,rr,mid+1,r,rs);
      }
}
int main()
{ scanf("%d%d",&n,&m);
   scanf("%s",&c[1]);
   scanf("%s",&c[2]);
   build_tree(1,n,1);
   for (;m--;)
{ scanf("%d%d",&x,&y);
  if (x>n) A=x-n; else A=x;
  if (y>n) B=y-n; else B=y;
  Ans.ls_rs=Ans.ld_rd=Ans.ld_rs=Ans.ls_rd=0;
  ask(min(A,B),max(A,B),1,n,1);
  if (A>B) { A=y>n?1:0; B=x>n?1:0;}
  else { A=x>n?1:0; B=y>n?1:0; }
  if (!A&&!B)
   printf("%d\n",Ans.ls_rs==-1?-1:Ans.ls_rs-1);
  if (A&&!B) printf("%d\n",Ans.ld_rs==-1?-1:Ans.ld_rs-1);
  if (!A&&B) printf("%d\n",Ans.ls_rd==-1?-1:Ans.ls_rd-1);
  if (A&&B)  printf("%d\n",Ans.ld_rd==-1?-1:Ans.ld_rd-1);
}
}