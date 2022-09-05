#include<cstdio>  
#include<cstdlib>  
#include<algorithm>  
#include<ctime>  
using namespace std;  
  
inline char nc(){  
  static char buf[100000],*p1=buf,*p2=buf;  
  if (p1==p2) { p2=(p1=buf)+fread(buf,1,100000,stdin); if (p1==p2) return EOF; }  
  return *p1++;  
}  
  
inline void read(int &x){  
  char c=nc(),b=1;  
  for (;!(c>='0' && c<='9');c=nc()) if (c=='-') b=-1;  
  for (x=0;c>='0' && c<='9';x=x*10+c-'0',c=nc()); x*=b;  
}  
  
const int N=20005;  
  
struct vv{  
  int x,y,idx,p;  
}v[N];  
int n,part[N];  
  
vv IDX;  
  
int rank[N];  
  
bool cmp(int a,int b) {  
  return (v[a].x-IDX.x)*(v[b].y-IDX.y)-(v[b].x-IDX.x)*(v[a].y-IDX.y)<0;  
}  
  
void match(int l,int r){  
  if (l+1==r){  
    part[v[rank[l]].idx]=v[rank[r]].idx; part[v[rank[r]].idx]=v[rank[l]].idx;  
    return;  
  }  
  
  for (int i=l+1;i<=r;i++) if (v[rank[i]].y<v[rank[l]].y) swap(v[rank[l]],v[rank[i]]);  
  IDX=v[rank[l]];  
  sort(rank+l+1,rank+r+1,cmp);  
  
  int t=0,last=l+1;  
  for (int i=l+1;i<r;i++){  
    t+=v[rank[i]].p;  
    if (t==0){  
      match(last,i);  
      last=i+1;  
    }  
  }  
  part[v[rank[l]].idx]=v[rank[last]].idx; part[v[rank[last]].idx]=v[rank[l]].idx;  
  if (last+1<r) match(last+1,r);  
}  
  
int main(){  
  read(n);  
  for (int i=1;i<=2*n;i++) rank[i]=i;  
  for (int i=1;i<=n;i++)  
    read(v[i].x),read(v[i].y),v[i].idx=i,v[i].p=1;  
  for (int i=n+1;i<=2*n;i++)  
    read(v[i].x),read(v[i].y),v[i].idx=i,v[i].p=-1;  
  match(1,2*n);   
  for (int i=1;i<=n;i++)  
    printf("%d\n",part[i]-n);  
  return 0;  
}