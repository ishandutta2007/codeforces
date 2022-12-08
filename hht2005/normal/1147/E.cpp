#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
char c[N];
int f[N],p[N],s[N],id[N];
int main() {
	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		if(n>=2) {
			printf("Q %d",n/2);
			for(int i=1;i<n;i+=2)
				printf(" %d %d",i,i+1);
			cout<<endl;
			scanf("%s",c+1);
			for(int i=1;i<n;i+=2)
				f[i]=c[i/2+1]-'0';
		}
		if(n>=3) {
			printf("Q %d",(n-1)/2);
			for(int i=2;i<n;i+=2)
				printf(" %d %d",i,i+1);
			cout<<endl;
			scanf("%s",c+1);
			for(int i=2;i<n;i+=2)
				f[i]=c[i/2]-'0';
		}
		int F;
		p[F=1]=1,s[F]=1;
		for(int i=2;i<=n;i++)
			if(!f[i-1])p[++F]=i,s[F]=1;
			else s[F]++,p[F]=i;
		int cnt=0;
		for(int i=1;i+2<=F;i+=4) {
			cnt++;
			if(i+3<=F)cnt++;
		}
		if(cnt>0) {
			printf("Q %d",cnt);
			for(int i=1;i+2<=F;i+=4) {
				printf(" %d %d",p[i],p[i+2]);
				if(i+3<=F)printf(" %d %d",p[i+1],p[i+3]);
			}
			cout<<endl;
			scanf("%s",c+1);
			cnt=0;
			for(int i=1;i+2<=F;i+=4) {
				f[i+2]=c[++cnt]-'0';
				if(i+3<=F)f[i+3]=c[++cnt]-'0';
			}
		}
		cnt=0;
		for(int i=3;i+2<=F;i+=4) {
			cnt++;
			if(i+3<=F)cnt++;
		}
		if(cnt>0) {
			printf("Q %d",cnt);
			for(int i=3;i+2<=F;i+=4) {
				printf(" %d %d",p[i],p[i+2]);
				if(i+3<=F)printf(" %d %d",p[i+1],p[i+3]);
			}
			cout<<endl;
			scanf("%s",c+1);
			cnt=0;
			for(int i=3;i+2<=F;i+=4) {
				f[i+2]=c[++cnt]-'0';
				if(i+3<=F)f[i+3]=c[++cnt]-'0';
			}
		}
		int S[4]={0,s[1],0,0};
		if(F>1)S[2]=s[2];
		id[1]=1;
		id[2]=2;
		for(int i=3;i<=F;i++) {
			if(f[i])id[i]=id[i-2];
			else {
				for(int j:{1,2,3})
					if(id[i-1]!=j&&id[i-2]!=j)
						id[i]=j;
			}
			S[id[i]]+=s[i];
		}
		printf("A %d %d %d\n",S[1],S[2],S[3]);
		for(int i=1;i<=F;i++) {
			s[i]+=s[i-1];
			if(id[i]==1) {
				for(int j=s[i-1]+1;j<=s[i];j++)
					printf("%d ",j);
			}
		}
		puts("");
		for(int i=1;i<=F;i++) {
			if(id[i]==2) {
				for(int j=s[i-1]+1;j<=s[i];j++)
					printf("%d ",j);
			}
		}
		puts("");
		for(int i=1;i<=F;i++) {
			if(id[i]==3) {
				for(int j=s[i-1]+1;j<=s[i];j++)
					printf("%d ",j);
			}
		}
		puts("");
		fflush(stdout);
	}
	return 0;
}