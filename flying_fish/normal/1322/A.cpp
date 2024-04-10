#include<bits/stdc++.h>
using namespace std;const int N=1e6+7;
int n,m,i,j,tot,ans,num,flag;char s[N];
int main(){
	for(scanf("%d%s",&n,s+1),i=1;i<=n;)if(s[i]=='(')++tot,++i;
	else{
		if(tot)tot--,++i;else{
			for(j=i+1,num=-1;j<=n&&num<0;++j)
				if(s[j]==')')num--;else num++;
			if(j==n+1&&num<0)flag=1;ans+=(j-i);i=j;
		}
	}printf("%d\n",flag||tot!=0?-1:ans);
}