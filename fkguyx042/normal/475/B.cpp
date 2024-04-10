#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{int num;int before;}s[100001];
node s1[100001];
int index1[100001],index11[100001];
int i,j,m,n,p,k,k1,kk=0;
bool vis[100001];
int numk[100001];
int ssc[100001];
char c[1001],c1[1001];
int id(int x,int y)
{return (x-1)*m+y;}
void add(int p1,int p2)
 { s[++k].num=p2; 
 s[k].before=index1[p1]; 
 index1[p1]=k;}
void add1(int p1,int p2)
  { s1[++k1].num=p2;
   s1[k1].before=index11[p1]; 
   index11[p1]=k1;}
void dfs(int num)
 { int i;
    vis[num]=true;
   for (i=index1[num];i;i=s[i].before)
      if (!vis[s[i].num]) dfs(s[i].num);
   ssc[++p]=num;
}
void ndfs(int num)
  { int i;
     numk[num]=kk;
      vis[num]=true;
       for (i=index11[num];i;i=s1[i].before)
         if (!vis[s1[i].num]) ndfs(s1[i].num);
} 
void doit()
 {  int i,j,k;
    memset(vis,false,sizeof(vis));
     for (i=1;i<=n;i++)
       if (!vis[i]) dfs(i);
         memset(vis,false,sizeof(vis));
     for (i=n;i>=1;i--)
       if (!vis[ssc[i]])
          { kk++;
            ndfs(ssc[i]);
            }
}
int main()
 {
 scanf("%d%d",&n,&m);
  scanf("%s",&c);
  scanf("%s",&c1);
  for (i=1;i<=n;i++) 
  {    for (j=1;j<m;j++) 
          if (c[i-1]=='<') add(id(i,j+1),id(i,j)),add1(id(i,j),id(i,j+1));
          else  add1(id(i,j+1),id(i,j)),add(id(i,j),id(i,j+1));
  }
  for (j=1;j<=m;j++)
  {  for (i=1;i<n;i++)
     if (c1[j-1]=='^') add(id(i+1,j),id(i,j)),add1(id(i,j),id(i+1,j));
     else add1(id(i+1,j),id(i,j)),add(id(i,j),id(i+1,j));
}
 n=n*m;
doit();
  if (kk>1) printf("NO\n"); else printf("YES\n");
return 0;
}