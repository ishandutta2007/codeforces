#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int vst[1000005],n,s[1000005];
void MakePrime(){
	for(int i=2;i<=1000000;i++){
		s[i]=s[i-1]+(!vst[i]);
		if(vst[i])continue;
		for(ll j=1ll*i*i;j<=1000000;j+=i)vst[j]=1;
	}
}
int main(){
	MakePrime();
	int t;
	scanf("%d",&t);
	while(t--){
		int x;
		scanf("%d",&x);
		printf("%d\n",s[x]-s[(int)sqrt(x)]+1);
	}
	return 0;
}