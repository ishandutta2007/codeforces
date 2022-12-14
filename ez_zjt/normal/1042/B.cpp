#include <bits/stdc++.h>
#define MAXN 1010
using namespace std;

int n;
int v[10];

int main(){
#ifdef DEBUG
	freopen("B.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0;i<8;i++) v[i]=1000000;
	for(int i=1;i<=n;i++){
		int c,s=0;
		scanf("%d",&c);
		char str[10];
		scanf("%s",str);
		for(int i=0;i<strlen(str);i++){
			if(str[i]=='A') s|=1;
			if(str[i]=='B') s|=2;
			if(str[i]=='C') s|=4;
		}
		v[s]=min(v[s],c);
	}
	v[0]=0;
	int ans=1000000;
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			for(int k=0;k<8;k++)
				if((i|j|k)==7)
					ans=min(ans,v[i]+v[j]+v[k]);
	if(ans>=500000) puts("-1");
	else printf("%d\n",ans);
}