#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=1e6+100,mod=1e9+7;
char s[N];int f[N][2],g[N][2],p[N],d[N],nex[N];bool bk[N];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	memset(p,0,sizeof(p));
	for(int i=len;i>=1;i--){
		if(s[i]=='1') p[i]=0;
		else p[i]=p[i+1]+1;
	}
	d[0]=0;
	for(int i=len;i>=1;i--){
		while(d[0]&&p[d[d[0]]]<=p[i]) d[0]--;
		if(d[0]==0) nex[i]=-1e9;
		else nex[i]=d[d[0]];
		d[++d[0]]=i;
	}
	for(int i=2;i<=len;i++){
		if(s[i]=='0'&&s[i-1]=='0') nex[i]=nex[i-1]+1;
	}
	int Sum=0;
	for(int i=len;i>=1;i--){
		if(s[i]=='1') break;
		Sum++;
	}
	int Sum2=0;
	for(int i=1;i<=len;i++){
		if(s[i]=='1') Sum2=0;
		else Sum2++;
		if(Sum2<Sum) bk[i]=true;
	}
	int st=0,ed=len+1;
	for(int i=len;i>=1;i--){
		if(s[i]=='1') break;
		bk[i]=false;ed=i;
	}
	for(int i=1;i<=len;i++){
		if(s[i]=='1') break;
		st=i;
	}
	int id1=-1,id2=-1;
	for(int i=len;i>=0;i--){
		g[i][0]=id1,g[i][1]=id2;
		if(s[i]=='0') id1=i;
		if(s[i]=='1') id2=i;
	}
	memset(f,0,sizeof(f));f[0][0]=1;
	for(int i=0;i<=len;i++){
		if(s[i+1]=='0'||(i>st&&nex[i]>0)){
			if(s[i+1]=='0') f[i+1][0]=(f[i+1][0]+f[i][0])%mod;
			else f[nex[i]+1][0]=(f[nex[i]+1][0]+f[i][0])%mod;
		}
		if(g[i][0]!=-1) f[g[i][0]][0]=(f[g[i][0]][0]+f[i][1])%mod;
		if(g[i][1]!=-1) f[g[i][1]][1]=((ll)f[g[i][1]][1]+f[i][0]+f[i][1])%mod;
	}
	int Ans=0;
	for(int i=0;i<len;i++){
		Ans=((ll)Ans+f[i][0]+f[i][1])%mod;
		if(i>st&&bk[i]) Ans=(Ans+f[i][0])%mod;
		if(s[len]=='0'&&i<ed-1) Ans=(Ans+f[i][1])%mod;
	}
	printf("%d\n",Ans);
	return 0;
}