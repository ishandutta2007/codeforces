#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[5001],n,i;
struct Node{int x,y;}A[3000001];
inline bool cmp(Node a,Node b) {return a.x<b.x;}
int main()
{freopen("input.txt","r",stdin);
 freopen("output.txt","w",stdout);
  scanf("%d",&n); n*=2;
 for (i=1;i<=n;i++) scanf("%d",&A[i].x),A[i].y=i,a[A[i].x]++;
 for (i=1;i<=5000;i++) if (a[i]&1) { printf("-1\n"); return 0;}
 sort(A+1,A+n+1,cmp);
 for (i=1;i<=n;i+=2) printf("%d %d\n",A[i].y,A[i+1].y);
}