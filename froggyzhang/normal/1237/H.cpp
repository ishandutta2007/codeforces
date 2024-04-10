#include<bits/stdc++.h>
using namespace std;
#define N 4004
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,cnta[4],cntb[4],a[N],b[N];
char _a[N],_b[N];
void Solve(){
	scanf("%s",_a+1);
	scanf("%s",_b+1);
	n=strlen(_a+1);
	for(int i=1;i<=n;++i)a[i]=_a[i]-'0';
	for(int i=1;i<=n;++i)b[i]=_b[i]-'0';
	memset(cnta,0,sizeof(cnta)),memset(cntb,0,sizeof(cntb));
	for(int i=1;i<=n;i+=2){
		++cnta[a[i]<<1|a[i+1]],++cntb[b[i]<<1|b[i+1]];
	}
	if(cnta[0]!=cntb[0]||cnta[3]!=cntb[3]){
		puts("-1");return;
	}
	int H=(cnta[1]+cnta[2])/2;
	vector<int> ans;
	auto Rev = [&](int p) -> void{
		reverse(a+1,a+p+1);
		ans.push_back(p);		
	};
	if(cnta[1]^H){
		for(int i=1;i<=n;i+=2){
			int t=a[i]<<1|a[i+1];
			if(t==1)--cnta[1],++cnta[2];
			else if(t==2)++cnta[1],--cnta[2];
			if(cnta[1]==H){
				Rev(i+1);break;
			}
		}
	}	
	int flag=0;
	if(cntb[1]^H){
		for(int i=1;i<=n;i+=2){
			int t=b[i]<<1|b[i+1];
			if(t==1)--cntb[1],++cntb[2];
			else if(t==2)++cntb[1],--cntb[2];
			if(cntb[1]==H){
				reverse(b+1,b+i+2);
				flag=i+1;break;
			}	
		}	
	}
	for(int i=1;i<=n-2;i+=2){
		int t=b[i]<<1|b[i+1];
		for(int j=i;j<=n;j+=2){
			if(t==(a[j]<<1|a[j+1])){
				if(j>1)Rev(j-1);
				Rev(j+1);
				break;
			}	
		}
	}
	if(n>2)Rev(n-2);
	if(flag)Rev(flag);
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%d ",x);
	printf("\n");
}
int main(){
	int T=read();
	while(T--)Solve();
	return 0;
}