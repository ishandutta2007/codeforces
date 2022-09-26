#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define N 200020
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,m,k,tot,dp[N][260],cnt[260],d[10];
struct Opt{
	int type,pos,id;
	bool operator <(const Opt b)const{
		return pos==b.pos?type<b.type:pos<b.pos;
	}
}a[N]; 
int main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=n;++i){
		int l=read(),r=read();
		a[++tot]={1,l,i};
		a[++tot]={-1,r+1,i};
	}
	sort(a+1,a+tot+1);
	for(int i=1;i<(1<<k);++i){
		cnt[i]=cnt[i>>1]+(i&1);
	}
	int st=0;
	for(int i=1;i<=tot;++i){
		int u=-1;
		if(a[i].type==1){
			for(int j=1;j<=k;++j){
				if(!d[j]){
					d[j]=a[i].id;
					u=j;
					break;
				}
			}
			for(int j=st;;j=(j-1)&st){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+(cnt[j]&1)*(a[i].pos-a[i-1].pos));
				dp[i][j|(1<<(u-1))]=max(dp[i][j|(1<<(u-1))],dp[i-1][j]+(cnt[j]&1)*(a[i].pos-a[i-1].pos-1)+((cnt[j]+1)&1));
				if(!j)break;
			}
			st|=(1<<(u-1));
		}
		else{
			for(int j=1;j<=k;++j){
				if(d[j]==a[i].id){
					d[j]=0;
					u=j;
					break;
				}
			}
			st^=(1<<(u-1));
			for(int j=st;;j=(j-1)&st){
				dp[i][j]=max(dp[i][j],dp[i-1][j]+(cnt[j]&1)*(a[i].pos-a[i-1].pos));
				dp[i][j]=max(dp[i][j],dp[i-1][j|(1<<(u-1))]+((cnt[j]+1)&1)*(a[i].pos-a[i-1].pos-1)+(cnt[j]&1));
				if(!j)break;
			}
		}
	}
	printf("%d\n",dp[tot][0]);
	return 0;
}