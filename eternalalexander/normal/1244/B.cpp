#include <bits/stdc++.h>

char s[100000];

void solve(){
	int n;
	scanf("%d",&n);scanf("%s",s+1);
	int leftmost=0,rightmost=0;
	for(int i=1;i<=n;++i){
		if (s[i]=='1')rightmost=i;
		if (!leftmost&&s[i]=='1')leftmost=i;
	}if (!leftmost)printf("%d\n",n);
	else printf("%d\n",std::max((n-leftmost+1)*2,rightmost*2));
}

int main(){
	int t;scanf("%d",&t);while (t--)solve();
	return 0;
}