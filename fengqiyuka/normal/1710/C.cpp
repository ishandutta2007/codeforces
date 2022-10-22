#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100,mod=998244353;
char s[N];int f[N][8][8];

int main()
{
	scanf("%s",s+1);
	
	int len=strlen(s+1);
	
	memset(f,0,sizeof(f));
	f[0][7][0]=1;
	for(int i=1;i<=len;i++)
		for(int j=0;j<=7;j++)
			for(int k=0;k<=7;k++)
				if(f[i-1][j][k])
					for(int l=0;l<=7;l++){
						int t1=(l&1),t2=((l>>1)&1),t3=((l>>2)&1);
						int t4=(j&1),t5=((j>>1)&1),t6=((j>>2)&1);
						if(s[i]=='1'){
							if(t1==0) t4=0;if(t2==0) t5=0;if(t3==0) t6=0;
						}
						else{
							if(t1==1&&t4==1) continue;
							if(t2==1&&t5==1) continue;
							if(t3==1&&t6==1) continue;
						}
						int now=(t4|(t5<<1)|(t6<<2)),tt=k;
						if(t1!=t2&&t1!=t3) tt|=1;
						if(t2!=t1&&t2!=t3) tt|=2;
						if(t3!=t1&&t3!=t2) tt|=4;
						f[i][now][tt]=(f[i][now][tt]+f[i-1][j][k])%mod;
					}
	
	int Ans=0;
	for(int i=0;i<=7;i++)
		Ans=(Ans+f[len][i][7])%mod;
		
	printf("%d\n",Ans);
	return 0;
}