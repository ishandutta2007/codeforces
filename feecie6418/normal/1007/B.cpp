#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s[8],d[100005];
bool Check(int x,int y,int z){
	if((x&1)&&(y&2)&&(z&4))return 1;
	if((x&1)&&(y&4)&&(z&2))return 1;
	if((x&2)&&(y&1)&&(z&4))return 1;
	if((x&2)&&(y&4)&&(z&1))return 1;
	if((x&4)&&(y&1)&&(z&2))return 1;
	if((x&4)&&(y&2)&&(z&1))return 1;
	return 0;
}
int main(){
	for(int i=1;i<=100000;i++)for(int j=i;j<=100000;j+=i)d[j]++;
	int t;
	cin>>t;
	while(t--){
		int A,B,C;
		ll ans=0;
		scanf("%d%d%d",&A,&B,&C);
		s[7]=d[__gcd(__gcd(A,B),C)];
		s[6]=d[__gcd(C,B)];
		s[5]=d[__gcd(A,C)];
		s[4]=d[C];
		s[3]=d[__gcd(A,B)];
		s[2]=d[B];
		s[1]=d[A];
		for(int i=7;i>=1;i--)for(int j=i+1;j<=7;j++)if((i&j)==i)s[i]-=s[j];
		for(int i=1;i<=7;i++){
			if(Check(i,i,i)){
				ans+=s[i]*(s[i]+1)*(s[i]+2)/6;
			}
			for(int j=i+1;j<=7;j++){
				if(Check(i,i,j)){
					ans+=s[i]*(s[i]+1)/2*s[j];
				}
				if(Check(j,j,i)){
					ans+=s[j]*(s[j]+1)/2*s[i];
				}
				for(int k=j+1;k<=7;k++){
					if(Check(i,j,k)){
						ans+=s[i]*s[j]*s[k];
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}