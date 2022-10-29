#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int m,n,p,k;
int a[10001];
map<int,int>mp;
inline bool cmp(int a,int b) { return a>b; }
int main()
{ scanf("%d%d",&n,&k);
  for (int i=0;i<n;i++) scanf("%d",&a[i]);sort(a,a+n,cmp);
   for(int i=1;i<=n;i++){
        for(int j=i-1;j<n;j++,k--){
            if(k==0) {
                return 0;}
            printf("%d %d",i,a[j]);
            for(int x=0;x<i-1;x++)
             printf(" %d",a[x]);
   printf("\n");
}
}
}