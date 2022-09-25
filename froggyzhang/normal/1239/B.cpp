#include<bits/stdc++.h>
using namespace std;
#define N 300030
typedef long long ll;
typedef unsigned long long ull;
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
int n,a[N],c[N],mn;
char s[N];
int check(int x,int y){
	static int _a[N],c[N];
	memcpy(_a,a,sizeof(a));
	swap(_a[x],_a[y]);
	for(int i=1;i<=n;++i)c[i]=c[i-1]+_a[i];
	int mn=*min_element(c+1,c+n+1),cnt=0;
	for(int i=1;i<=n;++i)cnt+=c[i]==mn;
	return cnt;
}
int main(){
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;++i){
		if(s[i]=='(')a[i]=1;
		else a[i]=-1;
		c[i]=c[i-1]+a[i];
	}
	if(c[n]){
		return !printf("0\n1 1\n");
	}
	for(int i=1;i<=n;++i){
		mn=min(mn,c[i]);
	}
	int L1=n+1,R1=0,cnt1=0;
	for(int i=1;i<=n;++i){
		if(mn==c[i])L1=min(L1,i),R1=max(R1,i);
	}
	for(int i=1;i<=n;++i){
		cnt1+=mn==c[i];
	}
	if(R1<n)++R1;
	int cnt2=check(L1,R1);
	int L5=n+1,R5=0;
	for(int i=1;i<=n;++i){
		if(c[i]<=mn+1)L5=min(L5,i),R5=max(R5,i);
	}
	if(R5<n)++R5;
	int cnt5=check(L5,R5);
	pair<int,int> t3,t4;
	int cnt3=-1,cnt4=-1;
	for(int i=1,j=-1;i<=n;++i){
		if(c[i]>=mn+2&&!~j)j=i;
		else if(c[i]<mn+2&&~j){
			int tmp=0;
			for(int k=j;k<i;++k){
				if(c[k]==mn+2)++tmp;
			}
			if(tmp+cnt1>cnt3){
				t3=make_pair(j,i);
				cnt3=tmp+cnt1;
			}
			j=-1;	
		}
	}
	for(int i=1,j=-1;i<=n;++i){
		if(c[i]>=mn+1&&!~j)j=i;
		else if(c[i]<mn+1&&~j){
			int tmp=0;
			for(int k=j;k<i;++k){
				if(c[k]==mn+1)++tmp;
			}
			if(tmp>cnt4){
				t4=make_pair(j,i);
				cnt4=tmp;
			}
			j=-1;	
		}
	}
	pair<int,int> ans(1,1);
	int mx=cnt1;
	if(cnt2>mx){
		mx=cnt2;
		ans=make_pair(L1,R1);
	}
	if(cnt3>mx){
		mx=cnt3;
		ans=t3;
	}
	if(cnt4>mx){
		mx=cnt4;
		ans=t4;
	}
	if(cnt5>mx){
		mx=cnt5;
		ans=make_pair(L5,R5);
	}
	printf("%d\n%d %d\n",mx,ans.first,ans.second);
	return 0;
}