#include<bits/stdc++.h>
using namespace std;
inline int rd(){int x=0,c=0,f=1;for(;c<'0'||c>'9';c=getchar())f=c!='-';
for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';return f?x:-x;}
const int N=100011;
char s[N];
int t[N];
int main(){
	int k=rd();
	scanf("%s",s+1);
	int n=strlen(s+1);
	sort(s+1,s+n+1);
	int tmp=0,tot=0;
	for(int i=1;i<=n;i++){
		tmp+=s[i]-'0';
		if(s[i]!='9'){
			tot++;
			t[tot]=t[tot-1]+'9'-s[i];
		}
	}
	if(k-tmp<=0)puts("0");
	else printf("%d\n",lower_bound(t+1,t+tot+1,k-tmp)-t);
}