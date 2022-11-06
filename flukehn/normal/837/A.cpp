#include<bits/stdc++.h>
using namespace std;
inline int rd(){int x=0,c=0,f=1;for(;c<'0'||c>'9';c=getchar())f=c!='-';
for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';return f?x:-x;}
const int N=1e6+5;
char s[N];
int main(){
	int n,ans=0;
	scanf("%d",&n);
	while(scanf("%s",s)==1){
		n=strlen(s);
		int tmp=0;
		for(int i=0;i<n;i++)
			tmp+=(s[i]<='Z'&&s[i]>='A');
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
}