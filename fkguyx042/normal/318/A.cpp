#include<cstdio>
long long i,j,m,n,p,k;
int main()
 { scanf("%I64d%I64d",&n,&k);
   if (n&1)
    { if (k<=(n+1)/2)  printf("%I64d\n",2*k-1);
      else printf("%I64d\n",2*(k-(n+1)/2));
}
else { if (k<=n/2)  printf("%I64d\n",2*k-1);
      else printf("%I64d\n",2*(k-n/2));
      }
return 0;
}