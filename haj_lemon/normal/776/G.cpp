#include<bits/stdc++.h>
using namespace std;
int q,na,nb,a[20],b[20],f[20],nf,x;
long long sum,dp[20][4][4];
string l,r;
bool pan1(int x,int y){if (y/4+1==x)return false;return true;}
bool pan2(int x,int y){if ((y&(1<<x))!=0) return true;return false;}
long long que(){
	long long ansn=0;
	for (int ma=0;ma<=15;ma++){
		if (ma/4+1>nf)continue;
		memset(dp,0,sizeof(dp));
		dp[nf+1][0][0]=1;
		for (int i=nf+1;i>1;i--){
			for (int ne=0;ne<=ma;ne++){
				if (pan1(i-1,ma)||pan2(ma%4,ne)){
					dp[i-1][(ne==ma)][1]+=dp[i][0][1];
					dp[i-1][1][1]+=dp[i][1][1];
					if (ne<=f[i-1]){
						dp[i-1][(ne==ma)][(ne<f[i-1])]+=dp[i][0][0];
						dp[i-1][1][(ne<f[i-1])]+=dp[i][1][0];
					}
				}
			}
		}
//		for (int i=1;i<=nf;i++)cout<<ma<<' '<<i<<' '<<dp[i][0][0]<<' '<<dp[i][0][1]<<' '<<dp[i][1][0]<<' '<<dp[i][1][1]<<endl;
		ansn+=dp[1][1][0]+dp[1][1][1];
	}
	return ansn;
}
int main(){
	scanf("%d",&q);
	while (q--){
		cin>>l>>r;
		na=l.length();nb=r.length();
		for (int i=0;i<na;i++)if (l[i]>='a'&&l[i]<='f')a[i+1]=l[i]-'a'+10;else a[i+1]=l[i]-'0';
		for (int i=0;i<nb;i++)if (r[i]>='a'&&r[i]<='f')b[i+1]=r[i]-'a'+10;else b[i+1]=r[i]-'0';
		for (int i=1;i<=nb;i++)f[nb-i+1]=b[i];nf=nb;
		sum=que();
		if (na!=1){
			for (int i=na;i>=1;i--)if(a[i]!=0){x=i;break;}
			a[x]--;for (int i=x+1;i<=na;i++)a[i]=15;
			for (int i=1;i<=na;i++)f[na-i+1]=a[i];nf=na;
			sum-=que();
		}
		cout<<sum<<endl;
	}
	return 0;
}