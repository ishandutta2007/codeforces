#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
char str[1000005];
int top=0,now=1,mintop=0,ans=0,n;
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++){
		if(str[i]=='(')top++;
		else top--;
		mintop=min(mintop,top);
		if(!top){
			if(mintop<0)ans+=i-now+1;
			now=i+1;
			mintop=0;
		}
	}
	if(top)return puts("-1"),0;
	printf("%d\n",ans);
}