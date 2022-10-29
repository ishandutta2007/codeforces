#include<cstdio>
#include<algorithm>
int num[31];
int i,j,m,n,p,k,flag,K;
char c;
int main()
{ scanf("%d\n",&k);
  for (c=getchar();c!='\n';c=getchar()) num[c-'a']++;
  for (i=0;i<26;i++)
   if (num[i])
if (num[i]%k!=0){ flag=1;break; }
  if (flag) printf("-1\n");
  else {  
          for (i=1;i<=k;i++)
            for (j=0;j<26;j++)
              for (K=1;K<=num[j]/k;K++)
                printf("%c",j+'a');
}
}