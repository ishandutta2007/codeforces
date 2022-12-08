#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],f[N],s[N];
signed main() {
	int T,n,c;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&c);
		for(int i=1;i<=c;i++)f[i]=s[i]=0;
		for(int i=1;i<=n;i++) {
			scanf("%d",a+i);
			f[a[i]]=1;
		}
		for(int i=1;i<=c;i++)
			s[i]=s[i-1]+f[i];
		int FL=1;
		for(int i=1;i<=c&&FL;i++) {
			if(f[i]!=1)continue;
			for(int j=1;i*j<=c&&FL;j++) {
				if(f[j])continue;
				int L=i*j-1,R=min(i*(j+1)-1,c);
				if(s[R]!=s[L])FL=0;
			}
		}
		puts(FL?"YES":"NO");
	}
}