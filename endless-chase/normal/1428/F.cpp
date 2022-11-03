#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,a[555555],len[555555],pos[555555],top,cur,pp;
char s[555555];
long long ans,tt[555555],csum;
long long calc(int l1,int p1,int l2,int p2)
{
	if (!l1 && !p1) return 1ll*(p2-1)*l2;
	pp=p1+(l1-l2);
	return 1ll*(p2-pp)*l2+1ll*(l2+1+l1)*(l1-l2)/2;
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	for (int i=1;i<=n;i++) a[i]=s[i-1]-'0';
	for (int i=1;i<=n;i++)
	{
		if (a[i]==1)
		{
			cur++;
		}
		else 
		{
			if (cur) 
			{
				top++;
				len[top]=cur;
				pos[top]=i-cur;
				tt[top]=calc(len[top-1],pos[top-1],len[top],pos[top]);
				csum+=tt[top];
			}
			cur=0;
		}
		while(top && cur>=len[top])
		{
			csum-=tt[top];
			top--;
		}
		ans+=(csum+calc(len[top],pos[top],cur,i-cur+1)+1ll*cur*(cur+1)/2);
	}
	printf("%lld\n",ans);
	return Accepted;
}