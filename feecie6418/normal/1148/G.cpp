#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,K,a[100005],F,G,H,s[10000005],b[100005],is1[100005],is2[100005],c1,c2;
vector<int> v[100005],w[100005];
void ad(int x,int k){
	for(int i:w[x])s[i]+=k;
}
ll qs(int x){
	ll ret=0;
	for(int i=0;i<w[x].size();i++)ret+=((__builtin_popcount(i)&1)?-1:1)*s[w[x][i]];
	return ret;
}
void Solve1(){
	for(int i=1;i<=n;i++)ad(i,-1);
	for(int i=1,j=0;i<=n&&j<K;i++)if(qs(i)==0)printf("%d ",i),j++,ad(i,1);
	exit(0);
}
void FindFGH(int f){
	F=f;
	for(int i=1;i<=n;i++)if(__gcd(a[i],a[f])==1){if(!G)G=i;else H=i;}
}
vector<int> Find(int r){
	vector<int> tmp;
	for(int i=1;i<=r;i++)ad(b[i],1);
	for(int i=1;i<=r;i++)if(qs(b[i])==0)tmp.push_back(b[i]);
	for(int i=1;i<=r;i++)ad(b[i],-1);
	return tmp;
}
int main() {
	scanf("%d%d",&n,&K);
	for(int i=1,t;i<=n;i++){
		scanf("%d",&a[i]),t=a[i];
		for(int j=2;j*j<=t;j++){
			if(t%j)continue;
			while(t%j==0)t/=j;
			v[i].push_back(j);
		}
		if(t>1)v[i].push_back(t);
		for(int p=0;p<(1<<v[i].size());p++){
			int pr=1;
			for(int j=0;j<v[i].size();j++)if(p&(1<<j))pr*=v[i][j];
			w[i].push_back(pr);
		}
		ad(i,1);
	}
	bool flag=0;
	for(int i=1;i<=n;i++){
		int d=qs(i);
		////cerr<<"D:"<<i<<' '<<d<<endl;
		if(d>1&&!flag)FindFGH(i),flag=1;
	}
	//cerr<<"FGH:"<<F<<' '<<G<<' '<<H<<endl;
	if(!flag)Solve1();
	if(K==3)return cout<<F<<' '<<G<<' '<<H<<'\n',0; 
	for(int i=1;i<=n;i++)ad(i,-1);
	for(int i=1;i<=1e7;i++)assert(s[i]==0);
	for(int i=1;i<=n;i++)if(i!=F&&i!=G&&i!=H)b[++b[0]]=i;
	vector<int> tmp=Find(n-3);
	if(tmp.size()>=K){
		for(int i=0;i<K;i++)cout<<tmp[i]<<' ';
		return 0; 
	}
	int l=1,r=n-3,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(mid-Find(mid).size()+3>=K)ans=mid,r=mid-1;
		else l=mid+1;
	}
	//cerr<<ans<<' '<<ans-Find(ans).size()<<endl;
	for(int i=1;i<=ans;i++)ad(b[i],1);
	for(int i=1;i<=ans;i++)if(qs(b[i]))is1[i]=1,c1++;//cerr<<"In1:"<<b[i]<<endl;
	ad(b[ans],-1);
	for(int i=1;i<ans;i++)if(qs(b[i]))is2[i]=1,c2++;//cerr<<"In2:"<<b[i]<<endl;
	//for(int i=1;i<=n;i++)//cerr<<"A:"<<a[i]<<endl;
	if(c2+4==K){
		int cnt=0;
		for(int i=1;i<=ans;i++){
			if(is2[i])cout<<b[i]<<' ';
			else if(i!=ans&&__gcd(a[b[i]],a[b[ans]])==1){
				if(!cnt)cout<<b[i]<<' ',cnt=1;
			}
			else if(i==ans)cout<<b[i]<<' ';
		}
		cout<<F<<' '<<G;
		if(!cnt)cout<<' '<<H;
	}
	else {
		int i1=0,i2=0;
		for(int i=1,cnt=0;i<=ans;i++){
			if(!is1[i])continue;
			if(is2[i])cout<<b[i]<<' ';
			else if(i==ans||__gcd(a[b[i]],a[b[ans]])==1){
				if(cnt<c1+3-K)cnt++;
				else {
					cout<<b[i]<<' ';
					if(i==ans)i1=1;
					if(i!=ans)i2=1;
				}
			}
		}
		assert(i1&&i2);
		cout<<F<<' '<<G<<' '<<H<<'\n';
	}
	return 0;
}