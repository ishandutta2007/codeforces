#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
//#define INF 0x7fffffff
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define N 300005
using namespace std;
typedef long long LL;
int cnt[26];
LL fra[1000005];
LL rev[1000005];
int mod=1e9+7;
LL f_pow(int a,int b){
	LL res=1,temp=a;
	while(b){
		if(b&1)res=res*temp%mod;
		temp=temp*temp%mod;
		b>>=1;
	}
	return res;
}
LL cal(string a){
	int tot=a.size();
	LL res=0;
	int temp[26];
	for(int i=0;i<26;i++)
	temp[i]=cnt[i];
	//cout<<a<<endl;
	for(int i=0;i<a.size();i++){
		LL add=fra[tot-1];
		for(int j=0;j<26;j++){
			add*=rev[cnt[j]];
			add%=mod;
		}
		for(int j=0;j<a[i]-'a';j++){
			if(cnt[j]==0)
			continue;
			add*=fra[cnt[j]];
			add%=mod;
			add*=rev[cnt[j]-1];
			add%=mod;
			res+=add;
			add*=fra[cnt[j]-1];
			add%=mod;
			add*=rev[cnt[j]];
			add%=mod;
		}
		cnt[a[i]-'a']--;
	//	printf("%d\n",res);
		tot--;
		if(cnt[a[i]-'a']<0)
		break;	
	} 
	for(int i=0;i<26;i++)
	cnt[i]=temp[i];
	return res;
} 
int main(){
	fra[0]=1;
	for(int i=1;i<=1000000;i++){
		fra[i]=fra[i-1]*i%mod;
	}
	rev[1000000]=f_pow(fra[1000000],mod-2);
	for(int i=1000000;i>0;i--)
	rev[i-1]=rev[i]*i%mod;
	string a,b;
	cin>>a>>b;
	MEM(cnt);
	for(int i=0;i<a.size();i++){
		cnt[a[i]-'a']++;
	} 
	printf("%I64d\n",((cal(b)-cal(a)-1)%mod+mod)%mod);
}