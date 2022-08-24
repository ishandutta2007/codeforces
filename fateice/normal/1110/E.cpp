#include<bits/stdc++.h>
#define L long long
#define vi vector<int>
#define pb push_back
using namespace std;
int n,a[100010],b[100010];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	  scanf("%d",&b[i]);
	if(a[1]!=b[1])
	  printf("No");
	else
	  {
       for(i=1;i<n;i++)
         a[i]=a[i+1]-a[i];
       for(i=1;i<n;i++)
         b[i]=b[i+1]-b[i];
       sort(a+1,a+n);
       sort(b+1,b+n);
       for(i=1;i<n;i++)
         if(a[i]!=b[i])
           break;
       if(i<n)
         printf("No");
       else
         printf("Yes");
      }
	return 0;
}