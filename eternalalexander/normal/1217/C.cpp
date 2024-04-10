#include <bits/stdc++.h>
#define maxn 200005
int R[maxn],n,t;
char s[maxn];

int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%s",s+1);
		n=std::strlen(s+1);
		R[n+1]=-1;int ans=0;
		for (int i=n;i>=1;i--){
			if (s[i]=='1')R[i]=i;
			else R[i]=R[i+1];
		}for (int l=1;l<=n;++l){
			if (R[l]==-1)break;
			int now=0;
			for (int r=R[l];r<=n;++r){
				now=(now<<1)+s[r]-'0';
				if (now==(r-l+1))ans++;
				if (now>n)break;
			}
		}printf("%d\n",ans);
	}
	return 0;
}