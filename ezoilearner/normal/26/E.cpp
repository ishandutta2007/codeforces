#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int sum=0;
int n,W;
#define Maxn 105
#define cout cerr
#define FR first
#define SE second
int num[Maxn]; 
pii seq[Maxn];

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
	rd(n);rd(W);
	for(int i=1;i<=n;++i)rd(num[i]),seq[i]=make_pair(num[i],i),sum+=num[i];
	sort(seq+1,seq+n+1);
	if(W<=0||W>sum){
		puts("No");
		return 0;
	}
	if(W>=seq[1].FR){
		puts("Yes");
		printf("%d ",seq[1].SE);
		int at=sum-W;
		for(int i=2;i<=n;++i){
			while(at&&seq[i].FR){
				at--;
				seq[i].FR--;
				printf("%d %d ",seq[i].SE,seq[i].SE);
			}
		}
		printf("%d ",seq[1].SE);
		seq[1].FR--;
		for(int i=1;i<=n;++i){
			while(seq[i].FR){
				printf("%d %d ",seq[i].SE,seq[i].SE);
				seq[i].FR--;
			}
		}
		return 0;
	}
	if(W==1||n==1){
		puts("No");
		return 0;
	}
	puts("Yes");
	printf("%d %d ",seq[1].SE,seq[2].SE);
	for(int i=3;i<=n;++i){
		while(seq[i].FR){
				printf("%d %d ",seq[i].SE,seq[i].SE);
				seq[i].FR--;
			}
	}
	printf("%d ",seq[1].SE);
	for(int i=seq[1].FR-1;i>=W;--i)printf("%d %d ",seq[1].SE,seq[1].SE);
	printf("%d ",seq[2].SE);
	printf("%d ",seq[1].SE);
	for(int i=seq[2].FR-1;i>=1;--i)printf("%d %d ",seq[2].SE,seq[2].SE);
	printf("%d ",seq[1].SE);
	for(int i=W-2;i>=1;--i)printf("%d %d ",seq[1].SE,seq[1].SE);
	return 0;
}