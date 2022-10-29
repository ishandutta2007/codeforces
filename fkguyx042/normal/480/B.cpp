#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
set<int>st;
int a[200001],i,j,m,n,p,k,l,x,y;
bool check0()
{ int i,flag=0,flag1=0;
  for (i=1;i<=n;i++) {
   if (*st.lower_bound(a[i]+x)==a[i]+x) flag=1;
   if (*st.lower_bound(a[i]+y)==a[i]+y) flag1=1;
}
   if (flag&flag1) { printf("0\n"); return true; }
   return false;
}
bool check1()
{  int i,flag=0,flag1=0;
   for (i=1;i<=n;i++)
    {
   if (*st.lower_bound(a[i]+x)==a[i]+x) flag=1;
   if (*st.lower_bound(a[i]+y)==a[i]+y) flag1=1;
   }
   for (i=1;i<=n;i++)
    {  int Flag=flag,Flag1=flag1;
       if(*st.lower_bound(a[i]+x)!=a[i]+x&&a[i]+x<=l)
       { Flag=1;   
	     if (*st.lower_bound(a[i]+y+x)==a[i]+y+x||*st.lower_bound(a[i]-y+x)==a[i]-y+x) Flag1=1;
	     if (Flag&Flag1) { printf("1\n%d\n",a[i]+x); return true; }
	   }
	   if(*st.lower_bound(a[i]-x)!=a[i]-x&&a[i]-x>0)
       { Flag=1;   
	     if (*st.lower_bound(a[i]+y-x)==a[i]+y-x||*st.lower_bound(a[i]-y-x)==a[i]-y-x) Flag1=1;
	     if (Flag&Flag1) { printf("1\n%d\n",a[i]-x); return true; } 
       }
    }
     for (i=1;i<=n;i++)
    {  int Flag=flag,Flag1=flag1;
       if(*st.lower_bound(a[i]+y)!=a[i]+y&&a[i]+y<=l)
       { Flag1=1;   
	     if (*st.lower_bound(a[i]+x+y)==a[i]+x+y||*st.lower_bound(a[i]+y-x)==a[i]+y-x) flag1=1;
	     if (Flag&Flag1) { printf("1\n%d\n",a[i]+y); return true; }
	   }
	   if(*st.lower_bound(a[i]-y)!=a[i]-y&&a[i]-y>0)
       { Flag=1;   
	     if (*st.lower_bound(a[i]-y+x)==a[i]-y+x||*st.lower_bound(a[i]-y-x)==a[i]-y-x) flag1=1;
	     if (Flag&Flag1) { printf("1\n%d\n",a[i]-y); return true; } 
       }
    }
return false;
}
int main()
{scanf("%d%d%d%d",&n,&l,&x,&y);
  for (i=1;i<=n;i++) scanf("%d",&a[i]),st.insert(a[i]);
  if (check0()) return 0;
  if (check1()) return 0;
  printf("2\n%d %d\n",x,y);
}