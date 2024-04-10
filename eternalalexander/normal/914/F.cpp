#include <bits/stdc++.h>
char s[110005],y[120005],b[10];
std::bitset<110005>ans,vis[30],all1;
int a,q,opt;
int main() {
	scanf("%s%d",s+1,&q);int n=std::strlen(s+1);
	for (int i=1;i<=n;++i) vis[s[i]-'a'][i]=1;
	for (int i=0;i<n;++i) all1[i]=1;
	while (q--){
		scanf("%d",&opt);
		if (opt==1) {
			scanf("%d%s",&a,b+1);
			vis[s[a]-'a'][a]=0;vis[b[1]-'a'][a]=1;
			s[a]=b[1];
		} if (opt==2) {int l,r;
			scanf("%d%d%s",&l,&r,y+1);
			ans=all1; int len=std::strlen(y+1);
			if (r-l+1<len) {printf("0\n");continue;}
			for (int i=1;i<=len;++i) {
				ans&=(vis[y[i]-'a']>>i);
			}printf("%d\n",(ans>>(l-1)).count()-(ans>>(r-len+1)).count());
		}
	}
	return 0;
}