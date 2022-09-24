#include<bits/stdc++.h>
using namespace std;
int mch[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,K;
		scanf("%d%d",&n,&K);
		for(int i=0;i<n;i++)mch[i]=n-i-1;
		if(n<=4&&K==n-1){
			puts("-1");
			continue;
		}
		if(K==n-1){
			for(int i=1;i<n;i<<=1){
				if(i!=1)mch[i]=n-(i>>1)-1,mch[n-(i>>1)-1]=i;
				else mch[i]=n-1-(n>>1),mch[n-1-(n>>1)]=i;
			}
			for(int i=0;i<n;i++)if(mch[i]<i)cout<<mch[i]<<' '<<i<<'\n';
			continue;
		}
		if(K!=0){
			mch[0]=n-K-1;
			mch[n-K-1]=0;
			mch[K]=n-1;
			mch[n-1]=K;
		}
		for(int i=0;i<n;i++)if(mch[i]<i)cout<<mch[i]<<' '<<i<<'\n';
	}
}