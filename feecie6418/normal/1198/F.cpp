#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005],ans[100005];
int main(){
	srand(time(0));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=i;
	while(1.0*clock()/CLOCKS_PER_SEC<=0.45){
		random_shuffle(b+1,b+n+1);
		int t1=a[b[1]],t2=a[b[2]];
		ans[b[1]]=1,ans[b[2]]=2;
		for(int i=3;i<=n;i++){
			if(__gcd(t1,a[b[i]])<t1)t1=__gcd(t1,a[b[i]]),ans[b[i]]=1;
			else t2=__gcd(t2,a[b[i]]),ans[b[i]]=2;
		}
		if(t1==1&&t2==1){
			puts("YES");
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);
			return 0;
		}
	}
	puts("NO");
}