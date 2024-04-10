#include<cstdio>
#include<algorithm>
#include<cstring>

#define N 1005
char c[N];
int size[N],fa[N],F[N],n,i,id[N],sum[N],j,k,ans[N];
using namespace std;
int get(int x) { return fa[x]==x?x:fa[x]=get(fa[x]); }
inline bool cmp(int a,int b) { return sum[a]>sum[b]; }
inline bool Cmp(int a,int b) { return size[a]>size[b]; }
int prime(int x)
{
      int i;
      for (i=2;i*i<=x;++i) if (x%i==0) return 0;
      return 1;
}
int main()
{
 scanf("%s",c);
 n=strlen(c);
 for (i=0;i<strlen(c);++i) sum[c[i]-'a']++;
 for (i=0;i<26;++i) id[i]=i;
 sort(id,id+26,cmp);
 for (i=1;i<=n;++i) fa[i]=i;
 for (i=2;i<=n;++i)
    if (prime(i))
       for (j=2;j<=n/i;++j) 
           if (get(i)!=get(i*j))
          fa[get(i)]=get(i*j); 
 for (i=1;i<=n;++i) size[get(i)]++;        
 for (i=1;i<=n;++i) if (fa[get(i)]==i) F[++F[0]]=i;
 sort(F+1,F+F[0]+1,Cmp);
 for (i=1;i<=F[0];++i) 
 {
     if (size[F[i]]>sum[id[0]]) { printf("NO\n"); exit(0); }
     for (j=25;j>=0;--j) if (size[F[i]]<=sum[id[j]]) break;
     for (k=1;k<=n;++k) if (get(k)==F[i]) ans[k]=id[j],sum[id[j]]--;
     sort(id,id+26,cmp);
  }
  printf("YES\n");
  for (i=1;i<=n;++i) printf("%c",ans[i]+'a');
  //for (;;);
}