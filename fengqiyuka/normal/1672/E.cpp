#include<bits/stdc++.h>
using namespace std;

int Query(int mid){
	printf("? %d\n",mid);
	fflush(stdout);
	int x;scanf("%d",&x);
	return x;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int l=1,r=5e6,ans,x;
	while(l<=r){
		int mid=(l+r)>>1;
		if(Query(mid)==1) ans=mid,r=mid-1;
		else l=mid+1;
	}
	
	int Ans=ans;
	for(int i=2;i<=n;i++){
		if(Query(ans/i)==i){
			if(Ans>ans/i*i) Ans=ans/i*i;
		}
	}
	
	printf("! %d\n",Ans);
	fflush(stdout);
	
	return 0;
}