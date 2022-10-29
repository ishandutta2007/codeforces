#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
using namespace std;
const int Mo=(int)1e9+9;
int  i,j,m,n,p,k,sum,Size[100001],vis[100001],flag[100001],xc,x;
map<pair<int,int>,int>mp;
set<int>st;
int a[100001],b[100001],size[100001],fox[100001],k1,Fox[100001];
struct Node{int ed,before;}s[1000001],S[1000001];
void add(int x,int y)
{ s[++k1].ed=y; s[k1].before=fox[x]; fox[x]=k1;
  S[k1].ed=x;  S[k1].before=Fox[y]; Fox[y]=k1;  }
int main()
{  scanf("%d",&n);  
  for (i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]),mp[make_pair(a[i],b[i])]=i;
  for (i=1;i<=n;i++)
 {   xc=mp[make_pair(a[i]-1,b[i]-1)];
     if (xc) add(i,xc),size[xc]++,Size[i]++;
     xc=mp[make_pair(a[i],b[i]-1)];
     if (xc) add(i,xc),size[xc]++,Size[i]++;
      xc=mp[make_pair(a[i]+1,b[i]-1)];
     if (xc)  add(i,xc),size[xc]++,Size[i]++;
 }
 set<int>::iterator it;
  for (i=1;i<=n;i++) if (Size[i]==1) 
  for (j=fox[i];j;j=s[j].before) 
   vis[s[j].ed]=1; 
  for (i=1;i<=n;i++) if (!vis[i]) st.insert(i),flag[i]=1;   
  for (i=1;i<=n;i++)
  {    if (i%2==1)
      {  it=st.end();
         --it;
        sum=((1ll*sum*n%Mo+*it)-1)%Mo;
         x=*it;
         if (x==7)
           x=7;
        flag[x]=2;
        st.erase(it);
         for (j=fox[x];j;j=s[j].before)
           { size[s[j].ed]--;
             if (size[s[j].ed]==0&&!flag[s[j].ed]) st.insert(s[j].ed),flag[s[j].ed]=1;
              else if (!flag[s[j].ed])
             {  for (k=Fox[s[j].ed];k;k=S[k].before)
                   if (Size[S[k].ed]==1&&flag[S[k].ed]!=2) break;
                   if (!k) st.insert(s[j].ed),flag[s[j].ed]=1;
           }
           }
         for (j=Fox[x];j;j=S[j].before)
           {    Size[S[j].ed]--;
                 if (Size[S[j].ed]==1&&flag[S[j].ed]!=2) 
                 for (k=fox[S[j].ed];k;k=s[k].before)
                   if (flag[s[k].ed]==1) {  flag[s[k].ed]=0; st.erase(s[k].ed); }
           }  
      }
      else {  it=st.begin();
         sum=((1ll*sum*n%Mo+*it)-1)%Mo;
         x=*it;
           flag[x]=2;
           st.erase(it);
         for (j=fox[x];j;j=s[j].before)
           { size[s[j].ed]--;
             if (size[s[j].ed]==0&&!flag[s[j].ed]) st.insert(s[j].ed),flag[s[j].ed]=1;
             else if (!flag[s[j].ed])
             {  for (k=Fox[s[j].ed];k;k=S[k].before)
                   if (Size[S[k].ed]==1&&flag[S[k].ed]!=2) break;
                   if (!k) st.insert(s[j].ed),flag[s[j].ed]=1;
           }
           }
         for (j=Fox[x];j;j=S[j].before)
           {    Size[S[j].ed]--;
               if (Size[S[j].ed]==1&&flag[S[j].ed]!=2) 
                 for (k=fox[S[j].ed];k;k=s[k].before)
                   if (flag[s[k].ed]==1) {  flag[s[k].ed]=0; st.erase(s[k].ed); }
           }
      }
  }
    printf("%d\n",sum);  
 //   for (;;);  
   return 0;
}