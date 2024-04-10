#include<bits/stdc++.h>
using namespace std;
char s[100010];
long long f[4];
int main() {
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	int n,a;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a);
		if(s[i]=='h') {
			f[1]=min(f[1],f[0]);
			f[0]+=a;
		}
		else if(s[i]=='a') {
			f[2]=min(f[2],f[1]);
			f[1]+=a;
		}
		else if(s[i]=='r') {
			f[3]=min(f[3],f[2]);
			f[2]+=a;
		}
		else if(s[i]=='d') {
			f[3]+=a;
		}
	}
	printf("%lld\n",min(min(f[0],f[1]),min(f[2],f[3])));
	return 0;
}