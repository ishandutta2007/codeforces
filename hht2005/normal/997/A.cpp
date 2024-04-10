#include<bits/stdc++.h>
using namespace std;
char s[300010];
int main() {
	int n,x,y,cnt=0;
	scanf("%d%d%d%s",&n,&x,&y,s+1);
	for(int i=2;i<=n;i++)
		if(s[i]=='1'&&s[i-1]=='0')cnt++;
	if(s[n]=='0')cnt++;
	if(cnt==0)cout<<0<<endl;
	else if(x<y)cout<<1ll*(cnt-1)*x+y<<endl;
	else cout<<1ll*y*cnt<<endl;
	return 0;
}