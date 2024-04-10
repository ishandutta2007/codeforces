#include<bits/stdc++.h>
using namespace std;
long long work(long long n){
	int ans=~0u>>2;
	if(n<=150){
		for(int i=0;i<=10;++i)
			for(int j=0;j<=10;++j)
				for(int k=0;k<=10;++k)
					if(6*i+8*j+10*k>=n)ans=min(ans,15*i+20*j+25*k);
		return ans;
	}
	long long tmp=0;
	long long ret=0;
	for(int i=141;i<=199;++i){
		if((n-i)%10!=0)continue;
		n-=i;
		tmp=i;
		ret+=(n/10)*25;
		break;
	}
	for(int i=0;i<=10;++i)
		for(int j=0;j<=10;++j)
			for(int k=0;k<=10;++k)
				if(6*i+8*j+10*k>=tmp)ans=min(ans,15*i+20*j+25*k);
	return ans+ret;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		long long n;
		cin>>n;
		cout<<work(n)<<"\n";
	}
}