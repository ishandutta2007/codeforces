#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,len[N];
char s[N];
string ans[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=n,ok=0;i>=1;--i){
		static char st[N];
		static char pre[N];
		static int top;
		if(ok&&s[i]==st[top]&&(st[top-1]<s[i]||(s[i]==st[top-1]&&pre[top-1]<s[i])))--top,ok=0;
		else{
			st[++top]=s[i];
			if(st[top]==st[top-1])pre[top]=pre[top-1];
			else pre[top]=st[top-1];
			ok=1;
		}
		if(top<=10){
			for(int j=top;j>=1;--j)ans[i]+=st[j];
		}
		else{
			for(int j=top;j>=top-4;--j)ans[i]+=st[j];
			ans[i]+="...";
			for(int j=2;j>=1;--j)ans[i]+=st[j];
		}
		len[i]=top;
	}
	for(int i=1;i<=n;++i){
		cout<<len[i]<<" "<<ans[i]<<endl;
	}
	return 0;
}