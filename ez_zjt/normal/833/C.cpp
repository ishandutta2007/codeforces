#include <cstdio>
#include <cstring>
#define LL long long

LL L,R;
int a[30],b[30],c[30],len;
int cnt[20],cnt2[20];
int ans=0;

void pre_gao(){
	LL l=L,r=R;
	while(l || r){
		a[++len]=l%10;
		b[len]=r%10;
		l/=10; r/=10;
	}
}

bool check1(int i){
	cnt2[a[i]]--;
	int now=i-1;
	for(int j=9;j>=0;j--)
		for(int k=0;k<cnt2[j];k++)
			c[now--]=j;
	now=i-1;
	while(now){
		if(c[now]>a[now]) return 1;
		if(c[now]<a[now]){
			cnt2[a[i]]++;
			return 0;
		}
		now--;
	}
	return 1;
}

bool check2(int i){
	cnt2[b[i]]--;
	int now=i-1;
	for(int j=0;j<=9;j++)
		for(int k=0;k<cnt2[j];k++)
			c[now--]=j;
	now=i-1;
	while(now){
		if(c[now]<b[now]) return 1;
		if(c[now]>b[now]){
			cnt2[b[i]]++;
			return 0;
		}
		now--;
	}
	return 1;
}

bool check(){
	for(int i=0;i<=9;i++) cnt2[i]=cnt[i];
	for(int i=len;i>=1;i--){
		if(a[i]==b[i]){
			if(!cnt2[a[i]]) return 0;
			cnt2[a[i]]--;
		}else{
			for(int j=a[i]+1;j<b[i];j++)
				if(cnt2[j]) return 1;
			if(cnt2[a[i]] && check1(i)) return 1;
			if(cnt2[b[i]] && check2(i)) return 1;
			return 0;
		}
	}
	return 1;
}

void dfs(int x,int tot){
	if(!x){
		cnt[0]=tot;
		if(check()) 
			ans++;
		return;
	}
	for(int i=0;i<=tot;i++){
		cnt[x]=i;
		dfs(x-1,tot-i);
	}
}

int main(){
#ifdef DEBUG
	freopen("C.in","r",stdin);
#endif
	scanf("%lld%lld",&L,&R);
	pre_gao();
	dfs(9,len);
	printf("%d\n",ans);
}