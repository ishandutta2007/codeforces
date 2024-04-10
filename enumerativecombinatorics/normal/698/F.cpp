#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int b[1100000];
int pr[1100000];
int st[1100000];
int to[1100000];
int val[1100000];
int wk[1100000];
int tk[1100000];
long long fact[1100000];
long long gcd(long long a,long long b){
	while(a){
		b%=a;swap(a,b);
	}
	return b;
}
int pl[110000];
int dec[1100000];
int used[1100000];
vector<int> pp[1100000];
int main(){
	int a;scanf("%d",&a);
	fact[0]=1;
	for(int i=1;i<1100000;i++)fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<a;i++){
		scanf("%d",b+i);
	}
	pr[0]=pr[1]=-1;
	for(int i=2;i<1100000;i++){
		if(pr[i]==-1)continue;
		pr[i]=1;
		for(int j=i+i;j<1100000;j+=i)pr[j]=-1;
	}
	st[1]++;
	for(int i=2;i<=a;i++){
		if(pr[i]==1){
			st[a/i]++;
			for(int j=i;j<=a;j+=i)pp[j].push_back(i);
		}
	}
	int ind=0;
	for(int i=2;i<1100000;i++){
		if(pr[i]==1)pl[ind++]=i;
	}
	long long ret=1;
	if(pr[b[0]]==1||b[0]==1){
		used[b[0]]=1;
		dec[1]++;
	}
	for(int i=1;i<=a;i++){
		if(pr[i]==1){
			int now=0;
			for(int j=i;j<=a;j+=i){
				if(!b[j-1])continue;
				now=gcd(now,b[j-1]);
			}
			if(now!=0){
				bool ok=false;
				int ss=-1;
				for(int j=0;j<pp[now].size();j++){
					if(a/pp[now][j]==a/i){
						ss=pp[now][j];
						ok=true;break;
					}
				}
				if(!ok&&a/i==1&&now==1){
					ss=now;
					ok=true;
				}
			//	printf("%d: %d %d\n",i,now,ss);
				if(used[ss]||!ok){

					printf("0\n");return 0;
				}
				used[ss]=1;
				dec[a/i]++;
			}
		}
	}
	for(int i=1;i<=a;i++)ret=ret*fact[st[i]-dec[i]]%mod;
	for(int i=1;i<=a;i++)val[i]=1;
	for(int i=2;i<=a;i++){
		if(pr[i]==1){
			for(int j=i;j<=a;j+=i)val[j]*=i;
		}
	}
	for(int i=1;i<=a;i++)wk[val[i]]++;
	for(int i=0;i<a;i++){
		if(b[i])tk[val[b[i]]]++;
	}
	for(int i=1;i<=a;i++)ret=ret*fact[wk[i]-tk[i]]%mod;
	printf("%I64d\n",ret);
}