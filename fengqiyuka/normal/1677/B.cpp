#include<bits/stdc++.h>
using namespace std;

const int N=1e6+100;
char s[N];int qz[N],qz2[N];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=0;i<=len;i++) qz[i]=qz2[i]=0;
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				int t=(j-1)*m+i;
				if(s[t]=='1') {qz[t]++;break;}
			}
		}
		int Sum=0;
		for(int i=0;i<m;i++){
			if(s[i]=='1') Sum++;
			if(Sum>0) qz2[i]++;
		}
		for(int i=1;i<=len-m+1;i++){
			if(s[i-1]=='1') Sum--;
			if(s[i+m-1]=='1') Sum++;
			if(Sum>0){
				qz2[i+m-1]++;
			}
		}
		for(int i=1;i<=len;i++){
			qz[i]+=qz[i-1];
			if(i>=m) qz2[i]+=qz2[i-m];
		}
		for(int i=1;i<=len;i++) printf("%d ",qz[i]+qz2[i]);
		printf("\n");
	}
	
	return 0;
}