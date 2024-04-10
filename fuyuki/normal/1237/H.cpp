#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re register
#define I inline int
#define V inline void
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=5e3+1;
char ch[N];
int n,a[N],b[N],sum;
int ans[N],out[N],tp;
V clean(){
	FOR(i,1,n)a[i]=b[i]=0;
}
V input(){
	scanf("%s",ch+1),n=strlen(ch+1)>>1;
	FOR(i,1,n)a[i]=ch[i*2-1]-'0'|ch[i*2]-'0'<<1;
	scanf("%s",ch+1);
	FOR(i,1,n)b[i]=ch[i*2-1]-'0'|ch[i*2]-'0'<<1;
}
V rev(rnt x){
	if(!x)return;
	reverse(a+1,a+x+1),ans[++tp]=x*2;
	FOR(i,1,x)if(a[i]==1||a[i]==2)a[i]^=3;
}
V work(){
	int cnt[4]={0,0,0,0},op=0,ed=0;
	tp=sum=0;
	FOR(i,1,n)if(b[i]==1||b[i]==2)b[i]^=3;
	FOR(i,1,n)cnt[a[i]]++,cnt[b[i]]--;
	if(cnt[0]||cnt[3])return void(cout<<"-1\n");
	rnt x=!!cnt[1];
	if(x){
		FOR(i,1,n){
			cnt[a[i]]--,cnt[a[i]^3]++;
			if(cnt[1]==0){
				op=i,x=0;
				break;
			}
		}
	}
	if(x){
		FOR(i,1,n)cnt[a[i]]++,cnt[a[i]^3]--;
		FOR(i,1,n){
			cnt[b[i]]++,cnt[3^b[i]]--;
			if(cnt[1]==0){
				ed=i;
				break;
			}
		}
		reverse(b+1,b+ed+1);
		FOR(i,1,ed)if(b[i]==1||b[i]==2)b[i]^=3;
	}
	rev(op);
	ROF(i,n,1){
			FOR(j,n-i+1,n)
				if(b[i]==a[j]){
					rev(j-1);
					rev(j);
					break;
				}
		}
	rev(ed);
	FOR(i,1,tp)
		if(ans[i]==out[sum])sum--;
		else out[++sum]=ans[i];
	cout<<sum<<'\n';
	FOR(i,1,sum)cout<<out[i]<<" \n"[i==sum];
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
	int T;scanf("%d",&T);
	while(T--){
		clean();
		input();
		work();
	}
	return 0;
}