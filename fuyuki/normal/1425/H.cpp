#include<bits/stdc++.h>
using namespace std;
const char ans[2][10]={"Tidak ","Ya "};
int T,A,B,C,D,op[2];
int main(){
	for(scanf("%d",&T);T--;cout<<'\n'){
		scanf("%d%d%d%d",&A,&B,&C,&D);
		if((A||D)&&(B||C))op[0]=op[1]=1;
		else op[0]=A||D,op[1]=B||C;
		if(A+B&1)cout<<ans[op[0]]<<ans[op[1]]<<ans[0]<<ans[0];
		else     cout<<ans[0]<<ans[0]<<ans[op[1]]<<ans[op[0]];
	}
}