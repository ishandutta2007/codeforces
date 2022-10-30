#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){a=a<b?b:a;}
const int N=600005,inf=2e9;
int t[N],l[N],r[N],c[N],d[N],b[N],ans[N],_[N],mx,lim,T[N],P,QAQ[N];
std::vector<int> v1[N],v2[N];
struct qry{int k,id;}Q[N];
std::map<int,int> mp[N];std::set<int> S;int MX[N<<2],M;
void build(int n){for(M=1;M<=n+2;M<<=1);}
void upd(int x,int C){for(x+=M;x;x>>=1)chmax(MX[x],C);}
int ask(int s,int t){
	if(s>t)return -2e9;
	int ans=0;
	for(s+=M-1,t+=M+1;s^t^1;s>>=1,t>>=1){
		if(~s&1)chmax(ans,MX[s^1]);
		if(t&1)chmax(ans,MX[t^1]);
	}
	return ans;
}
void add(int x,int y,int C){
	if(c[x]+c[y]<=lim){
		int tmp=(mp[x][y]+=C)+_[x]+_[y];
		chmax(mx,tmp),chmax(QAQ[x],tmp),chmax(QAQ[y],tmp);
	}
}
int main(){
	int n;read(n,lim);
	int pos=0;for(int i=1;i<=n;++i)read(l[i],r[i],c[i]),t[++pos]=l[i],t[++pos]=r[i],T[++P]=c[i];
	T[++P]=0,std::sort(T+1,T+P+1),P=std::unique(T+1,T+P+1)-T-1;
	t[++pos]=0,t[++pos]=inf,std::sort(t+1,t+pos+1),pos=std::unique(t+1,t+pos+1)-t-1;
	for(int i=1;i<=n;++i)l[i]=std::lower_bound(t+1,t+pos+1,l[i])-t,r[i]=std::lower_bound(t+1,t+pos+1,r[i])-t,v1[l[i]].pb(i),v2[r[i]].pb(i),++d[r[i]],--d[l[i]];
	for(int i=pos;i>=1;--i)d[i]+=d[i+1];
	for(int i=1;i<=pos;++i)b[i]=b[i-1]+(d[i]==1?t[i]-t[i-1]:0);
	int q;read(q);for(int i=1;i<=q;++i)read(Q[i].k),Q[i].id=i;std::sort(Q+1,Q+q+1,[&](const qry &a,const qry &b){return a.k<b.k;});
	int sum=0;build(P);
	std::fill(QAQ,QAQ+N,-2e9);
	for(int i=1,cur=1;i<=pos;++i){
		if(d[i]==0)sum+=t[i]-t[i-1];
		else if(d[i]==1){
			int x=*S.begin();_[x]+=t[i]-t[i-1];
			int o=ask(1,std::upper_bound(T+1,T+P+1,lim-c[x])-T-1);
			chmax(mx,_[x]+o),chmax(mx,QAQ[x]+=t[i]-t[i-1]);
		}
		else if(d[i]==2)add(*S.begin(),*++S.begin(),t[i]-t[i-1]);
		for(auto it:v2[i])S.erase(it),upd(std::lower_bound(T+1,T+P+1,c[it])-T,_[it]);
		for(auto it:v1[i])S.insert(it);
		while(cur<=q&&sum+mx>=Q[cur].k)ans[Q[cur].id]=t[i]-(sum+mx-Q[cur].k),++cur;
	}
	for(int i=1;i<=q;++i)printf("%d\n",ans[i]);
	return 0;
}