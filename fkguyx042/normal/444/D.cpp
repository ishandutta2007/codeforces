#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
using namespace std;
int i,j,m,n,p,k,ans,len,Len,sum,Sum,LenA,LenB;
char s[50001],A[11],B[11];
set<int>st[1000001];
map<long long,int>mp;
int main()
{  scanf("%s",&s); Len=strlen(s);
   for (len=1;len<=4;len++)
    for (j=0;j<Len-len+1;j++)
	  {   sum=0;
	     for (k=j;k<=j+len-1;k++)
	        sum=sum*27+s[k]-'a'+1;
	     st[sum].insert(j);
      } 
  for (scanf("%d",&m);m--;)
  { scanf("%s",&A); scanf("%s",&B); LenA=strlen(A); LenB=strlen(B);
     for (i=0,len=strlen(A),sum=0;i<len;i++) sum=sum*27+A[i]-'a'+1;
	 for (i=0,len=strlen(B),Sum=0;i<len;i++) Sum=Sum*27+B[i]-'a'+1;
	 if (!st[sum].size()||!st[Sum].size()) { printf("-1\n"); }
	 else {  if (mp[(long long)(1ll*min(sum,Sum)*1000000+max(sum,Sum))])
	         printf("%d\n",mp[(long long)(1ll*min(sum,Sum)*1000000+max(sum,Sum))]);
	         else {  if (st[sum].size()>st[Sum].size()) swap(sum,Sum),swap(LenA,LenB); ans=(int)1e9;
	                 set<int>::iterator it,it2;
	                 for (it=st[sum].end();it!=st[sum].begin();)
	                 {  --it;
	                    it2=st[Sum].lower_bound(*it);
	                    if (it2!=st[Sum].end())
	                      ans=min(ans,max(*it2+LenB,*it+LenA)-*it);
	                    if (it2!=st[Sum].begin())
						{ --it2; ans=min(ans,max(*it2+LenB,*it+LenA)-*it2); }
			}
			printf("%d\n",ans);
		   mp[(long long)(1ll*min(sum,Sum)*1000000+max(sum,Sum))]=ans;
	}
}
}
}