#include<bits/stdc++.h>
using namespace std;
long long hp,n,d[200001],sum,tmphp,modmin,ans,minminu=0x3f3f3f3f;
int main(){
//	scanf("%d %d",&hp,&n);
	cin>>hp>>n;
	tmphp=hp;
	for(long long i=1;i<=n;i++) {
		cin>>d[i];
		tmphp+=d[i];
		if(tmphp<=0){
//			printf("%d\n",i);
			cout<<i;
			return 0;
		}
		sum+=d[i];
		minminu=min(minminu,sum);
//		cout<<sum;
	}
	tmphp=hp;
	if(sum>=0){
		printf("-1\n");
		return 0;
	}
	//while(tmphp+minminu>0){
//		cout<<tmphp<<" "; 
//		tmphp+=sum;
//		ans++;
//	}
//	sum=minminu-sum;
	tmphp+=minminu;
	ans=tmphp/(-sum);
	hp+=ans*sum;
//	cout<<hp<<endl;
//	cout<<hp<<endl;
	ans*=n;
//	cout<<ans;
	for(long long i=0;;i++){
		if(hp<=0){
			cout<<ans+i;
			return 0;
		}
		hp+=d[(i)%n+1];
	}
	return 0;
}