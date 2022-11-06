#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
const int N=10005;
struct myhash{
	static const int mod=20000003;
	int fir[mod],nxt[mod/5],pb[mod/5],tp[mod/5],tot;
	void ins(int x,int y){
		int w=x%mod;
		tp[++tot]=y,pb[tot]=x;
		nxt[tot]=fir[w],fir[w]=tot;
	}
	int que(int x){
		int w=x%mod;
		for(int i=fir[w];i;i=nxt[i])
			if(pb[i]==x)return tp[i];
		return -1;
	}
}sg;
struct node{
	int a,b;
	bool operator<(const node&t)const{
		return a<t.a;
	}
} p[N];
int Sg(int x){
	int tmp=sg.que(x);
	if(~tmp)return tmp;
	int i; bool vis[33];
	memset(vis,0,sizeof(vis));
	for (i=1; x>>i; i++) vis[Sg(x>>i|x&(1<<i)-1)]=1;
	for (i=0; vis[i]; i++); sg.ins(x,i); return i;
}
int n,tot;
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	rep(i,1,n){
		int x,q;
		cin>>x;
		for(int i=2;i*i<=x&&x^1;i++)if(x%i==0){
			int a=i,b=0;
			while(x%i==0)b++,x/=i;
			p[++tot]=(node){a,b};
		}
		if(x^1)p[++tot]=(node){x,1};
	}
	sort(p+1,p+tot+1);
	int ans=0;
	n=tot;
	//cout<<Sg(3)<<endl;
	//cout<<tot<<endl; 
	for(int i=1,j;i<=n;i=j){
		int now=1<<p[i].b;
		for(j=i+1;j<=n&&p[j].a==p[i].a;j++){
			now|=1<<p[j].b;
		}
		ans^=Sg(now|1);
		//cout<<now<<" "<<ans<<endl;
	}
	puts((ans>0)?"Mojtaba":"Arpa");
}