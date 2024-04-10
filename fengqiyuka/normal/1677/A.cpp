#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5010;
int a[N],qz1[N],qz2[N],b[N];

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		ll Ans=0;
		for(int i=0;i<=n+1;i++) qz1[i]=qz2[i]=b[i]=0;
		
		for(int i=n;i>=1;i--){
			int Sum=0;
			for(int j=n;j>i;j--){
				if(a[i]<a[j]) Ans=Ans+Sum;
				Sum+=b[j];
			}
			for(int j=i+1;j<=n;j++)
				if(a[i]>a[j]) b[j]++;
//			printf("%d\n",Ans);
		}
		
		for(int i=1;i<=n;i++){
			int Sum=0;
			for(int j=1;j<i;j++)
				if(a[j]<a[i]) Sum++;
			qz1[i]=Sum;
		}
		for(int i=n;i>=1;i--){
			int Sum=0;
			for(int j=n;j>i;j--)
				if(a[j]<a[i]) Sum++;
			qz2[i]=Sum;
		}
//		for(int i=1;i<=n;i++) qz1[i]+=qz1[i-1];
		for(int i=n;i>=1;i--) qz2[i]+=qz2[i+1];
		
		for(int i=1;i<=n;i++) Ans=Ans-(ll)qz1[i]*qz2[i];
		printf("%lld\n",Ans);
	}
	
	return 0;
}