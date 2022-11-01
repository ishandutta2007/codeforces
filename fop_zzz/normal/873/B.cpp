#include<bits/stdc++.h>
using namespace std;
char s[200000];
int flag[300000],f[300000],l,ans,sum;
int main(){
	ios::sync_with_stdio(false);
	cin>>l>>s;flag[150000]=true;sum=150000;ans=0;
	for (int i=1;i<=l;i++){
		if (s[i-1]-'0')sum++;else sum--;
		if (flag[sum])ans=max(ans,i-f[sum]);
			else flag[sum]=true,f[sum]=i;
	}cout<<ans<<endl;
}