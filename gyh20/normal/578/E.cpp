#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
set<int>S[2];
char s[100002];
int n,ans[100002],a[100002],k;
inline void work(set<int>S0,set<int>S1){
	re int pos=1,num=0;
	set<int>::iterator it;
	while(1){
		if(num==n)break;
		it=S0.lower_bound(pos);
		if(*it==n+1)it=S0.begin();
		else{
			re int x=*it;
			if(*S1.lower_bound(x)==n+1&&*S0.begin()<*S1.begin())it=S0.begin();
		}
		a[++num]=*it,pos=*it,S0.erase(it);
		if(num==n)break;
		it=S1.lower_bound(pos);
		if(*it==n+1)it=S1.begin();
		else{
			re int x=*it;
			if(*S0.lower_bound(x)==n+1&&*S1.begin()<*S0.begin())it=S1.begin();
		}
			a[++num]=*it,pos=*it,S1.erase(it);
	}
	re int s=0;
	for(re int i=2;i<=n;++i)s+=(a[i]<a[i-1]);
	if(s<k){
		k=s;
		for(re int i=1;i<=n;++i)ans[i]=a[i];
	}
}
int main(){
	scanf("%s",s+1),n=strlen(s+1),k=n+1;
	for(re int i=1;i<=n;++i)if(s[i]=='L')S[0].insert(i);else S[1].insert(i);
	S[0].insert(n+1),S[1].insert(n+1);
	if(S[0].size()>=S[1].size())work(S[0],S[1]);
	if(S[1].size()>=S[0].size())work(S[1],S[0]);
	printf("%d\n",k);
	for(re int i=1;i<=n;++i)printf("%d ",ans[i]);
}