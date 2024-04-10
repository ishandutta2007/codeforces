#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=sqrt(1e7)+1;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int prime[505],cnt;bool vis[5005];
int n,k,x,f[10000005],d[100005],t1,t2,t3;
struct node{int a[505],cnt;}num[100005];
void add(int id,int deep,int sum,int opt){
	if(deep==num[id].cnt+1){
		f[sum]+=opt;return;
	}
	add(id,deep+1,sum,opt);
	add(id,deep+1,sum*num[id].a[deep],opt);
}
int ask(int id,int deep,int sum,int opt){
	if(deep==num[id].cnt+1)return opt*f[sum];
	return ask(id,deep+1,sum,opt)+ask(id,deep+1,sum*num[id].a[deep],-opt);
}
bool GCD(int x,int y){
	for(int i=1,j=1;i<=num[x].cnt;++i){
		while(j<num[y].cnt&&num[y].a[j]<num[x].a[i])++j;
		if(num[x].a[i]==num[y].a[j])return 1;
	}
	return 0;
}
void solvet(int id){
	t1=id;
	for(int i=1;i<=n;++i){
		if(!GCD(id,i)){
			if(!t2)t2=i;
			else if(!t3)t3=i;
		}
	}
}
int check(int n){
	for(int i=1;i<=n;++i){
		if(i==t1||i==t2||i==t3)continue;
		add(i,1,1,1);
	}
	int tmp=0;
	for(int i=1;i<=n;++i){
		if(i==t1||i==t2||i==t3)continue;
		d[i]=ask(i,1,1,1);if(d[i])++tmp;
	}
	return tmp;
}
int main(){
	for(int i=2;i<=N;++i){
		if(!vis[i]){prime[++cnt]=i;}
		for(int j=1;j<=cnt;++j){
			if(i*prime[j]>N)break;
			vis[i*prime[j]]=1;
			if(!(i%prime[j]))break;
		}
	}
	n=read();k=read();n=(k<<1);
	for(int i=1;i<=n;++i){
		x=read();
		for(int j=1;prime[j]*prime[j]<=x;++j){
			if(!(x%prime[j])){
				num[i].a[++num[i].cnt]=prime[j];
				while(!(x%prime[j]))x/=prime[j];
			}
		}
		if(x>1)num[i].a[++num[i].cnt]=x;add(i,1,1,1);
	}
	for(int i=1;i<=n;++i){
		d[i]=ask(i,1,1,1);
		if(d[i]>1&&!t1)solvet(i);
	}
	for(int i=1;i<=n;++i)add(i,1,1,-1);
	if(!t1){
		for(int i=1;i<=n&&k;++i){
			if(ask(i,1,1,1)==0){
				cout<<i<<" ";--k;add(i,1,1,1);
			}
		}
	}
	else{
		if(check(n)<k-3){
			for(int i=1;i<=n&&k;++i){
				if(d[i]==0){cout<<i<<" ";--k;}
			}
		}
		else{
			int l=k-3,r=n,mid;
			while(l<=r){
				mid=l+r>>1;
				if(check(mid)>=k-3)r=mid-1;
				else l=mid+1;
			}
			int ans=r+1,tmp=check(ans);
			if(tmp>=k){
				for(int i=1;i<ans;++i){
					if(i==t1||i==t2||i==t3)continue;
					if(tmp>k&&d[i]==1&&!GCD(i,ans)){
						--tmp;continue;
					}
					if(d[i])cout<<i<<" ";
				}
				if(d[ans])cout<<ans;
			}
			else{
				for(int i=1;i<ans;++i){
					if(i==t1||i==t2||i==t3)continue;
					if(tmp>k-2&&d[i]==1&&!GCD(i,ans)){
						--tmp;--d[ans];continue;
					}
					if(d[i])cout<<i<<" ";
				}
				if(!d[ans]&&ans)--tmp;
				if(d[ans])cout<<ans<<" ";
				cout<<t1<<" "<<t2<<" ";if(tmp==k-3)cout<<t3;
			}
		}
	}
	return 0;
}