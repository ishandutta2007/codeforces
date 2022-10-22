#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
int n;
#define Maxn 10010
#define cout cerr
#define FR first
#define SE second
int a[Maxn];

piii ans[Maxn*3];int cnt;
void F(int i,int j,int x){
	a[i]-=x*i;a[j]+=x*i;
	ans[++cnt]=piii(pii(i,j),x);
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;rd(T);
	while(T--){
		rd(n);int sum=0;cnt=0;
		for(int i=1;i<=n;++i){
			rd(a[i]);
			sum+=a[i];
		}
		if(sum%n!=0)puts("-1");
		else{
			for(int i=2;i<=n;++i){
				if(a[i]%i!=0){
					int t=(a[i]+i-1)/i;t*=i;t-=a[i];
					F(1,i,t);
				}
				F(i,1,a[i]/i);
			}
			for(int i=2;i<=n;++i){
				F(1,i,sum/n);
			}
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;++i)printf("%d %d %d\n",ans[i].FR.FR,ans[i].FR.SE,ans[i].SE);
		}
	}
	return 0;
}